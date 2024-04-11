#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
//#define int __int128
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 2005, MOD = 998244353;

int n;
string A, B;
int mas[26];
int dp[N][N];

void solve () {
    cin >> n >> A >> B;
    A = "#" + A;
    B = "#" + B;
    for (int i = 0; i < 26; i++)
        mas[i] = 0;
    for (int i = 1; i <= n; i++){
        mas[A[i]-'a']++;
        mas[B[i]-'a']--;
    }
    for (int i = 0; i < 26; i++)
    if (mas[i]){
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 26; j++)
            mas[j] = 0;
        for (int j = 1; j <= i; j++)
            mas[B[j]-'a']++;
        bool ok = 0;
        for (int x, j = 1; j <= n; j++){
            x = A[j]-'a';
            dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
            if (mas[x] == 0)
                ok = 1;
            if (ok)
                continue;
            mas[x]--;
            if (A[j] == B[i])
                dp[i][j] = max (dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    //cout << "HELLO ";
    cout << n - dp[n][n] << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--){
        solve ();
    }
}