#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
const ll Mod=1e9+7;

ll sum1[maxn],sum2[maxn],a[maxn],pos[maxn];
ll lowbit(int x)
{
    return x&(-x);
}

void add1(ll x,ll y)
{
    if(x==0)
        return;
    while(x<maxn)
    {
        sum1[x]+=y;
        x+=lowbit(x);
    }
}

ll query1(ll x)
{
    ll ans=0;
    while(x)
    {
        ans+=sum1[x];
        x-=lowbit(x);
    }
    return ans;
}

void add2(ll x,ll y)
{
    if(x==0)
        return;
    while(x<maxn)
    {
        sum2[x]+=y;
        x+=lowbit(x);
    }
}

ll query2(ll x)
{
    ll ans=0;
    while(x)
    {
        ans+=sum2[x];
        x-=lowbit(x);
    }
    return ans;
}



int main()
{
    sync;
    int n;
    while(cin>>n)
    {
        mm(sum1);
        mm(sum2);
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            int p=pos[i];
            add1(p,1);
            add2(p,p);
            ans+=i-query1(p);
            ll pp=ans;
            ll l=1,r=n,tmp;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(query1(mid)*2>i)
                {
                    tmp=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            ll x=query1(tmp);
            pp+=(tmp-x+1+tmp)*x/2-query2(tmp);
            x=i-x;
            pp+=query2(n)-query2(tmp)-((tmp+1+tmp+x)*x/2);
            cout<<pp<<' ';
        }
        cout<<endl;
    }
    return 0;
}