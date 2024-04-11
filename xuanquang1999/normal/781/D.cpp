//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define maxN 500
#define maxK 61
#define oo 1073741824
#define double long double

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

struct matrix {
    vector<vector<ll> > r, c; int n;
    matrix(int n): n(n) {
        r.assign(n, vector<ll>((n+maxK-1)/maxK, 0));
        c.assign((n+maxK-1)/maxK, vector<ll>(n, 0));
    }
};

void add(matrix &A, int i, int j) {
    A.r[i][j/maxK] |= (1LL<<(j%maxK));
    A.c[i/maxK][j] |= (1LL<<(i%maxK));
}

void printRAW(const matrix &A) {
    fto(i, 0, A.n-1) {
        fto(j, 0, (A.n+maxK-1)/maxK-1) printf("%lld ", A.r[i][j]);
        puts("");
    }
    fto(i, 0, (A.n+maxK-1)/maxK-1) {
        fto(j, 0, A.n-1) printf("%lld ", A.c[i][j]);
        puts("");
    }
}

void print(const matrix &A) {
    fto(i, 0, A.n-1) {
        fto(j, 0, A.n-1) printf("%d ", (A.r[i][j/maxK]>>(j%maxK))&1);
        puts("");
    }
}

matrix Identity(int n) {
    matrix I(n);
    fto(i, 0, n-1) add(I, i, i);
    return I;
}

matrix Mul(const matrix &A, const matrix &B) {
    matrix C(A.n);
//    puts("A");
//    print(A);
//    puts("B");
//    print(B);
    fto(i, 0, C.n-1) {
        fto(j, 0, C.n-1) {
            fto(k, 0, (C.n+maxK-1)/maxK-1) {
//                printf("%d %d %d\n", i, j, k);
                if (A.r[i][k]&B.c[k][j]) {
                    add(C, i, j); break;
                }
            }
        }
    }
    return C;
}

bool ok(matrix &A) {
    //print(A);
    fto(i, 0, (A.n+maxK-1)/maxK-1) {
        if (A.r[0][i] > 0) return true;
    }
    //print(A);
    return false;
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n, m;
    scanf("%d%d", &n, &m);
    vector<matrix> P(maxK, matrix(n)), B(maxK, matrix(n));
    //debug(P[0].n);
    fto(i, 1, m) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t); --u; --v;
        //debug(u);
        if (t == 0) add(P[0], u, v);
        else add(B[0], u, v);
    }
    //return 0;

    fto(i, 1, maxK-1) {
        P[i] = Mul(P[i-1], B[i-1]); B[i] = Mul(B[i-1], P[i-1]);
    }
//    printRAW(P[2]);
//    print(P[2]);
    //return 0;
    int k;
    fto(i, 0, maxK) {
//        debug(i);
        if (i == maxK) {puts("-1"); return 0;}
        if (!ok(P[i])) {
            k = i-1;
            break;
        }
    }
    if (k == -1) {puts("0"); return 0;}
//    debug(k);
//    return 0;
    matrix F = P[k];
    int cur = 1; ll ans = (1LL<<k);
    fdto(i, k-1, 0) {
        matrix T = Mul(F, ((cur) ? B[i] : P[i]));
//        debug(i);
//        print(F);
//        print(F);
//        print(T);
        if (ok(T)) {
            cur ^= 1;
            F = T;
            ans |= (1LL<<i);
        }
    }

    printf("%lld", (ans > 1000000000000000000) ? -1 : ans);

    return 0;
}