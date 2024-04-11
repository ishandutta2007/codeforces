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

const double PI = acos(-1.0);
const int INF = 1e9;

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

struct pt {
    int x, y, id, orient;
};

bool cmpX(const pt &a, const pt &b) {
    return a.x < b.x;
}

bool cmpY(const pt &a, const pt &b) {
    return a.y < b.y;
}

int sq(int x) {return x*x;}

int sqDist(const pt &p, const pt &q) {
    return sq(p.x - q.x) + sq(p.y - q.y);
}

struct result {
    pt p, q;
    int d;
};

result min(result a, result b) {
    return (a.d < b.d) ? a : b;
}

void update(result &res, const pt &p, const pt &q) {
    int d = sqDist(p, q);
    if (d < res.d)
        res = {p, q, d};
}

result closest(const vector<pt> &p, int l, int r) {
    result res = {p[l], p[r], INF};
    if (r - l <= 3) {
        fto(i, l, r) {
            fto(j, i+1, r) {
                if (p[i].id == p[j].id)
                    continue;
                update(res, p[i], p[j]);
            }
        }
    } else {
        int m = (l+r)/2;
        res = min(res, closest(p, l, m));
        res = min(res, closest(p, m+1, r));

        vector<pt> strip;
        fto(i, l, r)
            if (sq(p[i].x - p[m].x) < res.d)
                strip.pb(p[i]);

        sort(strip.begin(), strip.end(), cmpY);
        int k = sz(strip);
        fto(i, 0, k-1) {
            fto(j, i+1, k-1) {
                if (sq(strip[i].y - strip[j].y) >= res.d) break;
                if (strip[i].id == strip[j].id) continue;
                update(res, strip[i], strip[j]);
            }
        }
    }

    return res;
}

int n;
vector<pt> p;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    fto(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        p.pb({x, y, i, 1});
        p.pb({-x, y, i, 2});
        p.pb({x, -y, i, 3});
        p.pb({-x, -y, i, 4});
    }

    sort(p.begin(), p.end(), cmpX);

    result res = closest(p, 0, sz(p)-1);
    res.q.orient = 5 - res.q.orient;
    printf("%d %d %d %d", res.p.id, res.p.orient, res.q.id, res.q.orient);

    return 0;
}