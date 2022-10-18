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
#define oo 3000000000000000000LL

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

int n, q, a[maxN], b[maxN], maxB[maxN];
vector<int> v[maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d%d", &a[i], &b[i]);
        maxB[a[i]] = max(maxB[a[i]], b[i]);
        v[a[i]].pb(b[i]);
    }
    set<ii> s;
    fto(i, 1, n) {
        sort(v[i].begin(), v[i].end());
        if (maxB[i] > 0) s.insert(mp(maxB[i], i));
    }

    scanf("%d", &q);

    fto(iq, 1, q) {
        int k; scanf("%d", &k);
        vector<int> r(k);
        fto(i, 0, k-1) {
            scanf("%d", &r[i]);
            if (maxB[r[i]] > 0) s.erase(mp(maxB[r[i]], r[i]));
        }

        if (s.empty()) printf("0 0\n");
        else {
            int p = s.rbegin()->ss;
            if (s.size() == 1) printf("%d %d\n", p, v[p][0]);
            else {
                int b = (++s.rbegin())->ff;
                int x = *lower_bound(v[p].begin(), v[p].end(), b);
                printf("%d %d\n", p, x);
            }
        }

        fto(i, 0, k-1) {
            if (maxB[r[i]] > 0) s.insert(mp(maxB[r[i]], r[i]));
        }
    }

    return 0;
}