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

const int N = 100005, INF = 1e18;

int n;
int a[N];
int p[N], zoma[N], ans;

multiset < int > S;

int parent (int x){
    if (p[x] == x)
        return x;
    return p[x] = parent (p[x]);
}

void mrg (int x, int y){
    x = parent (x);
    y = parent (y);
    if (zoma[x] == 0 || zoma[y] == 0)
        return;
    S.erase (S.find (zoma[x]));
    if (y < n)
    S.erase (S.find (zoma[y]));
    p[x] = y;
    zoma[y] += zoma[x];
    if(y < n)
        S.insert (zoma[y]);
}

void solve () {
    cin >> n;
    S.clear();
    S.insert (0);
    for (int i = 1; i <= n; i++){
        p[i] = i;
        zoma[i] = 0;
    }
    for (int x, i = 1; i <= n; i++){
        cin >> x;
        int t = parent (x-1);
        auto it = S.end();
        it--;
        //cout << (*it) << " " << zoma[t] << endl;
        if ((*it) > zoma[t]){
            for (int j = i + 1; j <= n; j++)
                cin >> x;
            //cout << (*it) << " " << zoma[t] << endl;
            cout << "No" << endl;
            return;
        }
        zoma[x] = 1;
        if (x < n)
        S.insert (1);
        if (x > 1)
            mrg (x-1, x);
        if (x < n)
            mrg (x, x+1);
    }
    cout << "Yes" << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        solve ();
    }
}