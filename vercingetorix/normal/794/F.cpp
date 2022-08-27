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

ll spos[10][400000];
int ext[10][400000];
ll wsp[10];
class stree {
public:
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            s = a.size();
        }
        forn(i,0,10) ext[i][v] = i;
        if (tl == tr) {
            ll d10 = 1;
            ll val = a[tl];
            while(val > 0) {
                spos[val%10][v] += d10;
                val /= 10;
                d10 *= 10;
            }
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            forn(i,0,10) spos[i][v] = spos[i][v*2] + spos[i][v*2 + 1];
        }
    }
    
    void push(int v) {
        if(v<2*s) {
            forn(i,0,10) {
                ext[i][v*2] = ext[ext[i][v*2]][v];
                ext[i][v*2+1] = ext[ext[i][v*2+1]][v];
            }
        }
        forn(i,0,10) {
            wsp[i] = spos[i][v];
            spos[i][v] = 0;
        }
        forn(i,0,10) {
            spos[ext[i][v]][v] += wsp[i];
            ext[i][v] = i;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int x, int y) {
        push(v);
        if (l > r)
            return;
        if (l == tl && tr == r) {
            forn(i,0,10) if(ext[i][v] == x) ext[i][v] = y;
            push(v);
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), x, y);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, x, y);
            forn(i,0,10) spos[i][v] = spos[i][v*2] + spos[i][v*2 + 1];
        }
    }
    
    ll gsum (int v, int tl, int tr, int l, int r) {
        push(v);
        if (l > r) return 0;
        if (l == tl && tr == r) {
            ll res = 0;
            forn(i,0,10) res+=spos[i][v] * i;
            return res;
        }
        else {
            int tm = (tl + tr) / 2;
            ll res = gsum(v*2, tl, tm, l, min(r,tm)) + gsum(v*2+1, tm+1, tr, max(l,tm+1), r);
            forn(i,0,10) spos[i][v] = spos[i][v*2] + spos[i][v*2 + 1];
            return res;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    stree st;
    st.build(a, 1, 0, n-1);
    forn(i,0,q) {
        int t,l,r;
        scanf("%d %d %d", &t, &l, &r);
        l--; r--;
        if(t==2) printf("%lld\n", st.gsum(1, 0, n-1, l, r));
        else {
            int x,y;
            scanf("%d %d", &x, &y);
            st.update(1, 0, n-1, l, r, x, y);
        }
    }
    
}