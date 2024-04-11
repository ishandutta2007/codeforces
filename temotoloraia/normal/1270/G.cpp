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

#pragma GCC optimize ("O3")
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 1000005;

int n;
int a[N];
int p[N];
bool fix[N];

main() {
    //ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf ("%d", &a[i]);
            a[i] = i - a[i];
        }
        for (int i = 1; i <= n; i++){
            p[i] = 0;
            fix[i] = 0;
        }
        if (a[1] == 1){
            printf ("1\n1\n");
            continue;
        }
        int cur = 1;
        vector < int > V;
        while (1){
            fix[cur] = 1;
            int to = a[cur];
            if (fix[to] == 0){
                p[to] = cur;
                cur = to;
                continue;
            }
            int t = cur;
            while (t != to){
                V.pb (t);
                t = p[t];
            }
            V.pb (to);
            break;
        }
        printf ("%d\n", (int)V.size());
        for (int i = 0; i < (int)V.size(); i++)
            printf ("%d ", V[i]);
        printf ("\n");
    }
}