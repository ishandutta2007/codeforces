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

const int A  = 500500;

int imp[A];
int curc[A];
int numbad = 0;
vi a;
vi b;
vpi q;
int l, r;

void adjust(int lto, int rto) {
    while(r < rto) {
        r++;
        curc[a[r]]--;
        if(imp[a[r]] > 0 && curc[a[r]] == 0) numbad--;
    }
    while(l<lto) {
        curc[a[l]]++;
        if(imp[a[l]] > 0 && curc[a[l]] == 1) numbad++;
        l++;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m,k,n,s;
    scanf("%d %d %d %d", &m, &k, &n, &s);
    readv(aa,m);
    l= 0;
    r = -1;
    a = aa;
    readv(bb,s);
    srt(bb);
    b = bb;
    for(auto x : b) {
        if(q.empty() || q.back().first != x) q.pb(mp(x,1));
        else q.back().second++;
    }
    for(auto x : q) {
        numbad++;
        imp[x.first] = x.second;
        curc[x.first] = x.second;
    }
    int xt = m - n*k;
    for(int s = 0; s<=(n-1)*k; s+=k) {
        adjust(s, s+k-1+xt);
        if(numbad == 0) {
            printf("%d\n", xt);
            vi del;
            forn(i,s,s+k+xt) {
                if(del.size() == xt) break;
                if(imp[a[i]] == 0 || curc[a[i]] < 0) {
                    del.pb(i);
                    curc[a[i]]++;
                }
            }
            for(auto x : del) printf("%d ", x+1);
            printf("\n");
            exit(0);
        }
    }
    printf("-1\n");
}