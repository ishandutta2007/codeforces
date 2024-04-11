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

const int N = 105, MOD = 1e9+7;

int n;
int a[N], b[N], ind[N];
int ans;
vector < int > ANS[N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ind[a[i]] = i;
    }
    while (1){
        int x = 0;
        for (int i = 1; i < n; i++)
            if (ind[i] > ind[i+1]){
                x = i;
                break;
            }
        if (x == 0)
            break;
        int A = ind[x+1];
        int B = ind[x];
        int C = B;
        while (a[C-1] == a[C] - 1)
            C--;
        int pas = 2;
        if (ind[x] < n)
            pas++;
        if (ind[x+1] > 1)
            pas++;
        ans++;
        ANS[ans].pb (pas);
        if (A > 1)
            ANS[ans].pb (A-1);
        ANS[ans].pb (C-A);
        ANS[ans].pb (B - C + 1);
        if (B < n)
            ANS[ans].pb (n-B);
        int nn = 0;
        for (int i = B+1; i <= n; i++)
            b[++nn] = a[i];
        for (int i = C; i <= B; i++)
            b[++nn] = a[i];
        for (int i = A; i <= C-1; i++)
            b[++nn] = a[i];
        for (int i = 1; i <= A-1; i++)
            b[++nn] = a[i];
        for (int i = 1; i <= n; i++){
            a[i] = b[i];
            ind[a[i]] = i;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++){
        for (int x : ANS[i])
            cout << x << " ";
        cout << endl;
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--){
        solve ();
    }
}