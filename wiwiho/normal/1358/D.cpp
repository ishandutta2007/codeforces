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


int main(){
    StarBurstStream

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> d(2 * n);
    for(int i = 0; i < n; i++) cin >> d[i], d[i + n] = d[i];

    deque<ll> dq;
    ll now = 0;
    ll days = 0;
    ll ans = 0;
    for(int i = 0; i < 2 * n; i++){
        now += d[i] * (d[i] + 1) / 2;
        days += d[i];
        dq.eb(i);
        while(days > x){
            days -= d[dq.front()];
            now -= d[dq.front()] * (d[dq.front()] + 1) / 2;
            dq.pof;
        }
        if(dq.empty()){
            ans = max(ans, (2 * d[i] - x + 1) * x / 2);
            continue;
        }
        ll t = now;
//        printv(dq, cerr);
        if(dq.front() > 0) t += (2 * d[dq.front() - 1] - (x - days) + 1) * (x - days) / 2;
//        cerr << i << " " << now << " " << dq.front() << " " << dq.back() << " " << t  << "\n";
        ans = max(ans, t);
    }

    cout << ans << "\n";

    return 0;
}