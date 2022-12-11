#include <bits/stdc++.h>
using namespace std;
#define Maxn 1000007
int n;
vector<char> s[Maxn];
char a[Maxn];
pair<int,pair<int,int> > cnt[Maxn];
int p[Maxn],q[Maxn],num[Maxn],p1[Maxn],q1[Maxn];
bool flag[Maxn];
bool check(char x)
{
    if (x=='a'||x=='e'||x=='i'||x=='o'||x=='u') return true;
    return false;
}
void print(int x)
{
    int t=(int)s[x].size();
    for (int i=0;i<t;i++)
        printf("%c",s[x][i]);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",a+1);
        int len=strlen(a+1);
        for (int j=1;j<=len;j++)
        {
            s[i].push_back(a[j]);
            if (check(a[j])) 
            {
                ++cnt[i].first;
                cnt[i].second.first=a[j]-'a';
            }
        }
        cnt[i].second.second=i;
    }
    sort(cnt+1,cnt+n+1);
    int now=1,ans=0;
    for (int i=2;i<=n;i++)
        if (now!=i)
        {
            if (cnt[i].first==cnt[now].first&&cnt[i].second.first==cnt[now].second.first)
            {
                ++ans;
                flag[i]=true;
                flag[now]=true;
                p[ans]=cnt[i].second.second;
                q[ans]=cnt[now].second.second;
                now=i+1;
            } else now=i;
        }
    int tot=0;
    for (int i=1;i<=n;i++)
        if (!flag[i]) num[++tot]=i;
    now=1;
    int t=0;
    for (int i=2;i<=tot;i++)
        if (now!=i)
        {
            if (cnt[num[i]].first==cnt[num[now]].first)
            {
                ++t;
                p1[t]=cnt[num[i]].second.second;
                q1[t]=cnt[num[now]].second.second;
                now=i+1;
            } else now=i;
        }
    int res=min(t,ans);
    if (ans>res) res+=(ans-res)/2;
    printf("%d\n",res);
    for (int i=1;i<=t&&i<=ans;i++)
    {
        print(p1[i]);
        printf(" ");
        print(p[i]);
        printf("\n");
        print(q1[i]);
        printf(" ");
        print(q[i]);
        printf("\n");
    }
    for (int i=min(t,ans)+1;i<ans;i+=2)
    {
        print(p[i]);
        printf(" ");
        print(p[i+1]);
        printf("\n");
        print(q[i]);
        printf(" ");
        print(q[i+1]);
        printf("\n");
    }
    return 0;
}