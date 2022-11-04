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
const int maxn=5005;
const ll Mod=1000000007;


ll n,k;

int check(ll x)
{
    ll l=x,r=x;
    if(x%2==0)
        r++;
    ll ans=0;
    while(1)
    {
        ans+=min(n,r)-l+1;
        l<<=1;
        r<<=1;
        r++;
        if(l>n)
            break;
    }
    return ans>=k;
}


int main()
{
    sync;
    cin>>n>>k;
    ll l=1,r=(n+1)/2;
    ll ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid*2-1))
        {
            l=mid+1;
            
            ans=2*mid-1;
        }
        else
            r=mid-1;
    }
    
    l=1;
    r=n/2;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid*2))
        {
            l=mid+1;
            ans=max(2*mid,ans);
        }
        else
            r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}