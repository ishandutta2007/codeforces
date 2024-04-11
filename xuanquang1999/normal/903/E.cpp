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
#define maxN 5005
#define oo 2000000007
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

int k, n;
string s[maxN];

bool Try(const string &t) {
    vector<int> cnt(256, 0);
    bool selfSwap = false;
    fto(i, 0, n-1) {
        if (cnt[t[i]]) selfSwap = true;
        ++cnt[t[i]];
    }

//    debug(t);
//    debug(selfSwap);

    fto(i, 0, k-1) {
        vector<int> p;
        fto(j, 0, n-1) {
            if (s[i][j] != t[j]) p.pb(j);
        }
        if (sz(p) == 2) {
            if (s[i][p[0]] != t[p[1]] || s[i][p[1]] != t[p[0]]) return false;
        } else if (sz(p) == 0) {
            if (!selfSwap) return false;
        } else return false;
    }

    cout << t;
    exit(0);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &k, &n);
    fto(i, 0, k-1) cin >> s[i];

    Try(s[0]);

    string t = s[0];
    swap(t[0], t[1]);
    Try(t);

    fto(i, 1, k-1) {
        vector<int> p;
        fto(j, 0, n-1) {
            if (s[0][j] != s[i][j]) p.pb(j);
        }
        if (sz(p) > 4) {
            puts("-1");
            return 0;
        } else {
            fto(a, 0, sz(p)-2) fto(b, a+1, sz(p)-1) {
                t = s[0];
                swap(t[p[a]], t[p[b]]);
                //debug(t);
                Try(t);
            }
        }
    }

    puts("-1");

    return 0;
}