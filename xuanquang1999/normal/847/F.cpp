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
#define maxN 105
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

struct cand {
    int cnt, last, id;
};

bool cmp(const cand &a, const cand &b) {
    return (a.cnt > b.cnt) || (a.cnt == b.cnt && a.last < b.last);
}

int n, k, m, a, g[maxN], cnt[maxN], last[maxN], ans[maxN];
cand c[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d", &n, &k, &m, &a);

    fto(i, 1, a) scanf("%d", &g[i]);

    fto(i, 1, a) {
        ++cnt[g[i]];
        last[g[i]] = i;
    }

    fto(i, 1, n) c[i] = {cnt[i], last[i], i};

    sort(c+1, c+n+1, cmp);

//    fto(i, 1, n) printf("%d %d %d\n", c[i].cnt, c[i].last, c[i].id);

    fto(i, 1, n) {
        int cnt = 0;
        fto(j, 1, n) {
            if (j != i && cmp(c[j], {c[i].cnt+m-a, ((a == m) ? c[i].last : m), c[i].id})) ++cnt;
        }

        if (c[i].cnt+m-a == 0 || cnt >= k) {
            ans[c[i].id] = 3;
            continue;
        }

        cnt = 0;

        int sum = m-a;
//        debug(i);
        fto(j, 1, n) {
            if (j != i && cmp(c[j], c[i])) ++cnt;
            else if (j != i && c[i].cnt-c[j].cnt+1 <= sum) {
                sum -= c[i].cnt-c[j].cnt+1;
                ++cnt;
            }
        }
//        debug(cnt);

        if (c[i].cnt > 0 && cnt < k) {
            ans[c[i].id] = 1;
            continue;
        }

        ans[c[i].id] = 2;
    }

    fto(i, 1, n) printf("%d ", ans[i]);

    return 0;
}