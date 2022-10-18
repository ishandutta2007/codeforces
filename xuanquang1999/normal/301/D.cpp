//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define maxN 200005
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

struct BIT {
private: vector<int> t;
public:
    BIT(int n) {t.assign(n+1, 0);}
    void update(int p, int x) {
        for(int i = p; i < t.size(); i += i&(-i)) t[i] += x;
    }
    int query(int p) {
        int res = 0;
        for(int i = p; i > 0; i -= i&(-i)) res += t[i];
        return res;
    }
};

struct query {int l, r, id;};
bool cmpQ(const query &a, const query &b) {
    return a.l > b.l;
}

int n, m, pos[maxN], ans[maxN];
vector<ii> s;
vector<query> Q;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        int x; scanf("%d", &x);
        pos[x] = i;
    }

    fto(i, 1, n) {
        for(int j = i; j <= n; j += i) {
            int l = pos[i], r = pos[j];
            if (l > r) swap(l, r);
            s.pb(mp(l, r));
        }
    }

    sort(s.begin(), s.end());

    fto(i, 1, m) {
        int l, r;
        scanf("%d%d", &l, &r);
        Q.pb({l, r, i});
    }
    sort(Q.begin(), Q.end(), cmpQ);

    int i = sz(s)-1;
    BIT t(n);
    for(query q: Q) {
        while (i >= 0 && s[i].ff >= q.l) {
            t.update(s[i].ss, 1);
            --i;
        }
        ans[q.id] = t.query(q.r);
    }

    fto(i, 1, m) printf("%d\n", ans[i]);

    return 0;
}