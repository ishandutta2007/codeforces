#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;

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

const int MAXN = 1e5 + 5;
const double EPS = 1e-9;

struct pt {
    double x, y;
    bool operator < (const pt &p) {return make_tuple(y, x) < make_tuple(p.y, p.x);}
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (double k) {return {x*k, y*k};}
    pt operator / (double k) {return {x/k, y/k};}
    double operator * (pt p) {return x*p.y - y*p.x;}
    double operator | (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream& is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream& os, pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

double sq(pt v) {return v|v;}

double mag(pt v) {return sqrt(sq(v));}

double orient(pt a, pt b, pt c) {return (b-a)*(c-a);}

pt perp(pt v) {return {-v.y, v.x};}

pt piv;
bool cmpPolar(pt &a, pt &b) {
    return (a-piv)*(b-piv) > 0;
}

vector<pt> convexHull(vector<pt> p) {
    int minInd = min_element(p.begin(), p.end()) - p.begin();
    swap(p[0], p[minInd]);

    piv = p[0];
    sort(p.begin()+1, p.end(), cmpPolar);

    vector<pt> h;
    int k;
    for(pt a: p) {
        while ((k = sz(h)) > 1 && orient(h[k-2], h[k-1], a) <= 0) h.pop_back();
        h.pb(a);
    }

    k = sz(h);
    if (k > 2 && orient(h[k-2], h[k-1], h[0]) == 0)
        h.pop_back();

    return h;
}

double encloseRadius(pt a, pt b, pt c) {
    if (((a-c)|(b-c)) <= 0) return mag(a-b)/2;
    if (((a-b)|(c-b)) <= 0) return mag(a-c)/2;
    b = b-a; c = c-a;
    return mag((b*sq(c) - c*sq(b))/(b*c))/2;
}

double calc(vector<pt> p, double r) {
    int n = sz(p);

    double ans = 0;
    fto(i, 0, n-1)
        ans += p[i]*p[(i+1)%n];
    ans = abs(ans)/2;

    fto(i, 0, n-1) {
        double d = mag(p[(i+1)%n] - p[i])/2;
        double h = sqrt(r*r - d*d);
        double tri = h*d;
        double arc = acos(h/r)*r*r;
//        printf("%d %.15g %.15g %.15g %.15g\n", i, d, h, tri, arc);
        ans += arc - tri;
    }

    return ans;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    double R;
    cin >> n >> R;

    vector<pt> p(n);
    fto(i, 0, n-1)
        cin >> p[i];

    p = convexHull(p);
    n = sz(p);

    vector<int> l(n), r(n);

//    for(pt a: p)
//        cout << a << endl;

    set<pdi, greater<pdi> > s;

    fto(i, 0, n-1) {
        l[i] = (i+n-1)%n;
        r[i] = (i+1)%n;
        double x = encloseRadius(p[i], p[l[i]], p[r[i]]);
//        printf("%d %.15g\n", i, x);
        s.insert({x, i});
    }

    vector<bool> avail(n, true);

    while (s.begin()->ff > R) {
        int i = s.begin()->ss; s.erase(s.begin());
        avail[i] = false;

        int a = l[i], b = r[i];
        s.erase({encloseRadius(p[a], p[l[a]], p[r[a]]), a});
        s.erase({encloseRadius(p[b], p[l[b]], p[r[b]]), b});

        r[a] = b;
        l[b] = a;
        s.insert({encloseRadius(p[a], p[l[a]], p[r[a]]), a});
        s.insert({encloseRadius(p[b], p[l[b]], p[r[b]]), b});

//        print(pq);
//        cout << endl;
    }

    vector<pt> ans;
    fto(i, 0, n-1)
        if (avail[i]) ans.pb(p[i]);

//    for(pt p: ans)
//        cout << p << endl;

    cout << setprecision(50) << calc(ans, R) << endl;

    return 0;
}