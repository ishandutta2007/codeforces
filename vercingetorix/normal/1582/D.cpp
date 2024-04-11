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
char t[200500];

vi get(int a, int b, int c) {
    if(a==b) {
        if(c < 0) return get(-a,-b,-c);
        if(c > 1) return vi({c-1,1,-a});
        return vi({1,1,-2*a});
    }
    if(b == c) {
        vi ret = get(c,b,a);
        swap(ret[0], ret[2]);
        return ret;
    }
    if(a == c) {
        vi ret = get(a,c,b);
        swap(ret[1], ret[2]);
        return ret;
    }
    return vi({b-c,c-a,a-b});
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char c[200500];
    forn(ifa,0,ta) {
        int n;
        scanf("%d\n", &n);
        readv(a,n);
        if(n%2 == 0) {
            forn(i,0,n/2) {
                printf("%d %d ", a[i*2+1], -a[i*2]);
            }
            printf("\n");
        }
        else {
            int i0 = 0, i1 = 1, i2 = 2;
            if(n > 100) {
                vi p, m;
                forn(i,0,10) {
                    if(a[i]>0) p.pb(i);
                    else m.pb(i);
                }
                if(p.size() >= 3) {
                    i0 = p[0];
                    i1 = p[1];
                    i2 = p[2];
                }
                else {
                    i0 = m[0];
                    i1 = m[1];
                    i2 = m[2];
                }
            }
            vi ans(n);
            vi fi;
            forn(i,0,n) if(i!=i0 &&i!=i1&&i!=i2) fi.pb(i);
            vi res = get(a[i0], a[i1], a[i2]);
            ans[i0] = res[0];
            ans[i1] = res[1];
            ans[i2] = res[2];
                        for(int i = 0; i < fi.size(); i+=2) {
                            ans[fi[i]] = -a[fi[i+1]];
                            ans[fi[i+1]] = a[fi[i]];
                        }

            forn(i,0,n) printf("%d ", ans[i]);
            printf("\n");
        }
    }
    
    
}