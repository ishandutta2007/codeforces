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

const int N = (int)1e6 + 6;

string s, t;
int n;
int z[N*2];

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> t;
    --n;
    for(auto & c : t){
        if(c == 'N')c = 'S';
        else if(c == 'S')c = 'N';
        else if(c == 'E')c = 'W';
        else if(c == 'W')c = 'E';
    }
    reverse(all(t));
    t += s;
    int l = 0, r = 0;
    z[0] = 0;
    F(i, 1, 2*n){
        if(i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < 2 * n && t[z[i]] == t[i + z[i]])++z[i];
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    F(i, n, 2*n){
        if(z[i] == 2*n - i){cout << "NO"; ret 0;}
    }
    cout << "YES";
    return 0;
}