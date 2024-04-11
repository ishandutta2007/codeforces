//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int K = 21;
const int N = (int)2e5 + 5;
const int MAXA = (int)1e7 + 7;

int n, k;
int a[N];
int32_t lp[MAXA];
int32_t la[MAXA];
int stk[N];
int dp[N][K];
int ptr;

void sieve(){
    vector<int32_t> primes;
    for(int i = 2; i < MAXA; i++){
        if(!lp[i]){
            lp[i] = i;
            primes.push_back(i);
        }
        for(size_t j = 0; j < primes.size() && primes[j] <= lp[i] && i * 1ll * primes[j] < MAXA; j++){
            lp[i * primes[j]] = primes[j];
        }
    }
}

//#define TEST

void solve(){
#ifdef TEST
    n = (int)2e5;
    k = 20;
#else
    cin >> n >> k;
#endif
    for(int i = 0; i < n; i++){
#ifdef TEST
        a[i] = 10000000;
#else
        cin >> a[i];
#endif
        int mul = 1;
        while(a[i] > 1){
            int p = lp[a[i]];
            if(lp[a[i]/p] == p){
                a[i] /= p;
                a[i] /= p;
            }
            else{
                mul *= p;
                a[i] /= p;
            }
        }
        a[i] = mul;
    }
    for(int i = 0; i < n; i++)
        la[a[i]] = -1;
    set<int> fuck;
    fuck.insert(-1);
    for(int i = 0; i < n; i++){
        if(la[a[i]] != -1)
            fuck.insert(la[a[i]]);
        la[a[i]] = i;
        if(fuck.size() > k + 1)
            fuck.erase(fuck.begin());
        fill(dp[i], dp[i] + K, n + 228);
        int delta = fuck.size() - 1;
        for(int pos: fuck){
            for(int was = 0; was + delta <= k; was++){
                int val = pos == -1 ? 0 : dp[pos][was];
                dp[i][was + delta] = min(dp[i][was + delta], val + 1);
            }
            --delta;
        }
    }
    cout << *min_element(dp[n - 1], dp[n - 1] + K) << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(16);
    sieve();
    fill(la, la + MAXA, -1);
    int T = 1;
#ifndef TEST
    cin >> T;
#endif
    while(T--)
        solve();
    return 0;
}