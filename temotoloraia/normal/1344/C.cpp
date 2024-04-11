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

const int N = 200005, INF = 1e17;

int n, m;
vector < int > A[N], B[N];
vector < int > V;
int a[N], b[N];
int mas[N];
bool F[N];

void dfs (int k){
    F[k] = 1;
    for (int to : A[k]){
        if (F[to] == 0)
            dfs (to);
    }
    V.pb (k);
    mas[k] = (int)V.size();
}
string ans;

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    while (m--){
        int x, y;
        cin >> x >> y;
        A[x].pb (y);
        B[y].pb (x);
    }
    for (int i = 1; i <= n; i++)
        if (F[i] == 0)
            dfs (i);
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = i;
    for (int i = 0; i < n; i++){
        int x = V[i];
        for (int y : A[x]){
            if (mas[y] > mas[x]){
                cout << -1 << endl;
                return 0;
            }
            a[x] = min (a[x], a[y]);
        }
    }
    for (int i = n-1; i >= 0; i--){
        int x = V[i];
        for (int y : B[x])
            b[x] = min (b[x], b[y]);
    }
    for (int i = 0; i < n; i++)
        ans += "E";
    int pas = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == i && b[i] == i){
            ans[i-1] = 'A';
            pas++;
        }
    cout << pas << endl;
    cout << ans << endl;
}