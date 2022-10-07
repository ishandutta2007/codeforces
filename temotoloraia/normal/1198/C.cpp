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

int Test;
int n, m;

bool F[N], fix[N];

int u[N], v[N];



main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> Test;
    while (Test--){
        scanf ("%d %d", &n, &m);
        for (int i = 1; i <= n * 3; i++)
            F[i] = 0;
        for (int i = 1; i <= m; i++)
            fix[i] = 0;
        for (int i = 1; i <= m; i++)
            scanf ("%d %d", &u[i], &v[i]);
        int num = 0;
        for (int i = 1; i <= m; i++){
            if (F[u[i]] == 1 || F[v[i]] == 1)
                continue;
            F[u[i]] = 1;
            F[v[i]] = 1;
            fix[i] = 1;
            num++;
        }
        if (num >= n){
            cout << "Matching" << endl;
            num = n;
            for (int i = 1; i <= m && num > 0; i++)
                if (fix[i] == 1){
                    cout << i << " ";
                    num--;
                }
            cout << endl;
        }
        else {
            cout << "IndSet" << endl;
            num = n;
            for (int i = 1; i <= 3 * n && num > 0; i++)
                if (F[i] == 0){
                    cout << i << " ";
                    num--;
                }
            cout << endl;
        }
    }
    return 0;
}