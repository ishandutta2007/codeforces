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
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ll n, k, x, a[maxN];
bool _minus[maxN];

void Solve() {
//    pair<ll, int> b;
//    fto(i, 1, n) b[i] = mp(a[i], i);
//    sort(b+1, b+n+1);
//    fto(i, 1, n) cout << a[i] << " ";

    set<pair<ll, int> > s;
    fto(i, 1, n) s.insert(mp(a[i], i));
    fto(i, 1, k) {
        ll c = s.begin()->ff, id = s.begin()->ss;
        s.erase(s.begin());
        s.insert(mp(c+x, id));
        a[id] += x;
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> k >> x;
    fto(i, 1, n) cin >> a[i];

    int cntMinus = 0;
    fto(i, 1, n) {
        if (a[i] < 0) {
            ++cntMinus;
            _minus[i] = true;
            a[i] = -a[i];
        }
    }


    if (cntMinus%2 == 0) {
        ll p = min_element(a+1, a+n+1)-a;
        if (a[p] >= k*x) {
            a[p] -= k*x;
            if (a[p] == 0) _minus[p] = false;
        }
        else {
            ll t = a[p]/x+1;
            a[p] = -(a[p]-t*x);
            _minus[p] ^= true;
            k -= t;
            Solve();
        }
    }
    else Solve();

    fto(i, 1, n) {
        if (_minus[i]) printf("-");
        cout << a[i] << ' ';
    }



    return 0;
}