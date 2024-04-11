#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef long long ll;
typedef vector<int> vec;
typedef pair<ll,ll> pii;

vector<pii> v;
int main()
{
    ll n,b;cin>>n>>b;
    ll bx = b;
    for(ll i=2;i*i<=b;++i)
    {
        if(bx%i==0)
        {
            ll cnt = 0;
            while(bx%i==0)
            {
                cnt++,bx/=i;
                v.pb({i,cnt});
            }
        }
    }
    if(bx>1) v.pb({bx,1});
    ll ans = 1e18;
    for(auto pr:v)
    {
        ll p=pr.first;
        ll t=pr.second;
        ll l = (ll)(log10(n)/log10(p)+0.1);
        ll cnt = 0;
        for(ll i=1;i<=l;++i)
        {
            cnt += n / p;
            p = p * pr.first;
            if(p>n||p<0) break;
        }
        ans = min(ans, cnt/t);
    }
    cout << ans << endl;
}