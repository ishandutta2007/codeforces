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
class stree {
public:
    vi t;
    int s;
    void build (int n, int v, int tl, int tr) {
        t = vi(4*n, 0);
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  max(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  max(t[v*2], t[v*2+1]);
        }
    }
};
const int A= 200500;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int add = 200000;
    stree poslis, hlis;
    int n,m;
    scanf("%d %d", &n, &m);
    poslis.build(A, 1, 0, A-1);
    hlis.build(A, 1, 0, A-1);
    vpi posh;
    set<int> pos;
    vi ht(n, 0);
    while(m--) {
        int tp;
        scanf("%d", &tp);
        forn(i,0,posh.size()) {
            if(posh[i].second >= add+10) {
                swap(posh[i], posh.back());
                posh.pop_back();
                i--;
            }
        }
        if(tp == 1) {
            int p,h;
            scanf("%d %d", &p, &h);
            p--;
            for(auto & x : posh) {
                poslis.update(1, 0, A-1, x.first, 0);
                hlis.update(1, 0, A-1, x.second, 0);
            }
            posh.pb(mp(p, add+h));
            ht[p] = add+h;
            pos.insert(p);
            sort(all(posh), [&](const pi & x, const pi & y) {
                return x.second > y.second;
            });
            for(auto & x : posh) {
                int cur = poslis.get(1, 0, A-1, x.first, A-1) + 1;
                poslis.update(1, 0, A-1, x.first, cur);
                hlis.update(1, 0, A-1, x.second, cur);
            }
            printf("%d\n", poslis.get(1, 0, A-1, 0, A-1));
        }
        else {
            int k;
            scanf("%d", &k);
            auto it = pos.begin();
            vpi op;
            forn(i,0,k) {
                int cp = *it;
                poslis.update(1, 0, A-1, cp, 0);
                hlis.update(1, 0, A-1, ht[cp], 0);
                op.pb(mp(cp, ht[cp]));
                if(i!=k-1) it++;
            }
            forn(i,0,posh.size()) {
                if(posh[i].first == *it) {
                    swap(posh[i], posh.back());
                    posh.pop_back();
                    break;
                }
            }
            pos.erase(it);
            ht[op.back().first] = 0;
            op.pop_back();
            reverse(all(op));
            for(auto & x : op) {
                int cur = hlis.get(1, 0, A-1, x.second, A-1) + 1;
                poslis.update(1, 0, A-1, x.first, cur);
                hlis.update(1, 0, A-1, x.second, cur);
            }
            printf("%d\n", poslis.get(1, 0, A-1, 0, A-1));
        }
        add--;
    }
    
    
}