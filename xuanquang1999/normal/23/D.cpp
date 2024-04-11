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

const double PI = acos(-1.0);
const double EPS = 1e-9;

struct pt {
    double x, y;
    void read() {scanf("%lf%lf", &x, &y);}
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (double k) {return {x*k, y*k};}
    pt operator / (double k) {return {x/k, y/k};}
    double operator * (pt p) {return x*p.y - y*p.x;}
    void print() {printf("(%.15g, %.15g)\n", x, y);}
};

int orient(pt &a, pt &b, pt &c) {
    double x = (c-a)*(b-a);
    return (x > EPS) - (x < -EPS);
}

int mag(pt p) {
    return p.x*p.x + p.y*p.y;
}

pt perp(pt p) {return {-p.y, p.x};}

struct line {
    pt v; double c;
    line(pt p, pt q): v(q-p), c(v*p) {}
};

line perpThrough(pt v, pt p) {return {p, p + perp(v)};}

line parThrough(pt v, pt p) {return {p, p + v};}

line perpBisec(pt a, pt b) {return perpThrough(b-a, (b+a)/2);}

bool isConvex(pt p[]) {
    int sign[4];
    fto(i, 0, 3) {
        sign[i] = orient(p[i], p[(i+1)%4], p[(i+2)%4]);
        if (sign[0] == 0 || sign[i] != sign[0])
            return false;
    }
}

bool inter(line l1, line l2, pt &out) {
    double x = l1.v * l2.v;
    if (abs(x) < EPS)
        return false;
    out = (l2.v*l1.c - l1.v*l2.c)/x;
    return true;
}

bool getTetragon(pt m, pt n, pt p, pt out[]) {
//    printf("m: "); m.print();
//    printf("n: "); n.print();
//    printf("p: "); p.print();
    line bisecMN = perpBisec(m, n), bisecNP = perpBisec(n, p);
    pt o;
    if (!inter(bisecMN, bisecNP, o))
        return false;
//    printf("o: "); o.print();

    line nb = perpThrough(n-m, n);
    pt b; inter(nb, bisecNP, b);
    line nc = perpThrough(p-n, n);
    pt c; inter(nc, bisecMN, c);
//    printf("b: "); b.print();
//    printf("c: "); c.print();

    line de = parThrough(c-b, n);

    inter(de, bisecMN, out[1]);
    inter(de, bisecNP, out[2]);
    out[0] = m*2 - out[1];
    out[3] = p*2 - out[2];

    return isConvex(out);
}

int nTest;
pt c[3];

void Solve() {
    pt p[4];
    fto(i, 0, 2) {
        if (getTetragon(c[i], c[(i+1)%3], c[(i+2)%3], p)) {
            puts("YES");
            fto(i, 0, 3)
                printf("%.15g %.15g ", p[i].x, p[i].y);
            puts("");
            return;
        }
    }

    puts("NO");
    puts("");
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        fto(i, 0, 2)
            c[i].read();

        Solve();
    }

    return 0;
}