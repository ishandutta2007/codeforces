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

const int N = 1000005, MAXM = (1 << 20);

int n;
int a[N], b[N];
int nn, V[N];
int ans[N];

vector < int > M[MAXM + 5];
bool F[N];


void dfs (int k){
    int last = b[k];
    while (!M[last].empty() && F[M[last].back()])
        M[last].pop_back();
    if (M[last].empty()){
        V[nn--] = k;
        if (k & 1)
            V[nn--] = k+1;
        else
            V[nn--] = k-1;
        return;
    }
    int ind;
    ind = M[last].back();
    F[ind] = 1;
    if (ind & 1)
        ind++;
    else
        ind--;
    F[ind] = 1;
    dfs (ind);
    while (1){
        while (!M[last].empty() && F[M[last].back()])
            M[last].pop_back();
        if (M[last].empty())
            break;
        ind = M[last].back();
        F[ind] = 1;
        if (ind & 1)
            ind++;
        else
            ind--;
        F[ind] = 1;
        dfs (ind);
    }
    V[nn--] = k;
    if (k & 1)
        V[nn--] = k+1;
    else
        V[nn--] = k-1;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n*2; i++){
        scanf ("%d", &a[i]);
        ans[i] = i;
    }
    int X = 1;
    for (int it = 1; it <= 20; it++){
        X <<= 1;
        for (int i = 1; i <= n*2; i++){
            b[i] = (a[i] & (X-1));
            if (i >= 3)
                M[b[i]].push_back (i);
            F[i] = 0;
            V[i] = 0;
        }
        F[1] = 1;
        F[2] = 1;
        nn = n*2;
        dfs (2);
        for (int ne, i = 2; i <= n*2; i += 2){
            ne = i+1;
            if (ne > n*2)
                ne = 1;
            if (b[V[i]] != b[V[ne]] || nn){
                cout << it-1 << endl;
                for (int x = 1; x <= n*2; x++)
                    printf ("%d ", ans[x]);
                cout << endl;
                return 0;
            }
        }
        for (int i = 1; i <= n*2; i++)
            ans[i] = V[i];
        for (int i = 0; i < X; i++){
            M[i].clear();
            //while (!M[i].empty())M[i].pop();
        }
    }
    cout << 20 << endl;
    for (int x = 1; x <= n*2; x++)
        printf ("%d ", ans[x]);
    cout << endl;
}