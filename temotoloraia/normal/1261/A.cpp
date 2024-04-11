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

const int N = 2005;

int n, k;
string S;


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int Q;
    cin >> Q;
    while (Q--){
        cin >> n >> k;
        cin >> S;
        S = "#" + S;
        cout << n << endl;
        int t = n / 2 - k + 1;
        for (int i = 1; i <= t; i++){
            int p = 0;
            for (int j = i; j <= n; j++)
                if (S[j] == '('){
                    p = j;
                    break;
                }
            cout << i << " " << p << endl;
            int r = i + p >> 1;
            for (int j = i; j <= r; j++)
                swap (S[j], S[p + i - j]);
        }
        for (int i = t + 1; i <= t * 2; i++){
            int p = 0;
            for (int j = i; j <= n; j++)
                if (S[j] == ')'){
                    p = j;
                    break;
                }
            cout << i << " " << p << endl;
            int r = i + p >> 1;
            for (int j = i; j <= r; j++)
                swap (S[j], S[p + i - j]);
        }
        for (int i = t * 2 + 1; i <= n; i++){
            char ch = '(';
            if (i % 2 == 0)
                ch = ')';
            int p = 0;
            for (int j = i; j <= n; j++)
                if (S[j] == ch){
                    p = j;
                    break;
                }
            cout << i << " " << p << endl;
            int r = i + p >> 1;
            for (int j = i; j <= r; j++)
                swap (S[j], S[p + i - j]);
        }
    }
    return 0;
}