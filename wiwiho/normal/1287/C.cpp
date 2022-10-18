//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
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

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pii> odd, even;
    int all = 0, ocnt = n / 2 + n % 2, ecnt = n / 2;
    int lst = -1, lstp = -1;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 0) continue;
        if(lstp == -1){
            if(i != 0){
                if(a % 2 == 1) odd.eb(mp(i, 1)), ans += 1;
                else even.eb(mp(i, 1)), ans += 1;
            }
        }
        else if(lst % 2 != a % 2){
            all++, ans++;
        }
        else if(i - lstp - 1 > 0){
            if(a % 2 == 1) odd.eb(mp(i - lstp - 1, 2)), ans += 2;
            else even.eb(mp(i - lstp - 1, 2)), ans += 2;
        }

        if(a % 2 == 1) ocnt--;
        else ecnt--;

        lst = a;
        lstp = i;
    }
    if(lstp != n - 1){
        if(lstp == -1){
            if(n > 1) cout << "1\n";
            else cout << "0\n";
            return 0;
        }
        if(lst % 2 == 1) odd.eb(mp(n - lstp - 1, 1)),ans += 1;
        else even.eb(mp(n - lstp - 1, 1)), ans += 1;
    }

    int mx = 0;
    vector<int> dp(ocnt + 1);
    for(pii i : odd){
        for(int j = ocnt; j >= i.F; j--) dp[j] = max(dp[j], dp[j - i.F] + i.S), mx = max(mx, dp[j]);
    }
    ans -= mx;
    mx = 0;
    dp.clear();
    dp.resize(ecnt + 1);
    for(pii i : even){
        for(int j = ecnt; j >= i.F; j--) dp[j] = max(dp[j], dp[j - i.F] + i.S), mx = max(mx, dp[j]);
    }
    ans -= mx;
    cout << ans << "\n";

    return 0;
}