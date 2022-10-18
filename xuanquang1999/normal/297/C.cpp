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

int n, a[maxN], b[maxN];
ii s[maxN];
set<int> p;

void setValue(int i, int x) {
    a[s[i].ss] = x;
    b[s[i].ss] = s[i].ff-x;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &s[i].ff), s[i].ss = i;
    sort(s+1, s+n+1);
    int i = (n+2)/3+1, cur = s[i].ff;

    fto(j, 1, i-1) setValue(j, 0);
    while (i <= n && cur >= 0) {
        setValue(i, cur);
        p.insert(s[i].ff-cur);
        --cur;
        ++i;
    }

    if (i <= n) {
        cur = s[i].ff-1;
        while (i <= n) {
            while (p.find(s[i].ff-cur) != p.end()) --cur;
            setValue(i, cur);
            p.insert(s[i].ff-cur);
            --cur;
            ++i;
        }
    }

    puts("YES");
    fto(i, 1, n) printf("%d ", a[i]);
    puts("");
    fto(i, 1, n) printf("%d ", b[i]);
    puts("");

    return 0;
}