#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;

set<int> s;
map<int,int> mp;

const int maxn=100010;
bool f[maxn];
int a[maxn];
int ans,n,k,x,cnt,y;
    long long t;

void close()
{
exit(0);
}

void work()
{
}

void init()
{
    scanf("%d %d",&n,&k);
     ans=0;
     for (int i=1;i<=n;i++)
     {
         scanf("%d",&a[i]);
     }
     sort(a+1,a+n+1);
     for (int i=1;i<=n;i++)
     {
         s.insert(a[i]);
         mp[a[i]]=i;
     }
    set<int>::iterator it,pos;

    for (it=s.begin();it!=s.end();it++)
    {
    t=1;
        if (k==1) 
        {
            ans++;
            continue;
        }
        if (f[mp[*it]]) continue;
        t=t*(*it);
        pos=it;
        cnt=0;
        while (pos!=s.end())
        {
            pos=s.find(t);
            if (pos!=s.end())               y=1;
            else break;
            f[mp[t]]=true;
            t*=k;
            cnt++;
            if (t>(int)1E9)
                break;
        }
        if (cnt % 2==0)
            cnt/=2;
        else cnt=cnt/2+1;
        ans+=cnt;
    }
    printf("%d\n",ans);
}

int main ()
{
init();
work();
close();
return 0;
}