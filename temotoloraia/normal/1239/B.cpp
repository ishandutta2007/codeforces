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

const int N = 1000005, MOD = 1e9 + 7;

int n;
string S;
int a[N];
int M;

int ans, L, R;

int x[N], y[N];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> S;
    S = "#" + S;
    for (int i = 1; i <= n; i++){
        a[i] = a[i - 1];
        if (S[i] == '(')
            a[i]++;
        else
            a[i]--;
        M = min (M, a[i]);
    }
    if (a[n] != 0){
        cout << 0 << endl;
        cout << "1 1" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == M)
            ans++;
    L = 1;
    R = 1;
    for (int I = M; I <= M + 2; I++){
        int l = n, r = 1;
        for (int i = 1; i <= n; i++)
            if (a[i] < I){
                l = min (l, i);
                r = max (r, i);
            }
        for (int i = 1; i <= n; i++){
            x[i] = x[i - 1];
            y[i] = y[i - 1];
            if (a[i] == I - 2)
                x[i]++;
            if (a[i] == I)
                y[i]++;
        }
        int X = - 10 * n;
        int Y;
        int le = 0, ri = 0;
        int num;
        for (int i = 0; i < n; i++){
            if (S[i + 1] == ')'){
                if (y[i] - x[i] > X && i + 1 <= l){
                    le = i;
                    X = y[i] - x[i];
                }
            }
            else {
                if (i >= r){
                    ri = i;
                    Y = x[i] - y[i];
                    num = y[n] + X + Y;
                    if (num > ans){
                        ans = num;
                        L = le + 1;
                        R = ri + 1;
                    }
                }
            }
        }
    }
    for (int I = M - 2; I <= M; I++){
        for (int i = 1; i <= n; i++){
            x[i] = x[i - 1];
            y[i] = y[i - 1];
            if (a[i] == I + 2)
                x[i]++;
            if (a[i] == I)
                y[i]++;
        }
        int X = - 10 * n;
        int Y;
        int le = 0, ri = 0;
        int num;
        for (int i = 0; i < n; i++){
            if (a[i] < I + 2){
                le = 0;
                X = - n * 10;
            }
            if (S[i + 1] == '('){
                if (y[i] - x[i] > X){
                    le = i;
                    X = y[i] - x[i];
                }
            }
            if (S[i + 1] == ')') {
                ri = i;
                Y = x[i] - y[i];
                num = y[n] + X + Y;
                if (num > ans){
                    ans = num;
                    L = le + 1;
                    R = ri + 1;
                }
            }
        }
    }
    cout << ans << endl;
    cout << L << " " << R << endl;
    return 0;
}