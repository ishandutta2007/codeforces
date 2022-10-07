#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
//#define int long long
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


const int N = 300005, INF = 1e9;

int n;
string S;
int a[N], b[N];
int X, Y;

bool CHECK (pair < int, int > x, pair < int, int > y, pair < int, int > xy, int X, int Y){
    if (X < x.F || x.S < X || Y < y.F || y.S < Y || X-Y < xy.F || xy.S < X-Y)
        return 0;
    return 1;
}

bool check (int T){
    pair < int, int > x, y, xy;
    x = {a[1]-T, a[1]+T};
    y = {b[1]-T, b[1]+T};
    xy = {a[1]-b[1]-T, a[1]-b[1]+T};
    for (int i = 2; i <= n; i++){
        x.F = max (x.F, a[i] - T);
        x.S = min (x.S, a[i] + T);
        y.F = max (y.F, b[i] - T);
        y.S = min (y.S, b[i] + T);
        xy.F = max (xy.F, a[i]-b[i] - T);
        xy.S = min (xy.S, a[i]-b[i] + T);
    }
    x.F = max (x.F, 0);
    y.F = max (y.F, 0);
    x.F = max (x.F, y.F + xy.F);
    //x.S = min (x.S, y.S + xy.S);
    y.F = max (y.F, x.F - xy.S);
    //y.S = min (y.S, x.S - xy.F);
    //if (x.F > x.S || y.F > y.S || xy.F > xy.S)return 0;
    X = x.F;
    Y = y.F;
    if (X+Y){
        if (CHECK (x, y, xy, X, Y))
            return 1;
        return 0;
    }
    pair < int, int > x1 = x, y1 = y, xy1 = xy;
    x.F = 1;
    y.F = max (y.F, x.F - xy.S);
    X = x.F;
    Y = y.F;
    if (CHECK (x, y, xy, X, Y))
        return 1;
    x = x1;
    y = y1;
    xy1 = xy;
    y.F = 1;
    x.F = max (x.F, y.F + xy.F);
    X = x.F;
    Y = y.F;
    if (CHECK (x, y, xy, X, Y))
        return 1;
    return 0;
}

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> S;
        for (int j = 0; j < S.size(); j++)
            if (S[j] == 'B')
                a[i]++;
            else
                b[i]++;
    }
    //cout << check (3) << endl;
    int l = 0, r = 500000;
    while (l < r){
        int mid = l + r >> 1;
        if (check (mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    check (l);
    for (int i = 0; i < X; i++)
        cout << "B";
    for (int i = 0; i < Y; i++)
        cout << "N";
    cout << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T = 1;
    //cin >> T;
    while (T--)
        solve ();
}