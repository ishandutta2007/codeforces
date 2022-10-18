//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cerr << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cerr << a[i] << " "; cout << endl
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
#define maxN 205
#define MOD 1000
#define oo 1000000000000000007LL
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
    int n, m;
    vector<vector<ll> > a;
    matrix(int n, int m): n(n), m(m) {
        a.assign(n, vector<ll>(m, -oo));
    }
};

matrix mul(matrix A, matrix B) {
    matrix C(A.n, B.m);
    fto(i, 0, C.n-1) {
        fto(j, 0, C.m-1) {
            fto(k, 0, A.m-1) C.a[i][j] = max(C.a[i][j], A.a[i][k]+B.a[k][j]);
        }
    }
    return C;
}

matrix power(matrix A, ll n) {
    if (n == 1) return A;
    if (n%2 == 1) return mul(A, power(A, n-1));
    matrix P = power(A, n/2);
    return mul(P, P);
}

const int K = 26;

struct Vertex {
    int nxt[K];
    int p;
    char pch;
    int go[K];
    int sum = -1;
    int h = 0;
    int link = -1;
    Vertex(int p = -1, char ch = '$'): p(p), pch(ch) {
        fill(begin(nxt), end(nxt), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

int add_string(string s, int h) {
    int v = 0;
    fto(i, 0, sz(s)-1) {
        int c = s[i]-'a';
        if (t[v].nxt[c] == -1) {
            t[v].nxt[c] = t.size();
            t.pb(Vertex(v, c));
        }
        v = t[v].nxt[c];
    }
    t[v].h += h;
}

int go(int v, int c);

int get_link(int v) {
    int &res = t[v].link;
    if (res == -1) {
        if (v == 0 || t[v].p == 0) res = 0;
        else res = go(get_link(t[v].p), t[v].pch);
    }
    return res;
}

int go(int v, int c) {
    int &res = t[v].go[c];
    if (res == -1) {
        if (t[v].nxt[c] != -1) res = t[v].nxt[c];
        else if (v == 0) res = 0;
        else res = go(get_link(v), c);
    }
    return res;
}

int get_sum(int v) {
    int &res = t[v].sum;
    if (res == -1) {
        if (v == 0) res = 0;
        else res = t[v].h + get_sum(get_link(v));
    }
    return res;
}

int n, k, a[maxN];
string s[maxN];
ll l;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> l;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n) cin >> s[i];

    fto(i, 1, n) add_string(s[i], a[i]);

    k = sz(t);
    matrix A(k, 1);
    A.a[0][0] = 0;

    matrix F(k, k);

    fto(i, 0, k-1) {
        fto(c, 0, K-1) {
            int j = go(i, c);
            F.a[j][i] = max(F.a[j][i], (ll)get_sum(j));
        }
    }

    A = mul(power(F, l), A);

    ll ans = -oo;
    fto(i, 0, k-1) ans = max(ans, A.a[i][0]);
    cout << ans << endl;

    return 0;
}