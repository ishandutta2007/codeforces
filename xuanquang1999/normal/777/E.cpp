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
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct block {int a, b, h, id;};
bool cmp(const block &a, const block &b) {return (a.b > b.b) || (a.b == b.b && a.a > b.a);}

int n;
block a[maxN];
ll f[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].h), a[i].id = i;
    sort(a+1, a+n+1, cmp);

    map<int, ll> m;
    m[0] = 0;
    fto(i, 1, n) {
        ll x = (--m.lower_bound(a[i].b))->ss;
        f[i] = x+a[i].h;
        while (true) {
            map<int, ll>::iterator it = m.lower_bound(a[i].a);
            if (it == m.end() || f[i] < it->ss) break;
            m.erase(it);
        }
        m[a[i].a] = f[i];
//        debug(i);
//        forit(it, m) printf("%d %lld\n", it->ff, it->ss);
    }

    printf("%lld", *max_element(f+1, f+n+1));

    return 0;
}