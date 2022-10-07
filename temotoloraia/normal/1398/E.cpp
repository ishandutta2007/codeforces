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
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;


const int N = 205, INF = 1e12;

int sa, sb, sA, sB;

multiset < int > a, b;

multiset < int > A, B;


void solve () {
    int Q;
    cin >> Q;
    while (Q--){
        int t, d;
        cin >> t >> d;
        if (t == 1){
            if (d > 0){
                a.insert (d);
                sa += d;
                A.insert (d);
                sA += d;
                auto it = A.begin();
                sA -= (*it);
                sB += (*it);
                B.insert ((*it));
                A.erase (it);
            }
            else {
                d = -d;
                a.erase (a.find (d));
                sa -= d;
                if (A.find (d) != A.end()){
                    A.erase (A.find (d));
                    sA -= d;
                }
                else {
                    B.erase (B.find (d));
                    sB -= d;
                }
            }
        }
        else {
            if (d > 0){
                b.insert (d);
                sb += d;
                A.insert (d);
                sA += d;
                auto it = A.begin();
                sA -= (*it);
                sB += (*it);
                B.insert ((*it));
                A.erase (it);
            }
            else {
                d = -d;
                b.erase (b.find (d));
                sb -= d;
                if (A.find (d) != A.end()){
                    A.erase (A.find (d));
                    sA -= d;
                }
                else {
                    B.erase (B.find (d));
                    sB -= d;
                }
            }
        }
        int n = (int)a.size(), m = (int)b.size();
        while ((int)A.size() < n){
            auto it = B.end();
            it--;
            sA += (*it);
            sB -= (*it);
            A.insert ((*it));
            B.erase (it);
        }
        while ((int)A.size() > n){
            auto it = A.begin();
            sA -= (*it);
            sB += (*it);
            B.insert ((*it));
            A.erase (it);
        }
        if (n == 0){
            cout << sb << endl;
            continue;
        }
        if (m == 0){
            cout << sa * 2 - (*a.begin()) << endl;
            continue;
        }
        auto it = b.end();
        it--;
        if ((*a.begin()) <= (*it)){
            cout << sA + sa + sb << endl;
            continue;
        }
        cout << sa + sb + sa - (*a.begin()) + (*it) << endl;
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--)
        solve ();
}