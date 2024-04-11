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

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x = 1;
    while(x <= n){
        if(x == n || x + 1 == n){cout << 1; ret 0;}
        if(x&1){
            x = 2 * (x + 1);
        }
        else x = 2 * (x + 1) - 1;
    }
    cout << 0;
    return 0;
}