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

const int N = 100005;

int n, k;
int a[N];

void solve () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1 && a[1] == k){
        cout << "yes" << endl;
        return;
    }
    if (n == 1){
        cout << "no" << endl;
        return;
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] == k)
            ok = 0;
    if (ok){
        cout << "no" << endl;
        return;
    }
    for (int i = 1; i < n; i++){
        if (a[i] >= k && a[i+1] >= k){
            cout << "yes" << endl;
            return;
        }
    }
    for (int i = 2; i < n; i++){
        if (a[i-1] >= k && a[i+1] >= k){
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--)
        solve();
}