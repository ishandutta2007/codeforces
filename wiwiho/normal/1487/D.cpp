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
#define iceil(a, b) (((a) + (b) - 1) / (b))
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

int main(){
    StarBurstStream

    int T;
    cin >> T;
//    T=10000;

    deque<pii> qry(T);
    for(int i = 0; i < T; i++){
        cin >> qry[i].F;
//        qry[i].F = 1000000000;
        qry[i].S = i;
    }
    lsort(qry);

    int ans = 0;
    int N = 1000000000;
    vector<int> qaq(T);
    for(ll a = 1; ((a * a + 1) >> 1) <= N; a++){
        if((a * a - 1) & 1) continue;
        ll b = (a * a - 1) >> 1;
        ll c = a * a - b;
//            cerr << a << " " << b << " " << c << "\n";
        while(!qry.empty() && qry.front().F < c){
            qaq[qry.front().S] = ans;
            qry.pof;
        }
        if(c <= N && b > 0 && a * a + b * b == c * c) ans++;
    }
    while(!qry.empty()){
        qaq[qry.front().S] = ans;
        qry.pof;
    }

    for(int i : qaq) cout << i << "\n";

    return 0;
}