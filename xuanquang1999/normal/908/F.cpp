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
#define maxN 300005
#define MOD 1000
#define oo 1000000000000000007LL
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

int n, p[maxN];
char c[maxN];
vector<int> r, g, b;
int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) {
        char s[2];
        scanf("%d%s", &p[i], &s);
        c[i] = s[0];

        if (c[i] == 'R') r.pb(i);
        else if (c[i] == 'G') g.pb(i);
        else b.pb(i);
    }

    int ans = 0;
    if (sz(g) == 0) {
        if (sz(b) > 0) ans += p[b.back()]-p[b.front()];
        if (sz(r) > 0) ans += p[r.back()]-p[r.front()];
    } else {
        int i = 0, j = 0, minR = p[g[0]], minB = p[g[0]];
        while (i < sz(r) && p[r[i]] < p[g[0]]) minR = min(minR, p[r[i++]]);
        while (j < sz(b) && p[b[j]] < p[g[0]]) minB = min(minB, p[b[j++]]);
        ans += 2*p[g[0]]-minR-minB;

        fto(k, 1, sz(g)-1) {
            vector<int> inR, inB;
            inR.pb(g[k-1]);
            while (i < sz(r) && p[r[i]] < p[g[k]]) inR.pb(r[i++]);
            inR.pb(g[k]);

            inB.pb(g[k-1]);
            while (j < sz(b) && p[b[j]] < p[g[k]]) inB.pb(b[j++]);
            inB.pb(g[k]);

            int x1 = 2*(p[g[k]]-p[g[k-1]]);

            int maxInR = 0, maxInB = 0;
            fto(i, 1, sz(inR)-1) maxInR = max(maxInR, p[inR[i]]-p[inR[i-1]]);
            fto(i, 1, sz(inB)-1) maxInB = max(maxInB, p[inB[i]]-p[inB[i-1]]);

            ll x2 = 3LL*(p[g[k]]-p[g[k-1]])-maxInR-maxInB;
            ans += min((ll)x1, x2);
        }

        int maxR = p[g.back()], maxB = p[g.back()];
        while (i < sz(r)) maxR = max(maxR, p[r[i++]]);
        while (j < sz(b)) maxB = max(maxB, p[b[j++]]);

        ans += maxB + maxR - 2*p[g.back()];
    }

    printf("%d", ans);

    return 0;
}