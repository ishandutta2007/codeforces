#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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

vi spell;

int d[2][256];
int good[256];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,256) good[i] = __builtin_popcount(i)%2;
    vpi ev;
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    forn(i,0,n) {
        int l,r;
        scanf("%d %d", &l, &r);
        ev.pb(mp(l, i+1));
        ev.pb(mp(r+1, -i-1));
    }
    srt(ev);
    int pos = 0;
    int last = 0;
    for(auto x : ev) {
        int nx = pos^1;
        forn(i,0,256) d[nx][i] = 0;
        int cur = x.first;
        if(x.second > 0) {
            int ind = x.second - 1;
//            cout<<"add "<<ind<<'\n';
            forn(mask,0,1<<spell.size()) {
                int to = d[pos][mask] + good[mask]*(cur-last);
                d[nx][mask + (1<<spell.size())] = to;
                d[nx][mask] = to;
            }
            spell.pb(ind);
        }
        else {
            int ind = -x.second - 1;
//            cout<<"del "<<ind<<'\n';
            int w = -1;
//            for(auto x : spell) cout<<x<<' '; cout<<'\n';
            forn(i,0,spell.size()) if(spell[i] == ind) w = i;
            forn(i,w+1,spell.size()) spell[i-1] = spell[i];
            spell.pop_back();
//            for(auto x : spell) cout<<x<<' '; cout<<'\n';
//            cout<<"w "<<w<<'\n';
            int mb = (1<<w)-1;
            int ma = (1<<spell.size())-(1<<w);
            forn(tomask,0,1<<spell.size()) {
                int m1 = (tomask & mb) | ((tomask & ma) << 1);
                int m2 = m1 | 1<<w;
//                cout<<tomask<<' '<<m1<<' '<<m2<<'\n';
                d[nx][tomask] = max(d[pos][m1] + good[m1]*(cur-last), d[pos][m2] + good[m2]*(cur-last));
            }
        }
//        forn(i,0,1<<spell.size()) cout<<' '<<d[nx][i]; cout<<'\n';
        last = cur;
        pos^=1;
    }
    cout<<d[pos][0];
    
}