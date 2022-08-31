#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,w,h;
    cin>>n>>w>>h;
    vector<pair<pi, int>> e;
    forn(i,0,n) {
        int x,y;
        cin>>x>>y;
        e.pb(mp(mp(x,y), i));
    }
    vi d(n,-1591059);
    vi p(n,-2);
    sort(all(e));
    int best = -1;
    forn(i,0,n) {
        if(e[i].first.first > w && e[i].first.second > h) {
            d[i] = 1;
            p[i] = -1;
        }
        forn(j,0,i) {
            if(e[j].first.first < e[i].first.first && e[j].first.second < e[i].first.second) {
                if(d[i] < d[j] + 1) {
                    d[i] = d[j] + 1;
                    p[i] = j;
                }
            }
        }
        if(best == -1 || d[best] < d[i]) best = i;
    }
    if(d[best] < 0) cout<<0;
    else {
        cout << d[best] << endl;
        vi ans;
        int cur = best;
        while(cur >= 0) {
            ans.pb(e[cur].second + 1);
            cur = p[cur];
        }
        reverse(all(ans));
        for(auto x : ans) cout<<x<<' ';
    }
    
    
    
}