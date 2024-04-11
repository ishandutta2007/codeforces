#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
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

const int N = 505, M = 1000000;



void solve () {
    char ch = '0';
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0')
            x = 1;
        else
            y = 1;
    if (x+y==1){
        cout << s << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ch){
            cout << ch;
            ch = '0' + '1' - ch;
            continue;
        }
        cout << ch << s[i];
    }
    cout << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve();
    }
}