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

const int MAXN = 200005;

int n;
int PO[MAXN];
int B[MAXN];
int ANS, ans, pas;
int a[MAXN], b[MAXN];
int R[MAXN][20];

int RMQ (int l, int r){
    int x = B[r - l + 1];
    int y = r - PO[x] + 1;
    int z = R[l][x], t = R[y][x];
    if (a[z] < a[t])
        return z;
    return t;
}

int solve (int l, int r){
    if (l == r)
        return 1;
    if (l > r)
        return 0;
    int ind = RMQ (l, r);
    int x = solve (l, ind - 1);
    int y = solve (ind + 1, r);
    return max (x, y) + 1;
}


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    PO[0] = 1;
    for (int i = 1; i <= 30; i++)
        PO[i] = PO[i - 1] * 2;
    for (int i = 2; i < MAXN; i++){
        B[i] = B[i - 1];
        if ((i & (i - 1)) == 0)
            B[i]++;
    }
    cin >> n;
    int ind = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 1)
            ind = i;
    }
    ans = n - ind;
    pas = ind - n;
    for (int i = 1; i <= ind; i++)
        b[i + ans] = a[i];
    for (int i = ind + 1; i <= n; i++)
        b[i - ind] = a[i];
    for (int i = 1; i <= n; i++){
        a[i] = b[i];
        R[i][0] = i;
    }
    for (int I = 1; PO[I] <= n; I++){
        for (int i = 1; i + PO[I] <= n + 1; i++){
            int x = R[i][I - 1], y = R[i + PO[I - 1]][I - 1];
            if (a[x] < a[y])
                R[i][I] = x;
            else
                R[i][I] = y;
        }
    }
    ANS = n + 100;
    ans = 0;
    int l = 1, r = n - 1;
    for (int i = 0; i < 20; i++){
        int mid = l + r + 1 >> 1;
        int x = solve (1, mid);
        int y = solve (mid + 1, n - 1);
        int num = max (x, y) + 1;
        if (num < ANS){
            ANS = num;
            ans = mid;
        }
        if (x <= y)
            l = mid;
        else
            r = mid - 1;
    }
    for (int i = 0; i < 20; i++){
        int mid = l + r >> 1;
        int x = solve (1, mid);
        int y = solve (mid + 1, n - 1);
        int num = max (x, y) + 1;
        if (num < ANS){
            ANS = num;
            ans = mid;
        }
        if (x >= y)
            r = mid;
        else
            l = mid + 1;
    }
    ans += pas;
    if (ans < 0)
        ans += n;
    cout << ANS << " " << ans << endl;
    return 0;
}