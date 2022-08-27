#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m;
    ll t;
    //string s;
    //ll ans = 0;
    scanf("%lld %lld %lld\n", &n, &m,&t);
    ll s;
    char c;
    vpi reord;
    vll ord(n);
    ll total_speed = 0;
    vll outpos;
    forn(i,0,n) {
        scanf("%lld %c\n", &s, &c);
        reord.pb(mp(s%m,i));
        if(c=='R') {
            total_speed++;
            outpos.pb((s + t)%m);
        }
        else {
            total_speed--;
            outpos.pb((s+m-(t%m))%m);
        }
    }
    sort(all(reord));
    sort(all(outpos));
    ll totshift = 0;
    forn(i,0,n) {
        totshift+=outpos[i]+2*m - reord[i].first;
    }
    //totshift = totshift % (n*m);
    //ll actualshift = ((total_speed * (t%(m*n))) %(m*n) + m*n)%(m*n);
    ll tmod = t%(m*n);
    ll A = total_speed/10000;
    ll B= total_speed%10000;
    ll actualshift = (((A*tmod)%(m*n) * (10000))%(m*n) + (B*tmod)%(m*n))%(m*n);
    ll diff= ((totshift-actualshift)/m)%n;
    vi ans(n);
    forn(i,0,n) {
        ans[reord[i].second] = outpos[(i+n-diff)%n];
        if(ans[reord[i].second]==0)         ans[reord[i].second]=m;
    }
    forn(i,0,n) printf("%d ", ans[i]);
    // cout<<ans;
}