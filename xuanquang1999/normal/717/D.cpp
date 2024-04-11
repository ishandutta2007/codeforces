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
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}


struct matrix {
    vector<vector<double> > a;
    int m, n;

    matrix(int _m, int _n) {
        m = _m; n = _n;
        a.resize(m);
        fto(i, 0, m-1) a[i].resize(n);
    }
    bool inline operator == (const matrix &o) const {
        if (m != o.m || n != o.n) return false;
        fto(i, 0, m-1) {
            fto(j, 0, n-1) {
                if (a[i][j] != o.a[i][j]) return false;
            }
        }
        return true;
    }
    void inline operator = (const matrix &o) {
        m = o.m; n = o.n;
        fto(i, 0, m-1) {
            fto(j, 0, n-1) a[i][j] = o.a[i][j];
        }
    }

    matrix inline operator * (const matrix &o) const {
        matrix c(m, o.n);
        fto(i, 0, m-1) {
            fto(j, 0, o.n-1) {
                c.a[i][j] = 0;
                fto(k, 0, n-1) c.a[i][j] = c.a[i][j]+a[i][k]*o.a[k][j];
            }
        }
        return c;
    }
    void print() {
        fto(i, 0, m-1) {
            fto(j, 0, n-1) printf("%.3f ", a[i][j]);
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

int n, x;
double p[128];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> x;
    fto(i, 0, x) cin >> p[i];

    matrix F(1, 128);
    F.a[0][0] = 1;
    fto(j, 1, 127) F.a[0][j] = 0;

    matrix A(128, 128);
    fto(j, 0, 127) {
        fto(i, 0, 127) A.a[i][j] = p[i^j];
    }
    cout << setprecision(69) << 1-(F*matPow(A, n)).a[0][0];

    return 0;
}