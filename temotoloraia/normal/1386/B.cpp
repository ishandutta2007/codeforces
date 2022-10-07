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


const int N = 200005;

int A, B, C;
int nn, x[N], y[N];
bool fix[N];

int rad00, rad0, rad1;
int cnt;

map < pair < int, int >, int > M;

multiset < double > P, Q;
multiset < double >::iterator I1, I2;

void add (int ind){
    if (x[ind] == 0 && y[ind] == 0){
        rad00++;
        return;
    }
    cnt += M[{-x[ind], -y[ind]}];
    M[{x[ind], y[ind]}]++;
    if (x[ind] == 0){
        if (y[ind] > 0)
            rad0++;
        else
            rad1++;
        return;
    }
    double k = y[ind];
    k /= x[ind];
    if (x[ind] > 0){
        P.insert (k);
        return;
    }
    if (x[ind] < 0){
        Q.insert (k);
        return;
    }
}

void rem (int ind){
    if (x[ind] == 0 && y[ind] == 0){
        rad00--;
        return;
    }
    cnt -= M[{-x[ind], -y[ind]}];
    M[{x[ind], y[ind]}]--;
    if (x[ind] == 0){
        if (y[ind] > 0)
            rad0--;
        else
            rad1--;
        return;
    }
    double k = y[ind];
    k /= x[ind];
    if (x[ind] > 0){
        P.erase (P.find (k));
        return;
    }
    if (x[ind] < 0){
        Q.erase (Q.find (k));
        return;
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> A >> B >> C;
    int qq;
    cin >> qq;
    int sw = 0;
    if (A)
        sw = 1;
    else if (B)
        sw = 2;
    else if (C)
        sw = 3;
    if (sw == 2)
        swap (A, B);
    if (sw == 3)
        swap (A, C);
    while (qq--){
        char ch;
        cin >> ch;
        if (ch == 'A'){
            int a, b, c;
            cin >> a >> b >> c;
            if (sw == 2)
                swap (a, b);
            if (sw == 3)
                swap (a, c);
            nn++;
            fix[nn] = 1;
            x[nn] = a * B - b * A;
            y[nn] = a * C - c * A;
            int D = __gcd (abs (x[nn]), abs (y[nn]));
            if (D == 0)D = 1;
            x[nn] /= D;
            y[nn] /= D;
            add (nn);
        }
        else {
            int id;
            cin >> id;
            fix[id] = 0;
            rem (id);
        }
        if (rad00){
            cout << 1 << endl;
            continue;
        }
        if (cnt){
            cout << 2 << endl;
            continue;
        }
        if ((int)P.size() == 0 || (int)Q.size() == 0){
            cout << 0 << endl;
            continue;
        }
        I1 = P.begin();
        I2 = Q.end();
        I2--;
        if ((*I1) > (*I2) && rad1 == 0){
            cout << 0 << endl;
            continue;
        }
        I1 = Q.begin();
        I2 = P.end();
        I2--;
        if ((*I1) > (*I2) && rad0 == 0){
            cout << 0 << endl;
            continue;
        }
        cout << 3 << endl;
    }
}