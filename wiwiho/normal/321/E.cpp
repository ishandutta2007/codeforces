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

vector<vector<int>> u;

vector<vector<int>> dp;

void f(int k, int l, int r, int tl, int tr){
    int m = (l + r) / 2;
    int tmp = tl;

    for(int i = tl; i < m && i <= tr; i++){
        if(dp[k - 1][i] + u[m][m] - u[i][m] - u[m][i] + u[i][i] < dp[k][m]){
            dp[k][m] = dp[k - 1][i] + u[m][m] - u[i][m] - u[m][i] + u[i][i];
            tmp = i;
        }
    }

    if(l <= m - 1) f(k, l, m - 1, tl, tmp);
    if(m + 1 <= r) f(k, m + 1, r, tmp, tr);
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    u.resize(n + 1, vector<int>(n + 1));
    dp.resize(k + 1, vector<int>(n + 1, 500000000));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> u[i][j];
            u[i][j] += u[i][j - 1] + u[i - 1][j] - u[i - 1][j - 1];
        }
    }

    dp[0][0] = 0;
    for(int i = 1; i <= k; i++){
        f(i, i, n, i - 1, n - 1);
    }

    cout << dp[k][n] / 2 << "\n";

    return 0;
}