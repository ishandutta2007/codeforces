//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 55
#define MOD 1000003

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct matrix {
    vector<vector<ll> > a;
    int m, n;

    matrix(int _m, int _n) {
        m = _m; n = _n;
        a.resize(m+1);
        fto(i, 1, m) a[i].resize(n+1);
    }
    void read() {
        fto(i, 1, m) {
            fto(j, 1, n) scanf("%lld", &a[i][j]);
        }
    }
    bool inline operator == (const matrix &o) const {
        if (m != o.m || n != o.n) return false;
        fto(i, 1, m) {
            fto(j, 1, n) {
                if (a[i][j] != o.a[i][j]) return false;
            }
        }
        return true;
    }
    void inline operator = (const matrix &o) {
        m = o.m; n = o.n;
        fto(i, 1, m) {
            fto(j, 1, n) a[i][j] = o.a[i][j];
        }
    }

    matrix inline operator * (const matrix &o) const {
        matrix c(m, o.n);
        fto(i, 1, m) {
            fto(j, 1, o.n) {
                c.a[i][j] = 0;
                fto(k, 1, n) c.a[i][j] = (c.a[i][j]+a[i][k]*o.a[k][j])%MOD;
            }
        }
        return c;
    }
    void print() {
        fto(i, 1, m) {
            fto(j, 1, n) printf("%lld ", a[i][j]);
            puts("");
        }
        puts("");
    }
};

matrix matPow(matrix A, int n) {
    if (n == 1) return A;
    if (n%2 == 1) return A*matPow(A, n-1);
    matrix B = matPow(A, n/2);
    return B*B;
}

int n, H, W;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &W, &H);
    n += 1;
    matrix A(W+1, W+1);
    fto(i, 1, W) A.a[i][i+1] = 1;
    A.a[W+1][W+1] = 1;
    fdto(j, W, 1) A.a[W+1][j] = (A.a[W+1][j+1]*H)%MOD;

    matrix F(W+1, 1);
    F.a[1][1] = 1;
    fto(i, 2, W+1) {
        //F.a[i][1] = 1;
        int p = 1;
        fdto(j, i-1, 1) {
            F.a[i][1] = (F.a[i][1]+F.a[j][1]*p)%MOD;
            p = (p*H)%MOD;
        }
    }

    if (n <= W) cout << F.a[n+1][1];
    else cout << (matPow(A, n-W)*F).a[W+1][1];

    return 0;
}