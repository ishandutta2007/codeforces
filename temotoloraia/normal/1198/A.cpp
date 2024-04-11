#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
/*
#pragma GCC optimize ("O3")
#pragma comment(linker, "/STACK: 20000000005")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
*/
using namespace std;
 
const int N = 500005;
 
int n, k;
 
int a[N];
int b[N];
int ans;
 
main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n >> k;
    k *= 8;
    k /= n;
    if (k >= 19){
        cout << 0 << endl;
        return 0;
    }
    k = (1 << k);
    if (k > n){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        scanf ("%d", &a[i]);
    sort (a + 1, a + n + 1);
    a[0] = -1;
    for (int i = 1; i <= n; i++){
        b[i] = b[i - 1];
        if (a[i] > a[i - 1])
            b[i]++;
    }
    ans = n;
    int I = 0;
    for (int i = 0; i <= n; i++){
        while (b[I] < b[i] + k && I < n)
            I++;
        if (I > n)
            break;
        ans = min (ans, n - (I - i));
    }
    cout << ans << endl;
    return 0;
}