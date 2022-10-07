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
/*
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 100005;

int a[20];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        int n = s.size();
        int x = 0;
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        for (int i = 0; i < s.size(); i++){
            int t = s[i] - '0';
            x += t;
            a[t]++;
        }
        x %= 3;
        if (x != 0){
            cout << "cyan" << endl;
            continue;
        }
        string ans = "cyan";
        for (int i = 0; i < 10; i++){
            if (a[i] == 0)
                continue;
            a[i]--;
            for (int j = 0; j < 10; j++)
            if (a[j]){
                int y = i * 10 + j;
                if (y % 20 == 0)
                    ans = "red";
            }
            a[i]++;
        }
        cout << ans << endl;
    }
    return 0;
}