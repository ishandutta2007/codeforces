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

const int N = 4000005;
int MOD = 1e9 + 7;

int B[40];
int D[N];
int a[N];


int fin (int k){
    while (1){
        int le = k*2, ri = k*2+1;
        if (a[le] == 0 && a[ri] == 0)
            return D[k];
        if (a[le] > a[ri])
            k = le;
        else
            k = ri;
    }
}

void mak (int k){
    int le = k*2, ri = k*2+1;
    if (a[le] == 0 && a[ri] == 0){
        a[k] = 0;
        return;
    }
    if (a[le] > a[ri]){
        a[k] = a[le];
        mak (le);
    }
    else {
        a[k] = a[ri];
        mak (ri);
    }
}
int P, Q;
vector < int > V;

void solve (int k){
    if (a[k] == 0)
        return;
    while (fin (k) > Q && a[k] > 0){
        mak (k);
        V.pb (k);
    }
    if (a[k] == 0)
        return;
    solve (k*2);
    solve (k*2+1);
}

main()
{
    ios_base::sync_with_stdio(0);
    B[0] = 1;
    for (int i = 1; i <= 30; i++)
        B[i] = B[i - 1] * 2;
    for (int i = 0; i < 20; i++)
        for (int j = B[i]; j < B[i + 1]; j++)
            D[j] = i + 1;
    int tes;
    cin >> tes;
    while (tes--){
        cin >> P >> Q;
        for (int i = 1; i < B[P]; i++)
            cin >> a[i];
        V.clear();
        solve (1);
        int sum = 0;
        for (int i = 1; i < B[Q]; i++){
            sum += a[i];
        }
        cout << sum << endl;
        for (int x : V)
            cout << x << " ";
        cout << endl;
        for (int i = 1; i < B[P]; i++)
            a[i] = 0;
    }
    return 0;
}