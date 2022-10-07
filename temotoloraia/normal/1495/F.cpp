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

/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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

const int N = 200005, MOD = 998244353;

int n, QQ;
int p[N], a[N], b[N], s[N];
int P[N][22], D[N][22];
int R[N][22], E[N][22];
set < int > S;
int mar[N];

int calc (int x, int y){
    if (x == y)
        return 0;
    int ans = 0;
    for (int i = 19; i >= 0; i--){
        if (P[x][i] <= y){
            ans += D[x][i];
            x = P[x][i];
        }
    }
    if (x == y)
        return ans;
    for (int i = 19; i >= 0; i--){
        if (R[y][i] >= x){
            ans += E[y][i];
            y = R[y][i];
        }
    }
    return ans;
}

main()
{
  //  freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
   // ios_base::sync_with_stdio(0);
    cin >> n >> QQ;
    for (int i = 1; i <= n; i++)
        scanf ("%lld",&p[i]);
    for (int i = 1; i <= n; i++)
        scanf ("%lld",&a[i]);
    for (int i = n; i >= 1; i--)
        s[i] = s[i+1] + a[i];
    for (int i = 1; i <= n; i++)
        scanf ("%lld",&b[i]);
    p[n+1] = n+1;
    stack < int > Q;
    Q.push (n+1);
    for (int i = n; i >= 1; i--){
        while (p[Q.top()] < p[i])
            Q.pop();
        P[i][0] = Q.top();
        Q.push (i);
    }
    P[n+1][0] = n+2;
    P[n+2][0] = n+2;
    for (int I = 0; I < 20; I++){
        P[n+1][I] = n+2;
        P[n+2][I] = n+2;
    }
    for (int i = n; i >= 1; i--){
        if (P[i][0] == i+1)
            D[i][0] = min (a[i], b[i]);
        else {
            int di = calc (i+1, P[i][0]);
            D[i][0] = min (a[i] + di, b[i]);
        }
        for (int I = 1; I < 20; I++){
            P[i][I] = P[P[i][I-1]][I-1];
            D[i][I] = D[i][I-1] + D[P[i][I-1]][I-1];
        }
    }
    while (Q.size() > 0)
        Q.pop();
    p[0] = n+1;
    Q.push (0);
    for (int i = 1; i <= n; i++){
        while (p[Q.top()] < p[i])
            Q.pop();
        R[i][0] = Q.top();
        E[i][0] = a[Q.top()] + calc (Q.top()+1, i);
        Q.push (i);
    }
    for (int I = 1; I < 20; I++){
        for (int i = 1; i <= n; i++){
            int pp = R[i][I-1];
            R[i][I] = R[pp][I-1];
            E[i][I] = E[i][I-1] + E[pp][I-1];
        }
    }
    S.insert (1);
    S.insert (n+1);
    int ANS = calc (1, n+1);
    while (QQ--){
        int x;
        scanf ("%lld", &x);
        if (S.find (x) == S.end()){
            auto it = S.lower_bound (x);
            int z = (*it);
            it--;
            int y = (*it);
            ANS += calc (y, x) + calc (x, z) - calc (y, z);
            S.insert (x);
        }
        else {
            if (x != 1){
                S.erase (S.find (x));
                auto it = S.lower_bound (x);
                int z = (*it);
                it--;
                int y = (*it);
                ANS -= calc (y, x) + calc (x, z) - calc (y, z);
            }
        }
        printf ("%lld\n", ANS);
    }
}