#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll __int128
//#define ll long long
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


const int N = 200005;

int mas[30][30];
vector < int > g[N];
bool F[20];

void dfs (int k){
    F[k] = 1;
    for (int to : g[k])
    if (F[to] == 0)
        dfs (to);
}

void solve () {
    int n;
    string A, B;
    cin >> n >> A >> B;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            mas[i][j] = 0;
    for (int i = 0; i < n; i++){
        if (A[i] == B[i])
            continue;
        if (A[i] > B[i]){
            cout << -1 << endl;
            return;
        }
        mas[A[i]-'a'][B[i]-'a'] = 1;
    }
    for (int i = 0; i < 20; i++){
        g[i].clear();
        F[i] = 0;
    }
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            if (mas[i][j]){
                g[i].pb (j);
                g[j].pb (i);
            }
    int ans = 20;
    for (int i = 0; i < 20; i++){
        if (F[i])
            continue;
        dfs (i);
        ans--;
    }
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve ();
}