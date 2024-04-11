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
const double EPS = 1e-9;

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
    double x, y;
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (double k) {return {x*k, y*k};}
    pt operator / (double k) {return {x/k, y/k};}
    double operator * (pt p) {return x*p.y - y*p.x;}
    double operator | (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream &is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream &os, pt &p) {
        os << "(" << p.x << " " << p.y << ")";
        return os;
    }
};

pt perp(pt v) {return {-v.y, v.x};}

double sq(pt v) {return v|v;}

double tangentsPolar(pt o1, double r1, pt o2, double r2, bool inner, int sgn) {
    if (inner) r2 = -r2;
    pt d = o2 - o1;
    double dr = r1 - r2, d2 = sq(d), h2 = d2 - dr*dr;
    pt v = (d*dr + perp(d)*sqrt(h2)*sgn)/d2;
    pt p1 = o1 + v*r1, p2 = o2 + v*r2;
    double x = (p1.x - p2.x)*sgn, y = (p1.y - p2.y)*sgn;
//    cout << "x, y: " << x << " " << y << endl;
    return atan2(y, x);
}

struct Event {
    double polar;
    bool open;
    bool operator < (const Event &rhs) const {
        return polar < rhs.polar;
    }
};

bool cmp(Event e, double polar) {
    return e.polar <= polar;
}

const int MAXN = 1005;

int n, k;
pt o[MAXN];
double r[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> k;
    fto(i, 0, n-1)
        cin >> o[i] >> r[i];

    int maxCir = 1;
    fto(i, 0, n-1) {
        vector<Event> events;
//        debug(i);
        fto(j, 0, n-1) {
            if (i == j) continue;
            for(int sgn : {-1, 1}) {
                double lo = tangentsPolar(o[i], r[i], o[j], r[j], false, sgn);
                double hi = tangentsPolar(o[i], r[i], o[j], r[j], true, sgn);
                if (sgn == 1)
                    swap(lo, hi);
//                cout << i << " " << j << " " << lo << " " << hi << endl;
                if (lo < hi) {
                    events.pb({lo, true});
                    events.pb({hi, false});
                } else {
                    events.pb({lo, true});
                    events.pb({PI, false});
                    events.pb({-PI, true});
                    events.pb({hi, false});
                }
            }
        }

        sort(events.begin(), events.end());
//        for(Event e: events)
//            cout << e.open << " " << e.polar << endl;

        int cnt = 1, j = 0;
        for(Event e: events) {
            while (j < sz(events) && cmp(events[j], e.polar)) {
                cnt += (events[j].open) ? 1 : -1;
                ++j;
            }
//            debug(cnt);
            maxCir = max(maxCir, cnt);
        }
//        debug(maxCir);
    }

//    debug(maxCir);
    cout << 1 + 1LL*k*(k+1)/2 + 1LL*(k+1)*(maxCir-1) + (n - maxCir);

    return 0;
}