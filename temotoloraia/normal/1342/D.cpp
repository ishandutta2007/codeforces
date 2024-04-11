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
/*
#pragma comment(linker, "/STACK: 20000000005")
*/
using namespace std;

const int N = 200005, M = 1000000;

int n, k;
int a[N];
int b[N];
int nn;
int mas[N];

vector < int > V[N];

main()
{
    //ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int x, i = 1; i <= n; i++){
        scanf ("%d", &x);
        a[x]++;
    }
    for (int i = 1; i <= k; i++)
        scanf ("%d", &b[i]);
    int ind = 1;
    for (int i = k; i >= 1; i--){
        if (b[i] > b[i+1])
            ind = 1;
        while (a[i]){
            if (ind > nn)
                nn++;
            int t = min (b[i] - mas[ind], a[i]);
            while (t--){
                mas[ind]++;
                a[i]--;
                V[ind].pb (i);
            }
            if (mas[ind] == b[i])
                ind++;
        }
    }
    cout << nn << endl;
    for (int i = 1; i <= nn; i++){
        printf ("%d ", (int)V[i].size());
        for(int x : V[i])
            printf ("%d ", x);
        printf ("\n");
    }
}