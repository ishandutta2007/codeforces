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
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;


const ll N = 1000005, MOD = 1e9 + 7;

ll n, m, nn;
ll ANS;
ll ans[N];

pair < pair < ll, ll >, ll > P[N];


ll S[N];

deque < int > A, B;

ll p[N], s[N];


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> m >> n;
    nn = n * 2;
    for (int i = 1; i <= n; i++){
        scanf ("%d", &P[i].F.F);
        //P[i].F.F--;
        P[i].F.S = 1;
        P[i].S = i;
    }
    for (int i = n + 1; i <= nn; i++){
        scanf ("%d", &P[i].F.F);
        //P[i].F.F--;
        P[i].F.S = -1;
        P[i].S = i - n;
    }
    sort (P + 1, P + nn + 1);
    ll x = n;
    for (int i = 1; i <= nn; i++){
        x += P[i].F.S;
        S[x] += P[i % nn + 1].F.F - P[i].F.F;
        if (i == nn)
            S[x] += m;
    }
    ll ind = 0;
    ANS = 0;
    for (ll i = 1; i <= nn; i++)
        ANS += S[i] * i;
    p[0] = S[0];
    s[nn] = S[nn];
    for (int i = 1; i <= nn; i++)
        p[i] = p[i - 1] + S[i];
    for (int i = nn - 1; i >= 0; i--)
        s[i] = s[i + 1] + S[i];
    ll pas = ANS;
    for (ll i = 1; i <= nn; i++){
        pas -= s[i];
        pas += p[i - 1];
        if (pas < ANS){
            ANS = pas;
            ind = i;
        }
    }
    cout << ANS << endl;
    x = n;
    ll I = 0;
    for (int i = 0; i < nn; i++){
        x += P[i].F.S;
        if (x == ind){
            I = i + 1;
            break;
        }
    }
    for (int i = I; i < I + nn; i++){
        int j = (i - 1) % nn + 1;
        if (P[j].F.S == 1){
            if (B.size() == 0){
                A.push_back (j);
                continue;
            }
            int x = B.front();
            B.pop_front();
            ans[P[j].S] = P[x].S;
        }
        else {
            if (A.size() == 0){
                B.push_back (j);
                continue;
            }
            int x = A.front();
            A.pop_front();
            ans[P[x].S] = P[j].S;
        }
    }
    for (int i = 1; i <= n; i++)
        printf ("%d ", ans[i]);
    cout << endl;
    return 0;
}