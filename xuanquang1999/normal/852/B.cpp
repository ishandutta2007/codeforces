//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 1000005
#define maxM 105
#define MOD 1000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct matrix {
    vector<vector<int> > a;
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
                fto(k, 0, n-1) c.a[i][j] = (c.a[i][j]+1LL*a[i][k]*o.a[k][j])%MOD;
            }
        }
        return c;
    }
    void print() {
        fto(i, 0, m-1) {
            fto(j, 0, n-1) printf("%d ", a[i][j]);
            puts("");
        }
        puts("");
    }
};

matrix Identity(int n) {
    matrix I(n, n);
    fto(i, 0, n-1) I.a[i][i] = 1;
    return I;
}

matrix matPow(matrix A, int n) {
    if (n == 0) return Identity(A.m);
    if (n%2 == 1) return A*matPow(A, n-1);
    matrix B = matPow(A, n/2);
    return B*B;
}

int n, l, M, c[3][maxN], dpp[maxM], last[maxM];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &l, &M);
    fto(i, 0, 2) fto(j, 1, n) scanf("%d", &c[i][j]);

    matrix A(1, M);
    fto(i, 1, n) ++A.a[0][c[0][i]%M];

    fto(i, 1, n) ++dpp[c[1][i]%M];

    matrix B(M, M);
    fto(i, 0, M-1) fto(j, 0, M-1) B.a[i][j] = dpp[(j-i+M)%M];

    matrix C = A*matPow(B, l-2);

    fto(i, 1, n) {
        ++last[(c[1][i]+c[2][i])%M];
    }

    int ans = 0;
    fto(i, 0, M-1) {
        ans = (ans+1LL*last[i]*C.a[0][(M-i)%M])%MOD;
    }
    printf("%d", ans);


    return 0;
}