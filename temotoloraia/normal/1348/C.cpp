#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
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
//const int MOD = 1e9+7;
const int MOD = 998244353;

int mas[26];

void solve () {
    int n, k;
    for (int i = 0; i < 26; i++)
        mas[i] = 0;
    cin >> n >> k;
    vector < char > V (n);
    for (int i = 0; i < n; i++){
        char ch;
        cin >> V[i];
        ch = V[i];
        mas[ch-'a']++;
    }
    sort (V.begin(), V.end());
    if (V[k-1] != V[0] || k==n){
        cout << V[k-1] << endl;
        return;
    }
    if (V[k] != V[n-1]){
        cout << V[0];
        for (int i = k; i < n; i++)
            cout << V[i];
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i += k)
        cout << V[i];
    cout << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--)
        solve();
}