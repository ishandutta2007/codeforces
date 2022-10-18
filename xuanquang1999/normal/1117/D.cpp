#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define y1 ipanhefioaenf

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

const int MOD = 1000000007;

struct matrix {
    int n, m;
    vector<vector<int> > a;
    matrix(int n, int m): n(n), m(m) {
        a.assign(n, vector<int>(m, 0));
    }
};

matrix mul(matrix a, matrix b) {
    matrix c(a.n, b.m);
    fto(i, 0, a.n-1) {
        fto(j, 0, b.m-1) {
            fto(k, 0, a.m-1)
                c.a[i][j] = (c.a[i][j] + 1LL * a.a[i][k] * b.a[k][j]) % MOD;
        }
    }
    return c;
}

matrix identity(int n) {
    matrix res(n, n);
    fto(i, 0, n-1)
        res.a[i][i] = 1;
    return res;
}

matrix pow(matrix a, ll n) {
    matrix ans = identity(a.n);
    while (n > 0) {
        if (n&1) ans = mul(ans, a);
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

ll n;
int m;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> m;
    if (n < m) {
        puts("1");
        return 0;
    }

    matrix dp(m, 1);
    fto(i, 0, m-1)
        dp.a[i][0] = 1;

    matrix f(m, m);
    f.a[0][0] = f.a[0][m-1] = 1;
    fto(i, 1, m-1)
        f.a[i][i-1] = 1;

    f = pow(f, n-m+1);
    dp = mul(f, dp);

    cout << dp.a[0][0];

    return 0;
}