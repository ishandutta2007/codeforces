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

int bp[252000];
int bm[252000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vi cm(1001,0);
    vi cp(1001,0);
    forn(i,0,k) {
        int x;
        scanf("%d", &x);
        x-=n;
        if(x==0) {
            cout<<1;
            return 0;
        }
        else if(x>0) {
            cp[x]=1;
        }
        else {
            cm[-x]=1;
        }
    }
    vi p;
    vi m;
    forn(i,0,1001) if(cp[i]) p.pb(i);
    forn(i,0,1001) if(cm[i]) m.pb(i);
    if(p.empty() || m.empty()) {
        cout<<-1;
        return 0;
    }
    forn(i,0,252000) {
        bp[i] = 10000;
        bm[i] = 10000;
    }
    bp[0] = 0;
    bm[0] = 0;
    int ans = 10000;
    forn(i,0,251000) {
        if(i>0) ans = min(ans, bp[i]+bm[i]);
        int bp1=bp[i]+1;
        int bm1=bm[i]+1;
        for(auto x : p) bp[x+i] = min(bp[x+i], bp1);
        for(auto x : m) bm[x+i] = min(bm[x+i], bm1);
    }
    cout<<ans;
    
    
    
}