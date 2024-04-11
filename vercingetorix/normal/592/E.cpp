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
#include <random>
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
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

struct comp {
    bool operator() (const pll & a, const pll & b) const {
        //        if(b.q>a.q) return true;
        //        else if(b.q<a.q) return false;
        //        else {
        return a.first*b.second < b.first*a.second;
        //        }
    }
};



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,cc,dd;
    scanf("%d %d %d", &n, &cc, &dd);
    int c =cc;
    int d= dd;
    vpll pos, neg;
    vll zer;
    forn(i,0,n) {
        int r,w;
        scanf("%d %d", &r, &w);
        r-=c;
        w-=d;
        if(w>0) pos.pb(mp((ll)r, (ll)w));
        if(w==0) zer.pb((ll)r);
        if(w<0) neg.pb(mp((ll)r, (ll)-w));
    }
    sort(all(pos), comp());
    sort(all(neg), comp());
    sort(all(zer));
    ll ans = 0;
    ll pon = 0;
    ll nop = 0;
    for(auto x : pos) {
        x.first = -x.first;
        auto it2 = upper_bound(all(neg), x, comp());
        auto it1 = lower_bound(all(neg), x, comp());
        ll ov = neg.end() - it2;
        ll un = it1 - neg.begin();
        ll mi = it2 - it1;
        pon+=un;
        nop+=ov;
        ans += ov*un;
    }
    for(auto x : neg) {
        x.first = -x.first;
        auto it2 = upper_bound(all(pos), x, comp());
        auto it1 = lower_bound(all(pos), x, comp());
        ll ov = pos.end() - it2;
        ll un = it1 - pos.begin();
        ll mi = it2 - it1;
        ans += ov*un;
    }
    for(auto u:zer) {
        if(u>0) ans += pon;
        else ans+=nop;
    }
    cout<<ans;
    
    
    
}