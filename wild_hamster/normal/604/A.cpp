#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef int ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1000500], b[1000500], pb[4000500], back[4000050], t[4000050];
string s;
set<ll> f;
set<ll>::iterator itr;
map<ll,ll> compr;
vector <ll> tmp;
vector<pair<ll,ll> > gg;
int main()
{
    //freopen("input.txt","r",stdin);
    ll m[5],w[5],x,y;
    for (i = 0; i < 5; i++)
        cin >> m[i];
    for (i = 0; i < 5; i++)
        cin >> w[i];
    cin >> x >> y;
    ll ans = x*100 - 50*y;
    for (i = 0; i < 5; i++)
    {
        ans += max(3*(i+1)*50, (i+1)*500 - (i+1)*2*m[i] - 50*w[i]);
    }
    cout << ans << endl;
    return 0;
}