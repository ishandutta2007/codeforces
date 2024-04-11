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

const int N = 1000005, MOD = 1e9 + 7;

ll n, p;
pair < ll, ll > P[N];
int ind[N];

ll ans[N];

set < pair < ll, ll > > Q;

set < int > QQ;

set < int > S;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++){
        cin >> P[i].F;
        P[i].S = i;
    }
    sort (P + 1, P + n + 1);
    for (int i = 1; i <= n; i++)
        ind[P[i].S] = i;
    for (int i = 1; i <= n; i++)
        ans[i] = -1;
    ll T = 0;
    int X = n + 1;
    ll t = 0;
    for (int i = 1; i <= n; i++){
        while (T + p <= P[i].F && Q.size() > 0){
            auto it = Q.begin();
            T += p;
            ans[(*it).S] = T;
            QQ.erase ((*it).S);
            Q.erase (it);
            X = n + 1;
            if (QQ.size() > 0){
                X = (*QQ.begin());
            }
            if (S.size() > 0 && T < P[i].F){
                int x = (*S.begin());
                if (x <= X){
                    Q.insert ({max (t,T), x});
                    t = max (t, T) + 1;
                    QQ.insert (x);
                    X = x;
                    S.erase (x);
                }
            }
        }
        int I = P[i].S;
        if (Q.size() == 0 && S.size() == 0)
        T = max (T,P[i].F);
        /*if (X > I){
            Q.insert ({max (P[i].F,t), I});
            t = max (P[i].F,t) + 1;
            QQ.insert (I);
            X = I;
        }
        else {*/
            S.insert (I);
        //}
        if (S.size() > 0){
            int x = (*S.begin());
            if (x <= X){
                Q.insert ({max (T, t), x});
                t = max (T, t) + 1;
                QQ.insert (x);
                X = x;
                S.erase (x);
            }
        }
    }
    while (Q.size() > 0){
        auto it = Q.begin();
        T += p;
        ans[(*it).S] = T;
        QQ.erase ((*it).S);
        Q.erase (it);
        X = n + 1;
        if (QQ.size() > 0){
            X = (*QQ.begin());
        }
        if (S.size() > 0){
            int x = (*S.begin());
            if (x <= X){
                Q.insert ({max (T,t), x});
                t = max (t, T) + 1;
                QQ.insert (x);
                X = x;
                S.erase (x);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}