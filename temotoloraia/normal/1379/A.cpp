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

string s, S, str = "abacaba";
int n;

bool check (){
    int num = 0;
    for (int i = 0; i < n-6; i++){
        int ok = 1;
        for (int j = 0; j < 7; j++)
            if (s[i + j] != str[j])
                ok = 0;
        num += ok;
    }
    if (num == 1)
        return 1;
    return 0;
}

void solve () {
    cin >> n >> S;
    for (int x = 6; x < n; x++){
        s = S;
        bool ok = 0;
        for (int i = x - 6; i <= x; i++){
            if (s[i] == '?')
                s[i] = str[i-x+6];
            else if (s[i] != str[i-x+6]){
                ok = 1;
                break;
            }
        }
        if (ok)
            continue;
        ok = 0;
        for (int i = 0; i < n; i++){
            if (s[i] != '?')
                continue;
            for (char ch = 'c'; ch >= 'a'; ch--){
                s[i] = ch;
                if (check ()){
                    break;
                }
                s[i] = '?';
            }
            if (s[i] == '?'){
                ok = 1;
                break;
            }
        }
        if (ok)
            continue;
        if (check ()){
            cout << "YES" << endl;
            cout << s << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        solve ();
    }
}