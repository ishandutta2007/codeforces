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
#define maxN 100005
#define oo 1000000007
#define sz(a) (int)a.size()
#define BASE 317

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

int n;
unordered_set<int> s[maxN];
vector<int> small, large;
ll ans;

bool Find(int x, int y) {
    return (s[x].find(y) != s[x].end());
}

bool Check(int x1, int x2, int y1) {
    int y2 = y1+abs(x1-x2);
    if (Find(x1, y1) && Find(x1, y2) && Find(x2, y1) && Find(x2, y2)) ++ans;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        s[x].insert(y);
    }

    fto(x, 0, maxN-1) {
        if (sz(s[x]) > BASE) large.pb(x);
        else small.pb(x);
    }

    fto(i, 0, sz(large)-1) {
        fto(j, i+1, sz(large)-1) {
            int x1 = large[i], x2 = large[j];
            for (int y: s[x1]) Check(x1, x2, y);
        }
    }

    for(int x1: small) {
        for(int y1: s[x1]) {
            for(int y2: s[x1]) {
                if (y1 < y2) {
                    int x2 = x1-abs(y1-y2);
                    if (x2 >= 0 && sz(s[x2]) > BASE) Check(x1, x2, y1);

                    x2 = x1+abs(y1-y2);
                    if (x2 < maxN) Check(x1, x2, y1);
                }
            }
        }
    }

    cout << ans;

    return 0;
}