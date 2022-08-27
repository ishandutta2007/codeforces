#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
    int n,m,k;
    ll l;
    string s;
    ll ans = 0;
    scanf("%d %I64d %d", &n,&l,&k);
    vi a(n);
    vpi asort;
    forn(i,0,n) {
        scanf("%d", &a[i]);
        asort.pb(mp(a[i], i));
    }
    sort(all(asort));
    vi less(n);
    deque<int> uniqind;
    for(int i = n-1; i>=0; i--) {
        if ((i==n-1) || (asort[i].first != asort[i+1].first)) {
            less[asort[i].second] = i;
            uniqind.push_front(i);
        }
        else {
            less[asort[i].second] = less[asort[i+1].second];
        }
    }
    uniqind.push_front(-1);
    vector<vll> d(n, vll(k+1, 0));
    forn(i, 0, n) d[i][1] = 1;
    for(int len = 2; len<=k; len++) {
        ll curless = 0;
        for(int ui = 1; ui<uniqind.size(); ui++) {
            int u = uniqind[ui];
            ll num = u - uniqind[ui-1];
            curless += num * d[asort[u].second][len-1];
            curless = curless % mod;
            int ul=u-num;
            while(u > ul) {
                d[asort[u].second][len] = curless;
                u--;
            }
        }
    }
    ll steps = l/n;
    ll last = l%n;
    for(int len = 1; len<=k; len++) {
        if(steps >= len) {
            ll yo = 0;
            forn(i, 0, n) yo=(yo+d[i][len]) % mod;
            ans = (ans + ((steps-len + 1)%mod)*yo) % mod;
        }
        if (steps+1 >= len) {
            ll yo = 0;
            forn(i, 0, last) yo=(yo+d[i][len]) % mod;
            ans = (ans +yo) %mod;
        }
    }
    cout<<ans;
}