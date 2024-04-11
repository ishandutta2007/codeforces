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
template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
    
    T get(int l, int r) {
        T ret = get(r);
        if (l>0) ret -= get(l-1);
        return ret;
    }
};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    fenwick<int> r(n), c(n);
    vi cr(n,0), cc(n,0);
    while(q--) {
        int tp;
        read(tp);
        if(tp == 3) {
            int x1,y1,x2,y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            --x1; --y1; --x2; --y2;
            if(r.get(x1, x2) == x2-x1+1 || c.get(y1,y2) == y2-y1+1) printf("Yes\n");
            else printf("No\n");
        }
        else {
            int x,y;
            scanf("%d %d", &x, &y);
            --x; --y;
            if(tp == 1) {
                cr[x] ++;
                cc[y] ++;
                if(cr[x] == 1) r.modify(x, 1);
                if(cc[y] == 1) c.modify(y, 1);
            }
            else {
                cr[x] --;
                cc[y] --;
                if(cr[x] == 0) r.modify(x, -1);
                if(cc[y] == 0) c.modify(y, -1);
            }
        }
    }
    
    
}