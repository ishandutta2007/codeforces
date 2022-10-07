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

const int N = 200005, M = 100005;

string s;
int n;
int a[N];
int ans[N];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--){
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
            a[i] = s[i - 1] - '0';
        bool ok = 0;
        for (int x = 0; x <= 9; x++){
            int A = 0, B = x;
            ok = 1;
            for (int i = 1; i <= n; i++){
                if (a[i] >= B){
                    ans[i] = 2;
                    B = a[i];
                    continue;
                }
                if (a[i] < A || a[i] > x){
                    ok = 0;
                    break;
                }
                A = a[i];
                ans[i] = 1;
            }
            if (ok)
                break;
        }
        if (ok == 0){
            cout << "-" << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i];
        cout << endl;
    }
    return 0;
}