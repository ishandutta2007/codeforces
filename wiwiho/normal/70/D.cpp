#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

using namespace std;
using namespace __gnu_pbds;

#define orz
#ifdef orz
#define print(a...)cerr<<"Line "<<__LINE__<<":",kout("[" + string(#a) + "] = ", a)
void kout() { cerr << endl; }
template<class T1, class ... T2> void kout(T1 a, T2 ... e) { cerr << a << " ", kout(e...); }
#else
#define print(a..)
void kout() {}
template<class T1, class ... T2> void kout(T1 a, T2 ... e) {}
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

template<typename T>
pair<T, T> operator+(pair<T, T> a, pair<T, T> b){
    return mp(a.F + b.F, a.S + b.S);
}

template<typename T>
pair<T, T> operator-(pair<T, T> a, pair<T, T> b){
    return mp(a.F - b.F, a.S - b.S);
}

template<typename T>
pair<T, T> operator*(pair<T, T> a, T b){
    return mp(a.F * b, a.S * b);
}

template<typename T>
pair<T, T> operator/(pair<T, T> a, T b){
    return mp(a.F / b, a.S / b);
}

template<typename T>
T dot(pair<T, T> a, pair<T, T> b){
    return a.F * b.F + a.S * b.S;
}

template<typename T>
T cross(pair<T, T> a, pair<T, T> b){
    return a.F * b.S - a.S * b.F;
}

template<typename T>
T abs2(pair<T, T> a){
    return a.F * a.F + a.S * a.S;
}

template<typename T>
bool inPolygon(vector<pair<T, T>> polygon, pair<T, T> p){
    for(int i = 0; i < polygon.size(); i++)
        if(cross(p - polygon[i], polygon[(i - 1 + polygon.size()) % polygon.size()] - polygon[i]) *
           cross(p - polygon[i], polygon[(i + 1) % polygon.size()] - polygon[i]) > 0)
            return false;
    return true;
}

template<typename T>
void add(pll p, T& s){
    if(s.empty()){
        s.insert(p);
        return;
    }
    s.insert(p);
    auto it = s.lower_bound(p);
    if(it != s.begin() && next(it) != s.end() && cross(*it - *prev(it), *next(it) - *prev(it)) <= 0){
        s.erase(it);
        return;
    }
    while(it != s.begin() && prev(it) != s.begin() && cross(*prev(it) - *prev(prev(it)), *it - *prev(prev(it))) <= 0){
        it = s.erase(prev(it));
    }
    while(next(it) != s.end() && next(next(it)) != s.end() 
            && cross(*next(it) - *it, *next(next(it)) - *it) <= 0){
        it = s.erase(next(it));
        it--;
    }
}


template<typename T>
bool check(pll p, T& s){
    if(s.size() <= 1) return false;
    if(s.size() == 2){
        return cross(*s.rbegin() - *s.begin(), p - *s.begin()) >= 0;
    }

    bool tmp = s.find(p) == s.end();
    s.insert(p);
    auto it = s.lower_bound(p);
    if(it == s.begin() || next(it) == s.end()){
        s.erase(it);
        return !tmp;
    }

    if(it != s.begin() && next(it) != s.end() && cross(*it - *prev(it), *next(it) - *prev(it)) <= 0){
        s.erase(it);
        return true;
    }
    s.erase(it);
    return false;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    multiset<pll, greater<>> up;
    multiset<pll> down;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        int x, y;
        cin >> x >> y;

        if(t == 1){
            add(mp(x, y), up);
            add(mp(x, y), down);
        }
        else{
            bool t1 = check(mp(x, y), up);
            bool t2 = check(mp(x, y), down);
            if(t1 && t2) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}