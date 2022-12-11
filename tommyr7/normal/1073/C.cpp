#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n;
pair<int,int> s1[Maxn],s2[Maxn];
int x,y;
char ch[Maxn];
int nowx,nowy;
bool tryit(int len)
{
    for (int i=1;i<=n-len+1;i++)
    {
        int lx=i,rx=i+len-1;
        bool flag=true;
        if (len<abs(x-s1[lx-1].first-s2[rx+1].first)+abs(y-s1[lx-1].second-s2[rx+1].second)) flag=false;
        if (len%2!=(abs(x-s1[lx-1].first-s2[rx+1].first)+abs(y-s1[lx-1].second-s2[rx+1].second))%2) flag=false;
        if (flag) return true;
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",ch+1);
    scanf("%d%d",&x,&y);
    nowx=0,nowy=0;
    for (int i=1;i<=n;i++)
    {
        if (ch[i]=='U') ++nowy;
        if (ch[i]=='D') --nowy;
        if (ch[i]=='L') --nowx;
        if (ch[i]=='R') ++nowx;
    }
    if (abs(x)+abs(y)>n||(abs(x)+abs(y))%2!=n%2)
    {
        printf("%d\n",-1);
        return 0;
    }
    if (nowx==x&&nowy==y)
    {
        printf("%d\n",0);
        return 0;
    }
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    for (int i=1;i<=n;i++)
    {
        s1[i].first=s1[i-1].first;
        s1[i].second=s1[i-1].second;
        if (ch[i]=='U') ++s1[i].second;
        if (ch[i]=='D') --s1[i].second;
        if (ch[i]=='L') --s1[i].first;
        if (ch[i]=='R') ++s1[i].first;
    }
    for (int i=n;i;i--)
    {
        s2[i].first=s2[i+1].first;
        s2[i].second=s2[i+1].second;
        if (ch[i]=='U') ++s2[i].second;
        if (ch[i]=='D') --s2[i].second;
        if (ch[i]=='L') --s2[i].first;
        if (ch[i]=='R') ++s2[i].first;
    }
    int lx=1,rx=n;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (tryit(mid)) rx=mid; else lx=mid;
    }
    if (tryit(lx)) printf("%d\n",lx); else printf("%d\n",rx);
    return 0;
}