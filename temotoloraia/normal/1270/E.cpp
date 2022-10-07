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

#pragma GCC optimize ("O3")
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 1000005;

int n;
int x[N], y[N];
int ans[N];


main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int i = 2; i <= n; i++){
        x[i] -= x[1];
        y[i] -= y[1];
    }
    x[1] = y[1] = 0;
    while (1){
        int nn = 0;
        for (int i = 1; i <= n; i++){
            ans[i] = ((x[i] + y[i]) % 2 + 2) % 2;
            nn += ans[i];
        }
        if (0 < nn && nn < n){
            cout << nn << endl;
            for (int i = 1; i <= n; i++)
                if (ans[i])
                    cout << i << " ";
            cout << endl;
            return 0;
        }
        nn = 0;
        for (int i = 1; i <= n; i++){
            ans[i] = (x[i] % 2 + 2) % 2;
            nn += ans[i];
        }
        if (0 < nn && nn < n){
            cout << nn << endl;
            for (int i = 1; i <= n; i++)
                if (ans[i])
                    cout << i << " ";
            cout << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++){
            x[i] /= 2;
            y[i] /= 2;
        }
    }
}