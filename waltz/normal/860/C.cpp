#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int k[100005];
char c[15];
string name[100005];
int a[100005];
int ids[100005];
bool is_number[100005];
vector<int> unused0;
vector<int> unused1;
bool checks(int x)
{
    if (name[x][0]=='0') return false;
    int i;
    for (i=0;i<name[x].length();i++)
    {
        if (name[x][i]<'0') return false;
        if (name[x][i]>'9') return false;
    }
    return true;
}
int get_number(int x)
{
    int i;
    int sum=0;
    for (i=0;i<name[x].length();i++)
    {
        sum*=10;
        sum+=name[x][i]-'0';
    }
    return sum;
}
int m;
int n;
int next_one;
string anti_number(int x)
{
    static int que[15];
    int now=0;
    for (;x!=0;now++)
    {
        que[now]=x%10;
        x/=10;
    }
    string ans="";
    for (;;)
    {
        now--;
        if (now==-1) return ans;
        ans+=(char)(que[now]+'0');
    }
}
void dfs(int x)
{
    if (x<=m)
    {
        if (unused1.size()==0)
        {
            for (;;)
            {
                if (k[ids[next_one]]==1)
                {
                    dfs(next_one);
                    break;
                }
                next_one++;
            }
        }
        vector<int>::iterator t=unused1.end();
        t--;
        printf("move %d %d\n",x,(*t));
        ids[*t]=ids[x];
        ids[x]=-1;
        name[ids[*t]]=anti_number(x);
        unused1.pop_back();
        unused0.push_back(x);
    }
    else
    {
        vector<int>::iterator t=unused0.end();
        t--;
        printf("move %d %d\n",x,(*t));
        ids[*t]=ids[x];
        ids[x]=-1;
        name[ids[*t]]=anti_number(x);
        unused0.pop_back();
        unused1.push_back(x);
    }
}
int main()
{
    scanf("%d",&n);
    int i;
    m=0;
    for (i=1;i<=n;i++)
    {
        scanf("%s%d",c,&k[i]);
        name[i]=c;
        m+=k[i];
        ids[i]=-1;
    }
    int ans=0;
    bool all_numbers=true;
    for (i=1;i<=n;i++)
    {
        if (checks(i))
        {
            int j=get_number(i);
            if (j<=n)
            {
                ids[j]=i;
                is_number[i]=true;
            }
        }
        if (!is_number[i])
        {
            ans++;
            all_numbers=false;
        }
        else
        {
            if ((get_number(i)<=m)&&(k[i]==1)) continue;
            if ((get_number(i)>m)&&(k[i]==0)) continue;
            ans++;
        }
    }
    if (ans==0)
    {
        printf("%d\n",ans);
        return 0;
    }
    if (all_numbers)
    {
        ans++;
        printf("%d\n",ans);
        int i;
        for (i=1;i<=n;i++)
        {
            if ((get_number(i)<=m)&&(k[i]==1)) continue;
            if ((get_number(i)>m)&&(k[i]==0)) continue;
            printf("move %d orz\n",get_number(i));
            ids[get_number(i)]=-1;
            name[i]="orz";
            is_number[i]=false;
            break;
        }
    }
    else
    {
        printf("%d\n",ans);
    }
    for (i=1;i<=n;i++)
    {
        if (ids[i]==-1)
        {
            if (i<=m)
            {
                unused0.push_back(i);
            }
            else
            {
                unused1.push_back(i);
            }
        }
    }
    next_one=m+1;
    for (i=1;i<=n;i++)
    {
        if (ids[i]==-1) continue;
        //printf("%d %d %s\n",i,ids[i],name[ids[i]].c_str());
        if ((k[ids[i]]==1)&&(i<=m)) continue;
        if ((k[ids[i]]==0)&&(i>m)) continue;
        dfs(i);
    }
    for (i=1;i<=n;i++)
    {
        if (is_number[i]) continue;
        vector<int>::iterator ii;
        int val;
        if (k[i]==1)
        {
            ii=unused0.end();
            ii--;
            val=(*ii);
            unused0.pop_back();
        }
        else
        {
            ii=unused1.end();
            ii--;
            val=(*ii);
            unused1.pop_back();
        }
        printf("move %s %d\n",name[i].c_str(),val);
    }
    return 0;
}