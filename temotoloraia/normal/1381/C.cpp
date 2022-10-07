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

const int N = 200005;

int n, x, y;
int a[N], ans[N];
vector < int > V[N];
int nn, mas[N];
int rad[N];

void solve (){
    cin >> n >> x >> y;
    y -= x;
    for (int i = 0; i <= n+1; i++){
        V[i].clear();
        ans[i] = 0;
        rad[i] = 0;
    }
    int T = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        V[a[i]].pb (i);
        rad[a[i]]++;
    }
    int t = y/2;
    nn = 0;
    int mx = 0;
    for (int i = 1; i <= n + 1; i++){
        if ((int)V[i].size() == 0){
            T = i;
            continue;
        }
        if ((int)V[i].size() > (int)V[mx].size())
            mx = i;
        int p = min (y - nn, (int)V[i].size());
        p = min (p, t);
        while (p--){
            mas[nn++] = V[i].back();
            V[i].pop_back();
        }
    }
    for (int i = 0; i <= n+1; i++){
        V[i].clear();
    }
    for (int i = 1; i <= n; i++){
        V[a[i]].pb (i);
    }
    if (nn >= y){
        for (int i = 0; i < y; i++)
            ans[mas[i]] = a[mas[(i+t)%y]];
    }
    else {
        if (mx == 0){
            cout << "NO" << endl;
            return;
        }
        int pas = min ((int)V[mx].size(), n - (int)V[mx].size());
        if (pas * 2 < y){
            cout << "NO" << endl;
            return;
        }
        int X = y/2, Y = (y+1)/2;
        vector < int > inx;
        for (int i = 1; i <= n; i++){
            if (a[i] == mx)
                continue;
            inx.pb (a[i]);
            if (X){
                ans[i] = mx;
                rad[mx]--;
                X--;
            }
        }
        reverse (inx.begin(), inx.end());
        for (int i = 1; i <= n; i++){
            if (a[i] != mx)
                continue;
            if (Y){
                ans[i] = inx.back();
                rad[inx.back()]--;
                inx.pop_back();
                Y--;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (ans[i])
            continue;
        if (x && rad[a[i]]){
            x--;
            rad[a[i]]--;
            ans[i] = a[i];
        }
        else
            ans[i] = T;
    }
    if (x){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        solve ();
    }
}