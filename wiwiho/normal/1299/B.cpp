//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


ll cross(pll a, pll b){
    return a.F * b.S - a.S * b.F;
}

ll abs2(pll a){
    return a.F * a.F + a.S * a.S;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pll> p(n);
    for(int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;

    if(n % 2){
        cout << "NO\n";
        return 0;
    }

    vector<long double> a(n);
    for(int i = 0; i < n; i++){
        pll p1 = p[i], p2 = p[(i + 1) % n], p3 = p[(i + 2) % n];
        pll v1 = mp(p1.F - p2.F, p1.S - p2.S), v2 = mp(p3.F - p2.F, p3.S - p2.S);
        long double t = (long double)cross(v1, v2) / sqrt((long double)abs2(v1) / sqrt((long double)abs2(v2)));
        a[i] = t;
    }

    for(int i = 0; i < n / 2; i++){
        if(a[i] != a[n / 2 + i]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}