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

    int n, d;
    cin >> n >> d;

    vector<int> cnt(30001);
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        cnt[p]++;
    }

    vector<vector<int>> dp(30001, vector<int>(500));

    for(int i = 30000; i >= 0; i--){
        for(int j = 1; j < 499; j++){
            int l = j - 250 + d;
            if(l <= 0) continue;

            dp[i][j] = cnt[i];
            if(i + l + 1 <= 30000) dp[i][j] = max(dp[i][j], dp[i + l + 1][j + 1] + cnt[i]);
            if(i + l <= 30000) dp[i][j] = max(dp[i][j], dp[i + l][j] + cnt[i]);
            if(i + l - 1 <= 30000 && i - 1 > 0) dp[i][j] = max(dp[i][j], dp[i + l - 1][j - 1] + cnt[i]);
        }
    }

    //for(int i = 0; i < 100; i++) printv(dp[i], cerr);

    cout << dp[d][250] << "\n";

    return 0;
}