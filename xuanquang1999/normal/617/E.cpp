//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define maxX 1048576
#define BASE 316
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}
struct query {int l, r, id, bl;};
bool cmp(const query &a, const query &b) {
    if (a.bl < b.bl) return true;
    if (a.bl > b.bl) return false;
    return (a.bl&1) ? (a.r < b.r) : (a.r > b.r);
}

int n, m, k, a[maxN], cnt[maxX];
ll cur, ans[maxN];
query q[maxN];

void inc(int x) {
    cur += cnt[k^x];
    ++cnt[x];
}

void dec(int x) {
    --cnt[x];
    cur -= cnt[k^x];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, n) scanf("%d", &a[i]), a[i] ^= a[i-1];
    fto(i, 1, m) {
        int l, r; scanf("%d%d", &l, &r); --l;
        q[i] = {l, r, i, l/BASE};
    }
    sort(q+1, q+m+1, cmp);
//    fto(i, 1, n) printf("%d ", a[i]);
//    puts("");

    int l = 0, r = -1;
    cur = 0;
    fto(i, 1, m) {
        while (l < q[i].l) dec(a[l++]);
        while (l > q[i].l) inc(a[--l]);
        while (r < q[i].r) inc(a[++r]);
        while (r > q[i].r) dec(a[r--]);
        ans[q[i].id] = cur;
    }

    fto(i, 1, m) printf("%lld\n", ans[i]);

    return 0;
}