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

int GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a%b);
}

struct pt {
    ll x, y;
    void read() {cin >> x >> y;}
    pt operator + (pt &p) {return {x + p.x, y + p.y};}
    pt operator - (pt &p) {return {x - p.x, y - p.y};}
    ll operator * (pt &p) {return x*p.y - y*p.x;}
    ll operator % (pt &p) {return x*p.x + y*p.y;}
};

struct line {
    pt v; ll c;
    int i, j;

    line(pt p, pt q, int i, int j): v(q-p), c(v*p), i(i), j(j) {}
    ll side(pt &p) {return v*p - c;}
};

bool half(pt p) {
    return (p.y > 0 || (p.y == 0 && p.x < 0));
}

bool cmpAngle(line &a, line &b) {
    return make_tuple(half(a.v), 0) < make_tuple(half(b.v), a.v * b.v);
}

const int MAXN = 2000 + 5;

int n, pInd[MAXN], pPos[MAXN];
pt p[MAXN];
vector<line> c;

bool cmpSide(const int &i, const int &j) {
    return c[0].side(p[i]) < c[0].side(p[j]);
}

int C2(int x) {return x*(x+1)/2;}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) p[i].read();

    fto(i, 1, n)
        fto(j, 1, n)
            if (i != j) c.pb(line(p[i], p[j], i, j));

    sort(c.begin(), c.end(), cmpAngle);

    fto(i, 1, n) pInd[i] = i;
    sort(pInd+1, pInd+n+1, cmpSide);
    fto(i, 1, n)
        pPos[pInd[i]] = i;

    ll ans = 0;
    int lastI = -1, lastJ = -1;

    stack<ii> st;
    fto(i, 0, sz(c)-1) {
        line l = c[i];
        if (i > 0 && cmpAngle(c[i-1], l)) {
            while (!st.empty()) {
                int i = st.top().first, j = st.top().second; st.pop();
                if (l.side(p[i]) > l.side(p[j])) {
                    swap(pInd[pPos[i]], pInd[pPos[j]]);
                    swap(pPos[i], pPos[j]);
                }
            }
        }

        if (l.i < l.j) {
            int cntR = min(pPos[l.i], pPos[l.j])-1, cntL = n-cntR-2;
            ans += 1LL*C2(cntL-1)*C2(cntR-1);;
        }

        if (pPos[l.i] > pPos[l.j])
            st.push({l.j, l.i});
        else
            st.push({l.i, l.j});
    }

    cout << ans;

    return 0;
}