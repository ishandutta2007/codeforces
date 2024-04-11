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

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int q, x, y;
vector<int> v[maxN];

int Work(int i, int p) {
    v[p].pb(i);

    int t = upper_bound(v[p].begin(), v[p].end(), i-1)-upper_bound(v[p].begin(), v[p].end(), i-y-1);
//    printf("%d %d %d\n", i, p, t);
    return (t == 0);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &q);
    fto(i, 1, q) {
        scanf("%d%d", &x, &y);
        int lim = sqrt(x), ans = 0;
        fto(p, 1, lim) {
            if (x%p == 0) {
                ans += Work(i, p);
                if (p*p != x) ans += Work(i, x/p);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}