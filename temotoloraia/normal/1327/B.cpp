#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
//#define ll long long
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
/*
#pragma comment(linker, "/STACK: 20000000005")
*/


using namespace std;

const int N = 200005, MOD = 998244353;

int n;
int nn;
int mas[N];
bool A[N], B[N];

main()
{
    ios_base::sync_with_stdio(0);
    int tes;
    cin >> tes;
    while (tes--){
        cin >> n;
        for (int i = 1; i <= n; i++)
            A[i] = B[i] = 0;
        for (int i = 1; i <= n; i++){
            cin >> nn;
            for (int j = 1; j <= nn; j++)
                cin >> mas[j];
            reverse (mas + 1, mas + nn + 1);
            while (nn > 0 && B[mas[nn]] == 1)
                nn--;
            if (nn == 0)
                continue;
            B[mas[nn]] = 1;
            A[i] = 1;
        }
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++){
            if (A[i] == 0)
                x = i;
            if (B[i] == 0)
                y = i;
        }
        if (x == 0)
            cout << "OPTIMAL" << endl;
        else
            cout << "IMPROVE" << endl << x << " " << y << endl;
    }
    return 0;
}