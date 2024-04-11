#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
//#define int long long
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


const int N = 100005, INF = 1e12;



void solve () {
    int n;
    string S;
    cin >> S;
    n = S.size();
    int num = 0;
    vector < int > V;
    for (int i = 0; i < n; i++){
        if (S[i] == '0'){
            if (num){
                V.pb (num);
                num = 0;
            }
        }
        else
            num++;
    }
    if (num)
        V.pb (num);
    sort (V.begin(), V.end());
    reverse (V.begin(), V.end());
    int ans = 0;
    for (int i = 0; i < V.size(); i += 2)
        ans += V[i];
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--)
        solve ();
}