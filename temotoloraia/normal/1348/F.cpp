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
//const int MOD = 1e9+7;
//const int MOD = 998244353;

int n;
int a[N], b[N], ans[N], pas[N];
int mas[N];
int ui[N];
pair < int, int > P[N];
vector < int > V[N];
priority_queue < pair < int, int > > Q;

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        V[a[i]].pb (i);
    }
    for (int i = 1; i <= n; i++){
        for (int ind : V[i]){
            Q.push ({-b[ind], ind});
        }
        auto it = Q.top();
        ans[it.S] = i;
        pas[i] = b[it.S];
        if (it.F == -i)
            ui[i] = i;
        Q.pop();
    }
    for (int i = 1; i <= n; i++)
        ui[i] = max (ui[i-1], ui[i]);
    for (int i = 1; i <= n; i++){
        mas[i] = i+1;
        if (pas[i] >= i+1)
            mas[i] = mas[i-1];
    }
    for (int i = 1; i <= n; i++){
        for (int ind : V[i]){
            Q.push ({-b[ind], ind});
        }
        pair < int, int > it = Q.top();
        Q.pop();
        if (Q.size() == 0)
            continue;
        pair < int, int > A = Q.top();
        int x = i, y = ans[A.S];
        if (ui[y-1] < pas[x]){
            cout << "NO" << endl;Q.pop();
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << endl;
            Q.push (it);
            ans[A.S] = i;
            for (int j = i+1; j <= n; j++){
                for (int ind : V[j]){
                    Q.push ({-b[ind], ind});
                }
                auto it = Q.top();
                ans[it.S] = j;
                Q.pop();
            }
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--)
        solve();
}