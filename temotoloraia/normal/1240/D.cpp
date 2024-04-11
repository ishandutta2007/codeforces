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
const ll MM = 1e9;
const ll N = 5e5 + 5;

ll n;
ll a[N];


ll MOD[4] = {MM + 7, MM + 9, MM + 111, MM + 137};

map < vector < ll >, ll > M;

ll ans;

ll P;
ll PO[5][N];

ll V[N];

void solve (int l, int r){
    if (r <= l)
        return;
    int mid = l + r >> 1;
    vector < ll > v;
    for (int i = 0; i < 2; i++)
        v.pb (0);
    int num = 0;
    M.clear();
    for (int i = mid; i >= l; i--){
        if (num == 0){
            V[num] = a[i];
            for (int I = 0; I < 2; I++){
                v[I] = (v[I] + PO[I][num] * a[i]) % MOD[I];
            }
            num++;
            M[v]++;
            continue;
        }
        ll x = V[num - 1];
        if (x != a[i]){
            V[num] = a[i];
            for (int I = 0; I < 2; I++){
                v[I] = (v[I] + PO[I][num] * a[i]) % MOD[I];
            }
            num++;
            M[v]++;
            continue;
        }
        for (int I = 0; I < 2; I++){
            v[I] = (v[I] - PO[I][num - 1] * x) % MOD[I];
            if (v[I] < 0)
                v[I] += MOD[I];
        }
        M[v]++;
        num--;
    }
    for (int i = 0; i < 2; i++)
        v[i] = 0;
    num = 0;
    for (int i = mid + 1; i <= r; i++){
        if (num == 0){
            V[num] = a[i];
            for (int I = 0; I < 2; I++){
                v[I] = (v[I] + PO[I][num] * a[i]) % MOD[I];
            }
            num++;
            ans += M[v];
            continue;
        }
        ll x = V[num - 1];
        if (x != a[i]){
            V[num] = a[i];
            for (int I = 0; I < 2; I++){
                v[I] = (v[I] + PO[I][num] * a[i]) % MOD[I];
            }
            num++;
            ans += M[v];
            continue;
        }
        for (int I = 0; I < 2; I++){
            v[I] = (v[I] - PO[I][num - 1] * x) % MOD[I];
            if (v[I] < 0)
                v[I] += MOD[I];
        }
        ans += M[v];
        num--;
    }
    solve (l, mid);solve (mid + 1, r);
}


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    int Q;
    cin >> Q;
    while (Q--){
        scanf ("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf ("%lld", &a[i]);
        P = n + 147;
        for (int I = 0; I < 4; I++){
            PO[I][0] = 1;
            for (int i = 1; i <= n; i++)
                PO[I][i] = PO[I][i - 1] * P % MOD[I];
        }
        ans = 0;
        solve (1, n);
        printf ("%lld\n", ans);
    }
    return 0;
}