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
//#define int long long

using namespace std;

const int N = 400005;

string S;
int n;
int s[N];
int a[N], b[N];
int SQR;

ll ans;


main() {
    ios_base::sync_with_stdio(0);
    cin >> S;
    n = (int)S.size();
    S = "#" + S;
    for (int i = 1; i <= n; i++){
        s[i] = s[i - 1] + S[i] - '0';
    }
    SQR = sqrt ((n / 4));
    for (int k = 1; k <= SQR; k++){
        for (int i = 0; i <= n; i++)
            a[i] = k * s[i] - i;
        sort (a, a + n + 1);
        b[0] = 0;
        for (int i = 1; i <= n; i++){
            b[i] = 0;
            if (a[i] == a[i - 1])
                b[i] = b[i - 1] + 1;
            ans += b[i];
        }
    }

    for (int D = 1; D * (SQR + 1) <= n; D++){
        int x = 0, y = 0;
        int T = D * (SQR);
        int X, Y;
        for (int i = 0; i <= n; i++){
            while (x < n && s[x + 1] < s[i] + D)
                x++;
            while (y < n && s[y + 1] <= s[i] + D)
                y++;
            X = x - i, Y = y - i;
            if (X < T)
                X = T;
            Y /= D;
            X /= D;
            if (Y > X)
                ans += Y - X;
        }
    }
    cout << ans << endl;
}