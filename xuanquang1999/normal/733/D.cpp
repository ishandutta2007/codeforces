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

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, a[maxN][3];
map<ii, ii> m;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        fto(j, 0, 2) scanf("%d", &a[i][j]);
        sort(a[i], a[i]+3);
    }

    vector<int> ans;
    ll maxD = 0;
    fto(i, 1, n) {
        ll d = *min_element(a[i], a[i]+3);
        if (d > maxD) {
            maxD = d;
            ans = vector<int>(1, i);
        }
        fto(j, 0, 2) {
            int x = a[i][j], y = a[i][(j+1)%3], z = a[i][(j+2)%3];
            map<ii, ii>::iterator it = m.find(mp(x, y));
            if (it != m.end()) {
                d = min(x, y, z+it->ss.ff);
                if (d > maxD) {
                    maxD = d;
                    ans.clear(); ans.pb(i); ans.pb(it->ss.ss);
                }
            }
        }
        fto(j, 0, 2) {
            int x = a[i][j], y = a[i][(j+1)%3], z = a[i][(j+2)%3];
            map<ii, ii>::iterator it = m.find(mp(x, y));
            if (z > m[mp(x, y)].ff) {
                m[mp(x, y)] = mp(z, i);
            }
        }
    }

    printf("%d\n", ans.size());
    forit(it, ans) printf("%d ", *it);

    return 0;
}