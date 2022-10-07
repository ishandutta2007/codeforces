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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/
using namespace std;

const int MAXN = 1000000;


int n;
int mas[30];
int pas[30];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        mas[s[i] - 'a']++;
    for (int a = n / 3; a >= 0; a--){
        int b = n - a * 3;
        if (b % 4 != 0)
            continue;
        b /= 4;
        for (int i = 0; i < 26; i++)
            pas[i] = 0;
        pas['o' - 'a'] += a;
        pas['n' - 'a'] += a;
        pas['e' - 'a'] += a;
        pas['z' - 'a'] += b;
        pas['e' - 'a'] += b;
        pas['r' - 'a'] += b;
        pas['o' - 'a'] += b;
        bool ok = 1;
        for (int i = 0; i < 26; i++)
            if (pas[i] != mas[i])
                ok = 0;
        if (ok){
            for (int i = 0; i < a; i++)
                cout << "1 ";
            for (int i = 0; i < b; i++)
                cout << "0 ";
            cout << endl;
            return 0;
        }
    }
    return 0;
}