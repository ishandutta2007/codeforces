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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 6;

int f[30][N];
int pref[30][N];
int lp[N];

void precalc(){
    pref[0][0] = f[0][0] = 1;
    for(int i = 1; i < 30; i++){
        f[i][0] = 2;
        pref[i][0] = f[i][0] + pref[i - 1][0];
        pref[i][0] -= pref[i][0] >= mod ? mod : 0;
    }
    for(int level = 1; level < N; level++){
        pref[0][level] = f[0][level] = 1;
        for(int pw = 1; pw < 30; pw++){
            f[pw][level] = pref[pw][level - 1];
            pref[pw][level] = f[pw][level] + pref[pw - 1][level];
            pref[pw][level] -= pref[pw][level] >= mod ? mod : 0;
        }
    }
    for(int i = 2; i < N; i++){
        if(lp[i])
            continue;
        for(int j = i; j < N; j += i){
            lp[j] = lp[j] ? lp[j] : i;
        }
    }
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precalc();
    int T;
    scanf("%d", &T);
    while(T--){
        int r, n;
        scanf("%d%d", &r, &n);
        if(n == 1){
            printf("1\n");
            continue;
        }
        ll ans = 1;
        while(n > 1){
            int p = lp[n];
            int pw = 0;
            while(lp[n] == p){
                n /= p;
                ++pw;
            }
            ans = ans * f[pw][r] % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}