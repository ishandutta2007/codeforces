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
#define int long long

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

const int N = 400005, INF = 1e15;
int MOD = 1e9 + 7;

int n, m, k;
int P[N];
int a[N];

int datA (int R, int ind){
    return (a[ind] - 1) / R;
    int l = 0, r = a[ind];
    while (l < r){
        int mid = l + r >> 1;
        int x = (a[ind] + mid) / (mid + 1);
        if (x <= R)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int datB (int L, int ind){
    return a[ind] / L - 1;
    int l = 0, r = a[ind];
    while (l < r){
        int mid = l + r + 1 >> 1;
        int x = a[ind] / (mid + 1);
        if (x >= L)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

vector < pair < int, int > > V;

main()
{
    //ios_base::sync_with_stdio(0);
    int tes;
    cin >> tes;
    while (tes--){
        scanf ("%lld%lld%lld", &n, &m, &k);
        bool OK = 1;
        for (int i = 1; i <= m; i++)
            scanf ("%lld", &P[i]);
        P[m + 1] = n;
        m++;
        int S = m + k;
        if (n % S != 0)
            OK = 0;
        S = n / S;
        for (int i = 1; i <= m; i++){
            a[i] = P[i] - P[i - 1];
            if (a[i] % S != 0)
                OK = 0;
        }
        if (OK){
            printf ("0\n");
            continue;
        }
        sort (a + 1, a + m + 1);
        int L, R;
        int l = 1, r = a[m];
        while (l < r){
            int mid = l + r >> 1;
            int num = 0;
            for (int i = 1; i <= m; i++)
                num += datA (mid, i);
            if (num > k)
                l = mid + 1;
            else
                r = mid;
        }
        R = l;
        l = 1;
        r = a[1];
        while (l < r){
            int mid = l + r + 1 >> 1;
            int num = 0;
            for (int i = 1; i <= m; i++)
                num += datB (mid, i);
            if (num < k)
                r = mid - 1;
            else
                l = mid;
        }
        L = l;
        V.clear();
        for (int i = 1; i <= m; i++){
            int x = datA (R, i), y = datB (L, i);
            if (x <= y)
                continue;
            int X = a[i] / (x + 1), Y = (a[i] + y) / (y + 1);
            V.pb ({X, Y});
        }
        int ans = INF;
        V.pb ({L, L});
        sort (V.begin(), V.end());
        r = R;
        for (int i = 0; i < (int)V.size(); i++){
            l = min (L, V[i].F);
            ans = min (ans, r - l);
            r = max (r, V[i].S);
        }
        printf ("%lld\n", ans);
    }
    return 0;
}
/*
5
80 3 5
11 24 50
81 7 12
4 10 17 26 37 48 61
25 10 14
3 4 7 12 13 15 17 19 21 23
1 0 0

10 2 0
2 4
*/