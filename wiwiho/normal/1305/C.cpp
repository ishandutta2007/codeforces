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

ll fp(ll a, ll b, ll m){
    ll now = 1;
    ll base = a;

    while(b > 0){
        if(b & 1) now = now * base % m;
        base = base * base % m;
        b >>= 1;
    }

    return now;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    if(n > m){
        cout << "0\n";
        return 0;
    }

    vector<ll> a(n);
    vector<ll> now(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    lsort(a);
    for(int i = 0; i < n; i++){
        a[i] %= m;
    }

    vector<ll> ans(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(now[j] == 0) continue;
            ll t = ((a[i] - j) % m + m) % m;
            ans[t] += now[j];
        }
        now[a[i]]++;
    }

    ll p = 1;
    for(int i = 0; i < m; i++){
        if(ans[i] == 0) continue;
        p = p * fp(i, ans[i], m) % m;
    }
    cout << p << "\n";

    return 0;
}