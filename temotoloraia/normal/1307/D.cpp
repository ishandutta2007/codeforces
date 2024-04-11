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

const int N = 1000005, MOD = 1e9 + 7;

int n, m, k;
int a[N];
vector < int > g[N];
int A[N], B[N];

queue < int > Q;

void bfs (int K){
    for (int i = 1; i <= n; i++)
        A[i] = n + 10;
    A[K] = 0;
    Q.push (K);
    while (Q.size() > 0){
        int t = Q.front();
        Q.pop();
        for (int to : g[t]){
            if (A[to] <= A[t] + 1)
                continue;
            A[to] = A[t] + 1;
            Q.push (to);
        }
    }
}


pair < int, int > P[N];
int mas[N];

bool check (int ans){
    if (A[n] < ans)
        return 0;
    for (int i = 1; i <= k; i++){
        int l = 0, r = i - 1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (P[mid].F + P[i].S + 1 >= ans)
                l = mid;
            else
                r = mid - 1;
        }
        if (l == 0)
            continue;
        if (mas[l] + P[i].F + 1 >= ans)
            return 1;
    }
    return 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    while (m--){
        int x, y;
        cin >> x >> y;
        g[x].pb (y);
        g[y].pb (x);
    }
    bfs (n);
    for (int i = 1; i <= n; i++)
        B[i] = A[i];
    bfs (1);
    for (int i = 1; i <= k; i++)
        P[i] = {A[a[i]], B[a[i]]};
    sort (P + 1, P + k + 1);
    reverse (P + 1, P + k + 1);
    for (int i = 1; i <= k; i++)
        mas[i] = max (mas[i - 1], P[i].S);
    int L = 1, R = n - 1;
    while (L < R){
        int mid = L + R + 1 >> 1;
        if (check (mid))
            L = mid;
        else
            R = mid - 1;
    }
    cout << L << endl;
    return 0;
}