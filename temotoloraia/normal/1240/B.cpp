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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 3e5 + 5;

int n;
int a[N];
int l[N], r[N];


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    int Q;
    cin >> Q;
    while (Q--){
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf ("%d", &a[i]);
        for (int i = 1; i <= n; i++){
            l[i] = n + 1;
            r[i] = 0;
        }
        for (int i = 1; i <= n; i++)
            r[a[i]] = i;
        for (int i = n; i >= 1; i--)
            l[a[i]] = i;
        int rad = 0;
        for (int i = 1; i <= n; i++)
            if (r[i])
                rad++;
        int ans = 1;
        int R = 0, x, num;
        for (int L = 1; L <= n; L++){
            if (L <= R)
                continue;
            R = L;
            x = r[L];
            num = 0;
            if (r[L])
                num++;
            while (R < n && x < l[R + 1]){
                R++;
                if (r[R])
                    num++;
                x = max (x, r[R]);
            }
            ans = max (ans, num);
        }
        cout << rad - ans << endl;
    }
    return 0;
}