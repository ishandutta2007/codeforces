#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
char ch[1200];
int is[1200];
int set[1200],nu[1200],ct[1200];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y)
{
    set[find(x)]=y;
}
int ans[1200];
int i,j,n,p;
int main()
{
    while(~scanf("%s",ch))
    {
        n=strlen(ch);
        memset(is,0,sizeof(is));
        for(i=2;i<=n;i++)
        {
            bool can=true;
            for(j=2;j<i;j++)
            if(i%j==0){can=false;break;}
            if(can)is[i]=1;
        }
        for(i=1;i<=n;i++)set[i]=i;
        for(i=2;i<=n;i++)
        if(is[i])
        {           
            for(j=i*2;j<=n;j+=i)
            {
                if(find(i)!=find(j))
                U(i,j);
            }
        }
        for(i=0;i<=n;i++)nu[i]=0;
        for(i=1;i<=n;i++)nu[find(i)]++;
        int id=0,ma;
        for(i=1;i<=n;i++)if(nu[i]>1)id=i;
        memset(ct,0,sizeof(ct));
        for(i=0;i<n;i++)ct[ch[i]-'a']++;
        ma=0;
        for(i=0;i<26;i++)
        ma=max(ma,ct[i]);
        if(id!=0&&ma<nu[id])
        {puts("NO");continue;}
        puts("YES");
        int id1;
        for(i=0;i<26;i++)
        if(ct[i]==ma)
        {id1=i;break;}
        memset(ans,-1,sizeof(ans));
        for(i=1;i<=n;i++)
        if(find(i)==id)
        ans[i]=id1;
        ct[id1]-=nu[id];
        p=0;
        for(i=1;i<=n;i++)
        {
            if(ans[i]!=-1)continue;
            while(ct[p]==0)p++;
            ans[i]=p;ct[p]--;
        }
        for(i=1;i<=n;i++)printf("%c",'a'+ans[i]);puts("");
    }
}