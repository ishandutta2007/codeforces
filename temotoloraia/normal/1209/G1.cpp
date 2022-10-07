#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
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

const int N = 200005, M = 200000;

int n;
int a[N], b[N];
int x[N], y[N];
int mas[N];
int ans;
pair < int, int > P[N];

int num[N];



main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> a[0];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        num[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        y[a[i]] = i;
    for (int i = n; i >= 1; i--)
        x[a[i]] = i;
    for (int i = 1; i <= M; i++)
        P[i] = {x[i], y[i]};
    sort (P + 1, P + M + 1);
    int x = 0, y = 0, z = 1;
    for (int i = 1; i <= M; i++){
        if (P[i].S == 0)
            continue;
        if (P[i].F <= y){
            y = max (y, P[i].S);
            z = max (z, num[a[P[i].F]]);
            continue;
        }
        ans += y - x + 1 - z;
        x = P[i].F;
        y = P[i].S;
        z = num[a[P[i].F]];
    }
    ans += y - x + 1 - z;
    cout << ans << endl;
    return 0;
}