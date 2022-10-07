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

const int N = 1000005, INF = 1e9 + 5;

int n, k;
int a[N];


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int tes;
    cin >> tes;
    while (tes--){
        cin >> n >> k;
        for (int i = 0; i < 60; i++)
            a[i] = 0;
        string ans = "YES";
        while (n--){
            int x;
            cin >> x;
            for (int i = 0; i < 60; i++){
                int y = x % k;
                if (y > 1)
                    ans = "NO";
                else if (y == 1){
                    if (a[i])
                        ans = "NO";
                    a[i]++;
                }
                x /= k;
            }
        }
        cout << ans << endl;
    }
}