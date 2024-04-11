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
//#define int long long

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

const int N = 300005, MOD = 1e9 + 7;

int n, k;
vector < int > v[N];
bool F[N];
bool fix[N];
char ch;
int num;

void mak (int cur){
    for (int x : v[cur])
        if (F[x] == 1){
            cout << "? " << x << endl;
            num++;
            cin >> ch;
            if (ch == 'Y'){
                F[x] = 0;
            }
        }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    int K = (k + 1) / 2;
    int M = (n - 1) / K + 1;
    for (int i = 0; i < n; i++)
        v[i / K].pb (i + 1);
    for (int i = 1; i <= n; i++)
        F[i] = 1;
    for (int t = 1; t * 2 <= M; t++){
        for (int i = 0; i < M; i++)
            fix[i] = 0;
        for (int i = 0; i < M; i++){
            if (fix[i] == 1)
                break;
            int cur = i;
            num = 0;
            while (fix[cur] == 0){
                fix[cur] = 1;
                mak (cur);
                cur += t;
                if (cur >= M)
                    cur -= M;
            }
            if (num <= k + 1){
                cout << "R" << endl;
                continue;
            }
            cout << "R" << endl;
            cur = (i - t + M) % M;
            mak (cur);
            mak (i);
            cout << "R" << endl;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (F[i] == 1)
            ans++;
    cout << "! " << ans << endl;
    return 0;
}