#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
//#define int long long
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

const int N = 500005, M = 1e7;

vector < pair < int, int > > ans;
vector < int > pr;
int P[M+5];

void solve (){
    int X;
    scanf ("%d", &X);
    int x = X, y=1;
        int p = P[x];
        while (P[x] == p){
            x /= p;
            y *= p;
        }
    if (x == 1){
        ans.pb ({-1, -1});
        return;
    }
    ans.pb ({x, y});
}
main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    for (int i = 2; i <= M; i++){
        if (P[i] == 0){
            P[i] = i;
            pr.pb (i);
        }
        for (int x : pr){
            if (x > M/i || x > P[i])
                break;
            P[x*i] = x;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
    for (auto it : ans)
        printf ("%d ",it.F);
    printf ("\n");
    for (auto it : ans)
        printf ("%d ",it.S);
    printf ("\n");
}