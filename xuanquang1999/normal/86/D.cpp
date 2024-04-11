//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 200005
#define maxX 1000005
#define oo 1000000007
#define EPS 1e-9

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, sqrtN;

struct query {
    int l, r, bl, br, id;
};

bool cmp(query a, query b) {
    return (mp(a.bl, a.br) < mp(b.bl, b.br));
}

query q[maxN];
int t, a[maxN], cnt[maxX];
ll power, ans[maxN];

ll sqr(ll x) {
    return x*x;
}

void add(int p) {
    ++cnt[a[p]];
    power += (sqr(cnt[a[p]])-sqr(cnt[a[p]]-1))*a[p];
}

void del(int p) {
    power -= (sqr(cnt[a[p]])-sqr(cnt[a[p]]-1))*a[p];
    --cnt[a[p]];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &t);
    sqrtN = sqrt(n);
    fto(i, 0, n-1) scanf("%d", &a[i]);
    fto(i, 1, t) {
        scanf("%d%d", &q[i].l, &q[i].r);
        --q[i].l; --q[i].r;
        q[i].bl = q[i].l/sqrtN; q[i].br = q[i].r/sqrtN;
        q[i].id = i;
    }
    sort(q+1, q+t+1, cmp);
//    fto(i, 1, t) printf("%d %d\n", q[i].l, q[i].r);
    int curL = n, curR = n-1;
    fto(i, 1, t) {
        while (curL < q[i].l) del(curL++);
        while (curL > q[i].l) add(--curL);
        while (curR < q[i].r) add(++curR);
        while (curR > q[i].r) del(curR--);
        ans[q[i].id] = power;
    }

    fto(i, 1, t) printf("%I64d\n", ans[i]);


    return 0;
}