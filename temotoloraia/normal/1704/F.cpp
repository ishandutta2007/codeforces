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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

//#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 500005, MOD = 998244353, INF = 1e11;


int gr[N];

int grundy (int x){
    if (x >= 200){
        x -= ((x-200)/34+1)*34;
    }
    return gr[x];
}

void solve () {
    int n;
    string S;
    cin >> n >> S;
    int b = 0, r = 0;
    if (S[0] == 'B')
        b++;
    else
        r++;
    int cnt = 1;
    int ans = 0;
    for (int i = 1; i < n; i++){
        if (S[i] == 'B')
            b++;
        else
            r++;
        if (S[i] != S[i-1])
            cnt++;
        else{
            int x = grundy (cnt);
            ans ^= x;
            //cout << "HI " << x << endl;
            cnt = 1;
        }
    }
    int x =grundy (cnt);
    ans ^= x;
            //cout << "HI " << x << endl;
    if (b > r)
        cout << "Bob";
    else if (b < r)
        cout << "Alice";
    else if (ans)
        cout << "Alice";
    else
        cout << "Bob";
    cout << endl;
}


main()
{
   // freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i = 2; i <= 200; i++){
        vector < int > V;
        for (int x = 0; x+x+2 <= i; x++)
            V.pb (gr[x] ^ gr[i-x-2]);
        sort (V.begin(), V.end());
        for (int x : V){
            if (x == gr[i])
                gr[i]++;
            if (x > gr[i])
                break;
        }
    }
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}