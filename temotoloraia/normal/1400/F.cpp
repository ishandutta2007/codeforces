#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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

const int N = (1<<20)+5, MOD = 998244353;


vector < int > V;
int M[(1<<20)+5];
int dp[20000], DP[20000];
bool ch[20000];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //freopen ("sequence.in", "r", stdin);freopen ("sequence.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    string S;
    int k;
    cin >> S >> k;
    if (k == 1){
        for (int i = 0; i < S.size(); i++)
            if (S[i] == '1')
            M[0]++;
        cout << M[0] << endl;return 0;
    }
    for (int B = 1; B < (1 << k); B+=2){
        bool ok = 0;
        for (int i = 0; i < k-1; i++){
            int x = (1 << i) + (1 << i+1);
            if ((B & x) == x){
                ok = 1;
                break;
            }
        }
        if (ok)
            continue;
        V.pb (B);
        M[B] = (int)V.size();
    }
    for (int i = 1; i < k; i++)
        if (k % i == 0)
            ch[i] = 1;
    int n = (int)S.size();
    S = "#" + S;
    for (int I = 1; I <= n; I++){
        if (S[I] == '1'){
            int mx = n;
            for (int j = 0; j < (int)V.size(); j++)
                mx = min (mx, dp[j]);
            for (int j = 0; j < (int)V.size(); j++)
                dp[j] = mx;
            continue;
        }
        for (int j = 0; j < (int)V.size(); j++)
            DP[j] = dp[j]+1;
        int x = S[I] - '0';
        if (x % k == 0){
            for (int j = 0; j < (int)V.size(); j++)
                dp[j]++;
            continue;
        }
        if (x > k){
            continue;
        }
        for (int B : V){
            vector < int > v;
            v.pb (0);
            for (int i = 0; i <= k-x; i++)
                if (B & (1 << i))
                    v.pb (i+x);
            bool ok = 1;
            if (v.back() == k)
                ok = 0;
            for (int i = 0; i < v.size() && ok == 0; i++)
                for (int j = i+1; j < v.size(); j++)
                    if (ch[v[j] - v[i]]){
                        ok = 1;break;
                    }
            if (ok){
                int bt = 0;
                for (int i : v)
                    if (i < k)
                        bt ^= (1 << i);
                bt = M[bt]-1;
                DP[bt] = min (DP[bt], dp[M[B]-1]);
            }
        }
        for (int j = 0; j < (int)V.size(); j++)
            dp[j] = DP[j];
    }
    int ans = n;
    for (int j = 0; j < (int)V.size(); j++){
        ans = min (ans, dp[j]);
    }
    cout << ans << endl;
}