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

const int MAXN = 2e5+5;
int n, q, a[MAXN];
vector<int> pos[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, n) scanf("%d", &a[i]);

    set<int> s;
    fto(i, 1, n) {
        pos[a[i]].pb(i);
        if (a[i] == 0) s.insert(i);
    }
    s.insert(n+1);

    if (sz(pos[q]) == 0) {
        fto(i, 1, n) {
            if (a[i] == 0) {
                a[i] = q;
                s.erase(i);
                pos[q].pb(i);
                break;
            }
        }
    }

    fdto(x, q, 1) {
        if (sz(pos[x]) == 0) continue;
        int l = pos[x][0], r = pos[x].back();
        while (true) {
            int p = *s.lower_bound(l);
            if (p <= r) {
                s.erase(p);
                a[p] = x;
                pos[x].pb(p);
            } else break;
        }
    }

    while (true) {
        int p = *s.begin();
        if (p <= n) {
            a[p] = 1;
            pos[1].pb(p);
            s.erase(s.begin());
        } else break;
    }

//    fto(i, 1, n) printf("%d ", a[i]);

    fto(x, 1, q) {
        if (sz(pos[x]) == 0) continue;
        int l = pos[x][0], r = pos[x].back();
        if (*s.lower_bound(l) <= r) {
            puts("NO");
            return 0;
        }
        for(int p: pos[x])
            s.insert(p);
    }

    if (*max_element(a+1, a+n+1) == q) {
        puts("YES");
        fto(i, 1, n)
            printf("%d ", a[i]);
    } else
        puts("NO");

    return 0;
}