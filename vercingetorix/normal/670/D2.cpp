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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vi a(n);
    vi b(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) scanf("%d", &b[i]);
    vpi en;
    forn(i,0,n) en.pb(mp(b[i]/a[i], i));
    sort(all(en));
    vll need(n);
    vll have(n);
    ll curn = 0;
    ll curh = 0;
    forn(i,0,n) {
        curn += (ll)a[en[i].second];
        need[i]=curn;
        curh += (ll)b[en[i].second];
        have[i] = curh;
    }
    int l = 0;
    int r = 2000000000;
    while(r-l>0) {
        int m = ((ll)r+l+1)/2;
        int pos = lower_bound(all(en), mp(m,0)) - en.begin();
        bool f= false;
        if(pos == 0) f=true;
        else {
            if( (ll)k >= (ll)m * need[pos-1] - have[pos-1]) f=true;
            if((double)m * need[pos-1] - have[pos-1] > (double) 10*k) f=false;
        }
        if(f) l = m;
        else r=m-1;
    }
    cout<<l;
}