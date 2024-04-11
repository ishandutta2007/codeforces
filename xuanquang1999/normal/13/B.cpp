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

struct pt {
    ll x, y;
    void read() {cin >> x >> y;}
    void print() {printf("(%lld, %lld)\n", x, y);}
    bool operator == (pt p) {return (x == p.x && y == p.y);}
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    ll operator * (pt p) {return x*p.y - y*p.x;}
    ll operator % (pt p) {return x*p.x + y*p.y;}
};

int nTest;
pt p[3][2];

bool haveCommon() {
    fto(i, 0, 2) {
        fto(j, i+1, 2) {
            fto(x, 0, 1) {
                fto(y, 0, 1) {
                    if (p[i][x] == p[j][y]) {
                        if (x == 1) swap(p[i][0], p[i][1]);
                        if (y == 1) swap(p[j][0], p[j][1]);
                        fto(z, 0, 1) {
                            swap(p[0][z], p[i][z]);
                            swap(p[1][z], p[j][z]);
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

double mag(pt p) {return hypot(p.x, p.y);}

ll sq(pt p) {return p.x*p.x + p.y*p.y;}

bool isAcute(pt a, pt o, pt b) {
    pt oa = a-o, ob = b-o;
    ll x = oa%ob;
    return (0 <= x && x < mag(oa)*mag(ob) && oa*ob != 0);
}

bool onSegment(pt a, pt b, pt p) {
    pt pa = a-p, pb = b-p;
    return (pa*pb == 0 && pa%pb <= 0);
}

bool isProperDivided(pt a, pt b, pt p) {
    if (!onSegment(a, b, p))
        return false;

//    a.print();
//    b.print();
//    p.print();

    pt ap = p-a, ab = b-a;
    ll x = ap%ab, ab2 = sq(ab);
//    debug(x);

    return (ab2 <= 5*x && 5*x <= 4*ab2);
}

bool Solve() {
    if (!haveCommon())
        return false;
    if (!isAcute(p[0][1], p[0][0], p[1][1]))
        return false;
//    fto(i, 0, 2) {
//        fto(j, 0, 1) printf("(%lld, %lld) ", p[i][j].x, p[i][j].y);
//        puts("");
//    }

    fto(z, 0, 1)
        if (isProperDivided(p[0][0], p[0][1], p[2][z]) && isProperDivided(p[1][0], p[1][1], p[2][1-z]))
            return true;
    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        fto(i, 0, 2)
            fto(j, 0, 1)
                p[i][j].read();

        puts(Solve() ? "YES" : "NO");
    }


    return 0;
}