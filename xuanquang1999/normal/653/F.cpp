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
#define maxN 500005
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

int n, d[maxN], sa[maxN], rnk[2*maxN], lcp[maxN];
vector<int> pos[2*maxN];
char s[maxN];

void buildSA() {
    fto(i, 0, n-1) rnk[i] = s[i];
    int j = 0;
    while (true) {
        vector<pair<ii, int> > pos;
        fto(i, 0, n-1) pos.pb(mp(mp(rnk[i], rnk[i+(1<<j)]), i));
        sort(pos.begin(), pos.end());
        int cnt = 1;
        fto(i, 0, n-1) {
            if (i > 0 && pos[i].ff != pos[i-1].ff) ++cnt;
            rnk[pos[i].ss] = cnt;
        }
        if (cnt == n) break;
        ++j;
    }
    fto(i, 0, n-1) {
        --rnk[i];
        sa[rnk[i]] = i;
    }
}

void buildLCP() {
    int k = 0;
    fto(i, 0, n-1) {
        if (rnk[i] == 0) continue;
        k = max(0, k-1);
        while (s[sa[rnk[i]-1]+k] == s[i+k]) ++k;
        lcp[i] = k;
    }
}

int Count(vector<int> &v, int l, int r) {
    return upper_bound(v.begin(), v.end(), r)-upper_bound(v.begin(), v.end(), l-1);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    scanf("%s", s);

    buildSA();
    buildLCP();

    fto(i, 1, n) d[i] = d[i-1] + ((s[i-1] == '(') ? 1 : -1);
    fto(i, 0, n) pos[d[i]+maxN].pb(i);

//    fto(i, 0, n) printf("%d %d %d\n", sa[i], rnk[i], lcp[i]);

    ll ans = 0;

    stack<int> st;
    fdto(i, n, 0) {
        int lo = i+lcp[i]+1;

        while (!st.empty() && d[st.top()] >= d[i]) st.pop();
        int hi = (st.empty()) ? n : st.top()-1;
        st.push(i);
        if (i < n && lo <= hi) ans += Count(pos[d[i]+maxN], lo, hi);
//        printf("%d %d %d\n", i, lo, hi);
    }

    cout << ans;

    return 0;
}