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
struct sparse_table{
    vector<vector<T>> ST;
    sparse_table(vector<T> &A){
        int N = A.size();
        int LOG = 32 - __builtin_clz(N);
        ST = vector<vector<T>>(LOG, vector<T>(N));
        for (int i = 0; i < N; i++){
            ST[0][i] = A[i];
        }
        for (int i = 0; i < LOG - 1; i++){
            for (int j = 0; j < N - (1 << i); j++){
                ST[i + 1][j] = gcd(ST[i][j], ST[i][j + (1 << i)]);
            }
        }
    }
    T get(int L, int R){
        R++;
        int d = 31 - __builtin_clz(R - L);
        return gcd(ST[d][L], ST[d][R - (1 << d)]);
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    sparse_table<int> st(a);
    const int A = 5000001;
    vll cnt(A,0);
    map<int, ll> cntbig;
    forn(i,0,n) {
        int to = i;
        while(to < n) {
            int val = st.get(i, to);
            int l = to;
            int r = n;
            while(r-l>1) {
                int m = (r+l)/2;
                if(st.get(i, m) == val) l = m;
                else r = m;
            }
            if(val < A) cnt[val] += r-to;
            else cntbig[val] += r-to;
            to = r;
        }
    }
    
    int q;
    read(q);
    while(q--) {
        int k;
        scanf("%d", &k);
        if(k<A) printf("%lld\n", cnt[k]);
        else printf("%lld\n", cntbig[k]);
    }
    
}