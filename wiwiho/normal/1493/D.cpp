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

vector<map<int, int>> a;
vector<int> cnt;

vector<int> prime, lpd;

void sieve(int n){
    lpd.resize(n + 1, 1);
    for(int i = 2; i <= n; i++){
        if(lpd[i] == 1){
            lpd[i] = i;
            prime.eb(i);
        }
        for(ll j : prime){
            if(i * j > n) break;
            lpd[i * j] = j;
            if(j == lpd[i]) break;
        }
    }
}

vector<pii> getpd(int n){
    vector<pii> ans;
    while(n > 1){
        int now = lpd[n];
        int c = 0;
        while(n % now == 0){
            c++;
            n /= now;
        }
        ans.eb(mp(now, c));
    }
    return ans;
}

int n, q;
ll ans = 1;
void upd(int t){
    for(int i = 1; i <= n; i++){
        a[i][t]--;
        if(a[i][t] == 0) cnt[t]--;
    }
    ans = ans * t % MOD;
}

void add(int pos, int t){
    a[pos][t]++;
    if(a[pos][t] == 1) cnt[t]++;
    if(cnt[t] == n) upd(t);
}

void mul(int pos, int t){
    vector<pii> pd = getpd(t);
    for(pii i : pd){
        while(i.S--){
            add(pos, i.F);
        }
    }
}

int main(){
    StarBurstStream

    cin >> n >> q;

    a.resize(n + 1);
    cnt.resize(200000);
    sieve(200000);

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        mul(i, t);
    }

    while(q--){
        int i, x;
        cin >> i >> x;
        mul(i, x);
        cout << ans << "\n";
    }

    return 0;
}