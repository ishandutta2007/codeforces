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
ostream &operator<<(ostream &o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<vector<ll>> dp;
vector<ll> a;
vector<int> cnt;
ll cost = 0;

int lp = 0, rp = -1;

void moveR(int to){
    while(rp < to){
        rp++;
        cost += cnt[a[rp]];
        cnt[a[rp]]++;
    }
    while(rp > to){
        cnt[a[rp]]--;
        cost -= cnt[a[rp]];
        rp--;
    }
}

void moveL(int to){
    while(lp < to){
        cnt[a[lp]]--;
        cost -= cnt[a[lp]];
        lp++;
    }
    while(lp > to){
        lp--;
        cost += cnt[a[lp]];
        cnt[a[lp]]++;
    }
}

int n;

void f(int k, int l, int r, int tl, int tr){
    if(l > r) return;
    int m = (l + r) / 2;

    moveR(m);
    pll p = mp(1LL << 60, -1);

    for(int i = tl; i < m && i <= tr; i++){
        moveL(i + 1);
        p = min(p, mp(dp[k - 1][i] + cost, (ll)i));
    }

    dp[k][m] = p.F;
    f(k, l, m - 1, tl, p.S);
    f(k, m + 1, r, p.S, tr);
}

int main(){
    StarBurstStream

    int k;
    cin >> n >> k;

    dp.resize(k + 1, vector<ll>(n + 1, 1LL << 60));
    a.resize(n + 1);
    cnt.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[0][0] = 0;

    for(int i = 1; i <= k ;i++){
        f(i, 1, n,  0, n - 1);
    }

    cout << dp[k][n] << "\n";

    return 0;
}