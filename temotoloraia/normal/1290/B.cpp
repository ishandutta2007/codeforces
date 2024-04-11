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

const int N = 300005, MOD = 1e9 + 7;

string S;
int n;
int a[26][N];

main()
{
    ios_base::sync_with_stdio(0);
    cin >> S;
    n = (int)S.size();
    S = "#" + S;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 26; j++)
            a[j][i] = a[j][i - 1];
        a[S[i] - 'a'][i]++;
    }
    int Q;
    cin >> Q;
    while (Q--){
        int l, r;
        cin >> l >> r;
        int x = 0, y = 0;
        for (int i = 0; i < 26; i++){
            int d = a[i][r] - a[i][l - 1];
            if (d > 0)
                x++;
            if (d > 1)
                y++;
        }
        if (S[l] == S[r] && x <= 2 && l < r)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}