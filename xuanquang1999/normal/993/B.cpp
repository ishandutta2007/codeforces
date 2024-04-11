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
#define maxN 100005
#define MOD 1000
#define oo 1000000007
#define sz(a) (int)a.size()
#define y1 ejkbaefbkj

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

int n, m, x1[maxN], y1[maxN], x2[maxN], y2[maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        scanf("%d%d", &x1[i], &y1[i]);
        if (x1[i] > y1[i]) swap(x1[i], y1[i]);
    }
    fto(i, 1, m) {
        scanf("%d%d", &x2[i], &y2[i]);
        if (x2[i] > y2[i]) swap(x2[i], y2[i]);
    }

    set<int> sCom;
    set<int> s1[maxN], s2[maxN];

    fto(i, 1, n) {
        fto(j, 1, m) {
            map<int, int> m;
            ++m[x1[i]];
            ++m[y1[i]];
            ++m[x2[j]];
            ++m[y2[j]];
            if (m.size() == 3) {
                for(ii p: m) {
                    if (p.ss == 2) {
                        int x = p.ff;
                        sCom.insert(x);
                        s1[i].insert(x);
                        s2[j].insert(x);
                    }
                }
            }
        }
    }

//    for(ii p: ans) printf("%d %d\n", p.ff, p.ss);

    if (sz(sCom) == 1) {
        printf("%d ", (*sCom.begin()));
    } else {
        bool ok = true;
        fto(i, 1, n) {
            if (sz(s1[i]) > 1) ok = false;
        }
        fto(j, 1, m) {
            if (sz(s2[j]) > 1) ok = false;
        }
        puts((ok) ? "0" : "-1");
    }

    return 0;
}