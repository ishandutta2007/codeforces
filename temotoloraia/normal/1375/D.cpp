#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
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

const int MOD = 998244353;

int POWER (int x, int y){
    int ans = 1;
    while (y){
        if (y & 1)
            ans = ans * x % MOD;
        y >>= 1;
        x = x * x % MOD;
    }
    return ans;
}


const int N = 300005;


vector < int > ans;
set < int > S;
set < int >::iterator it;
int a[N], b[N];
int n;
vector < int > V[N];



void solve () {
    cin >> n;
    S.clear();
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[a[i]]++;
    }
    for (int i = 0; i <= n; i++)
        if (b[i] == 0)
            S.insert (i);
    while (1){
        it = S.begin();
        int x = (*it);
        if (x == n)
            break;
        ans.pb (x);
        b[a[x]]--;
        if (b[a[x]] == 0)
            S.insert (a[x]);
        a[x] = x;
        b[x]++;
        S.erase (it);
    }
    int T = n;
    for (int i = 0; i < n; i++){
        if (a[i] == i)
            continue;
        int t = n;
        for (int j = 0; j < n; j++)
            if (a[j] == i){
                t = j;
                break;
            }
        if (t == n){
            T = a[i];
            ans.pb (i);
            a[i] = i;
            continue;
        }
        ans.pb (t);
        ans.pb (i);
        a[t] = T;
        T = a[i];
        a[i] = i;
    }
    cout << (int)ans.size() << endl;
    for (int x : ans)
        cout << x+1 << " ";
    cout << endl;
    ans.clear();
    for (int i = 0; i <= n; i++){
        b[i] = 0;
    }
}


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--){
        solve ();
    }
}