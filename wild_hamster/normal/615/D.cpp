#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1000500], b[1000500], dp[4000500], inv[4000050], t[4000050], pre[400050];
string s;
vector <pair<ll,ll> > f;
ll binpow(ll x, ll y, ll md)
{
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2, md);
    tmp = (tmp*tmp)%(md);
    if (y%2 == 0)
        return tmp;
    return (x*tmp)%(md);
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    //n = 200000;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d",&x);
        //x = 2;
        a[x]++;
    }
    ll ans = 1;
    ll val = 1;
    for (i = 1; i <= 200005; i++)
        if (a[i] != 0)
            t[a[i]]++;
    for (i = 1; i <= 200005; i++)
        if (t[i] != 0)
            f.push_back(mp(i,t[i]));
    ll sz = f.size();
    //for (i = 0; i < sz; i++)
    //  cout << f[i].first << " " << f[i].second << endl;
    for (i = 0; i < sz; i++)
    {
        x = f[i].first;
        pre[x] = 1;
        for (j = 0; j < sz; j++)
            if (f[j].first != x)
                pre[x] = (pre[x] * binpow(f[j].first+1, f[j].second, MOD-1)) %(MOD-1);
            else
            {
                pre[x] = (pre[x] * binpow(f[j].first+1, f[j].second-1, MOD-1)) %(MOD-1);
                //pre[x] = (pre[x] * f[j].first)%MOD;
            }
        //cout << pre[x] << endl;
    }
    for (i = 1; i <= 200005; i++)
    {
        if (a[i] != 0)
        {
            ans = (ans*binpow(binpow(i,pre[a[i]], MOD), a[i]*(a[i]+1)/2, MOD))%MOD;
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}