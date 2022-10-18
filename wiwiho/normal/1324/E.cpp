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

vector<int> BIT;

int lowbit(int x){
    return x & -x;
}

void modify(int x){
    if(x == 0) return;
    for(; x < BIT.size(); x += lowbit(x)) BIT[x] += 1;
}

int get(int x){
    int ans = 0;
    for(; x > 0; x -= lowbit(x)) ans += BIT[x];
    return ans;
}

int main(){
    StarBurstStream

    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(h, -1);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        vector<int> now(h, -1);
        for(int j = 0; j < h; j++){
            if(dp[j] == -1) continue;
            now[(j + a[i]) % h] = max(now[(j + a[i]) % h],
                                      dp[j] + (l <= (j + a[i]) % h && (j + a[i]) % h <= r));
            now[(j + a[i] - 1 + h) % h] = max(now[(j + a[i] - 1 + h) % h],
                                      dp[j] + (l <= (j + a[i] - 1 + h) % h && (j + a[i] - 1 + h) % h <= r));
        }
        dp = now;
//        printv(dp, cerr);
    }

    int ans = 0;
    for(int i = 0; i < h; i++) ans = max(ans, dp[i]);

    cout << ans << "\n";

    return 0;
}