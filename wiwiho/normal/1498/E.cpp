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

bool query(int a, int b){
    cout << "? " << a << " " << b << "\n" << flush;
    string r;
    cin >> r;
    return r == "Yes";
}

void ans(int a, int b){
    cout << "! " << a << " " << b << "\n" << flush;
    exit(0);
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> in(n + 1), out(n + 1);
    vector<pii> tmp(n);
    for(int i = 1; i <= n; i++){
        cin >> in[i];
        out[i] = n - 1 - in[i];
        tmp[i - 1] = mp(in[i], i);
    }

    lsort(tmp);

    for(int len = n - 1; len > 0; len--){
        for(int i = 0; i + len < n; i++){
            int u = tmp[i].S, v = tmp[i + len].S;
            if(out[u] + in[v] == n - 1){
                ans(u, v);
            }
            if(out[u] + in[v] > n - 1){
                if(query(v, u)) ans(u, v);
            }
            if(out[v] + in[u] > n - 1){
                if(query(u, v)) ans(u, v);
            }
        }
    }
    ans(0, 0);

    return 0;
}