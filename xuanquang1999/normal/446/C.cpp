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
#define X real()
#define Y imag()
#define maxN 300005
#define oo 2000000007
#define EPS 1e-9
#define MOD 1000000009

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

int add(int &a, const ll &b) {a = (a+b)%MOD;}

int powMod(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return (1LL*x*powMod(x, n-1))%MOD;
    int p = powMod(x, n/2);
    return (1LL*p*p)%MOD;
}

struct Node {
    int sum, prog;
    Node() {sum = prog = 0;}
};

struct IT {
private:
    vector<Node> t;
    int n, base;
    vector<int> sumGeoProg, basePow;

    void propagate(const int &id, const int &l, const int &r) {
        int m = (l+r)/2;
        if (t[id].prog != 0) {
            add(t[2*id].sum, 1LL*t[id].prog*sumGeoProg[m-l+1]);
            add(t[2*id+1].sum, 1LL*t[id].prog*(sumGeoProg[r-l+1]-sumGeoProg[m-l+1]+MOD));
            add(t[2*id].prog, t[id].prog);
            add(t[2*id+1].prog, 1LL*t[id].prog*basePow[m-l+1]);
            t[id].prog = 0;
        }
    }
    void update(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return;
        if (i <= l && r <= j) {
            add(t[id].sum, 1LL*basePow[l-i+1]*sumGeoProg[r-l+1]);
            add(t[id].prog, basePow[l-i+1]);
            return;
        }
        propagate(id, l, r);
        int m = (l+r)/2;
        update(2*id, l, m, i, j); update(2*id+1, m+1, r, i, j);
        t[id].sum = (t[2*id].sum+t[2*id+1].sum)%MOD;
    }
    int query(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return 0;
        if (i <= l && r <= j) return t[id].sum;
        propagate(id, l, r);
        int m = (l+r)/2;
        return (query(2*id, l, m, i, j)+query(2*id+1, m+1, r, i, j))%MOD;
    }
public:
    IT(int n, int base): n(n), base(base) {
        t.assign(4*n+1, Node());

        basePow.assign(n+1, 0);
        sumGeoProg.assign(n+1, 0);
        basePow[0] = 1;
        fto(i, 1, n) {
            basePow[i] = (1LL*basePow[i-1]*base)%MOD;
            sumGeoProg[i] = (sumGeoProg[i-1]+basePow[i-1])%MOD;
        }
    }
    void update(int l, int r) {update(1, 1, n, l, r);}
    int query(int l, int r) {return query(1, 1, n, l, r);}
};

int Fib(int n) {
    return (276601605LL*(powMod(691504013, n)-powMod(308495997, n)+MOD))%MOD;
}

int n, m, a[maxN];
ll d[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &a[i]), d[i] = d[i-1]+a[i];

    //fto(i, 1, 4) debug(Fib(i));

    IT t1(n, 691504013), t2(n, 308495997);
    fto(i, 1, m) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1) {
            t1.update(l, r);
            t2.update(l, r);
        } else {
            ll fSum = 276601605LL*(t1.query(l, r)-t2.query(l, r)+MOD), aSum = d[r]-d[l-1];
            printf("%d\n", (aSum+fSum)%MOD);
        }
    }

    return 0;
}