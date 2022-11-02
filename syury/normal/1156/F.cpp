//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int mod = 998244353;
const int N = (int)5e3 + 3;

int dp[N][N];
int n;
int a[N];
int b[N];
int cnt[N];
int inv[N];
int pref[N][N];

signed main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    inv[1] = 1;
    F(i, 2, N){
        inv[i] = (mod - (mod/i)*1ll*inv[mod%i]%mod)%mod;
    }
    scanf("%d", &n);
    F(i, 0, n)
        scanf("%d", a + i);
    sort(a, a + n);
    int ptr = 0;
    int sz = 0;
    F(i, 0, n){
        if(i + 1 < n && a[i] == a[i + 1])cont;
        b[sz] = a[i];
        cnt[sz] = i - ptr + 1;
        ptr = i + 1;
        ++sz;
    }
    int tot = n;
    n = sz;
    memcpy(a, b, sizeof(a));
    dp[0][0] = 1;
    pref[0][0] = 1;
    int ans = 0;
    F(i, 0, n){
        dp[i+1][0] = 0;
        pref[i+1][0] = 1;
        E(j, 1, i + 1)pref[i+1][j] = pref[i][j];
        E(j, 1, i + 1){
            if(cnt[i] > 1){
                int val = pref[i][j - 1];
                val = val * 1ll * inv[tot - j + 1] % mod * cnt[i] % mod;
                val = val * 1ll * inv[tot - j] % mod * (cnt[i] - 1)%mod;
                ans += val;
                ans %= mod;
            }
            int val = pref[i][j - 1];
            val = val * 1ll * inv[tot - j + 1] % mod * cnt[i] % mod;
            dp[i+1][j] = val;
            pref[i+1][j] += val;
            pref[i+1][j] %= mod;
        }
    }
    cout << (ans + mod)%mod << endl;
	return 0;
}