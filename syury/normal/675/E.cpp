//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue

template<typename T>
struct Promotion{};

template<> struct Promotion<char>{typedef int16_t promoted;};
template<> struct Promotion<int8_t>{typedef int16_t promoted;};
template<> struct Promotion<int16_t>{typedef int32_t promoted;};
template<> struct Promotion<int32_t>{typedef int64_t promoted;};
#if defined(_WIN64) || defined(__LP64__)
template<> struct Promotion<int64_t>{typedef __int128 promoted;};
#endif
template<> struct Promotion<uint8_t>{typedef uint16_t promoted;};
template<> struct Promotion<uint16_t>{typedef uint32_t promoted;};
template<> struct Promotion<uint32_t>{typedef uint64_t promoted;};
#if defined(_WIN64) || defined(__LP64__)
template<> struct Promotion<uint64_t>{typedef unsigned __int128 promoted;};
#endif
template<> struct Promotion<float>{typedef double promoted;};
template<> struct Promotion<double>{typedef long double promoted;};

#define PROM(x) ((typename Promotion<typename std::__decay_and_strip<decltype(x)>::__type>::promoted)(x))

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 55;

int a[N];
int n;
ll va[N];
ll t[4*N];

void build(int v, int l, int r){
    t[v] = l;
    if(l == r)ret;
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
    if(a[t[2*v]] < a[t[2*v+1]])t[v] = t[2*v+1]; else t[v] = t[2*v];
}

inline int gmax(int x, int y){
    if(x == -1)ret y;
    if(y == -1)ret x;
    ret a[x] < a[y] ? y : x;
}

int get(int v, int l, int r, int ul, int ur){
    if(ul > ur)ret -1;
    if(l == ul && r == ur)ret t[v];
    int mid = (l + r)/2;
    ret gmax(get(2*v, l, mid, ul, min(ur, mid)), get(2*v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    F(i, 0, n)cin >> a[i];
    build(1, 0, n - 1);
    ll ans = 0;
    DF(i, n - 1, 0){
        --a[i];
        int j = get(1, 0, n - 1, i, a[i]);
        va[i] = n - 1 - i;
        va[i] += va[j] - (a[i] - j);
        ans += va[i];
    }
    cout << ans << endl;
    return 0;
}