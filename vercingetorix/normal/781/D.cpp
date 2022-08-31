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
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
bitset<500> a[2][61][500];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,m) {
        int u,v,t;
        scanf("%d %d %d", &u, &v, &t);
        u--; v--;
        a[t][0][u].set(v);
    }
    forn(bit,1,61) {
        forn(rt,0,2) {
            int f = rt;
            int s = 1-rt;
            forn(st,0,n) {
                forn(en, 0, n) {
                    if(a[f][bit-1][st][en]) {
                        a[f][bit][st] |= a[s][bit-1][en];
                    }
                }
            }
        }
    }
    if(a[0][60][0].count() > 0) {
        cout<<-1;
        return 0;
    }
    ll ans = 0;
    ll d60 = 1ll<<60;
    ll bit = 60;
    bitset<500> cur;
    cur.set(0);
    int f = 0;
    while(bit >= 0) {
        bitset<500> can;
        forn(i,0,n) {
            if(cur[i]) can |= a[f][bit][i];
        }
        if(can.count() > 0) {
            f = 1 - f;
            ans += d60;
            cur = can;
        }
        bit--;
        d60 >>= 1;
    }
    if(ans>1000000000000000000ll) ans = -1;
    cout<<ans;
    
    
}