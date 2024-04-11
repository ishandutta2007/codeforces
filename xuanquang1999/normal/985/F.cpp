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
#define maxN 200005
#define maxK 20
#define MOD 1000
#define oo 1000000007
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

int n, q, sa[maxN], rnk[2*maxN], lcp[maxN], b[maxK][maxN], s[2*maxN], last[256];
char t[maxN];

void buildSA() {
    fto(i, 0, n-1) rnk[i] = s[i];
    int j = 0;
    while (true) {
        vector<pair<ii, int> > pos(n);
        fto(i, 0, n-1) pos[i] = mp(mp(rnk[i], rnk[i+(1<<j)]), i);
        sort(pos.begin(), pos.end());

        int cnt = 1;
        fto(i, 0, n-1) {
            if (i > 0 && pos[i-1].ff != pos[i].ff) ++cnt;
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
        int j = sa[rnk[i]-1];
        while (s[j+k] == s[i+k]) ++k;
        lcp[rnk[i]-1] = k;
    }
}

void buildTable() {
    fto(j, 0, n-2) b[0][j] = lcp[j];
    fto(i, 1, log2(n-1)) {
        fto(j, 0, n-(1<<i)-1) b[i][j] = min(b[i-1][j], b[i-1][j+(1<<(i-1))]);
    }
}

int getLCP(int x, int y) {
    if (x == y) return n-max(x, y);
    int l = rnk[x], r = rnk[y];
    if (l > r) swap(l, r);
    --r;
    int i = log2(r-l+1);
    return min(b[i][l], b[i][r-(1<<i)+1]);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    scanf("%s", t);

    fdto(i, n-1, 0) {
        if (last[t[i]] == 0) s[i] = n+1;
        else s[i] = last[t[i]]-i;
        last[t[i]] = i;
    }

//    fto(i, 0, n-1) printf("%d ", s[i]);
//    puts("");

    buildSA();
    buildLCP();
    buildTable();

    fto(iq, 1, q) {
        int i, j, len;
        scanf("%d%d%d", &i, &j, &len);
        --i; --j;

//        debug(iq);
//        printf("%d %d %d\n", i, j, len);
        bool ok = true;
        while (len > 0) {
            int k = getLCP(i, j);
//            printf("%d %d %d\n", i, j, k);
            if (k >= len) break;

            int nxtI = i+k, nxtJ = j+k;
            if (s[nxtI]+nxtI <= i+len-1 || s[nxtJ]+nxtJ <= j+len-1) {
                ok = false;
                break;
            }
            i = nxtI+1;
            j = nxtJ+1;
            len -= k+1;
        }

        puts((ok) ? "YES" : "NO");
    }



    return 0;
}