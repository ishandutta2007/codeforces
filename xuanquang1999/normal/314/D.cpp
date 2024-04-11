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
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define oo 2000000007
#define EPS 1e-9
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()

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

int n;
ll minL[maxN], minR[maxN], maxL[maxN], maxR[maxN];
pair<ll, ll> p[maxN];

bool Check(ll d) {
//    debug(d);
    int l = 1;
    fto(r, 1, n) {
        while (p[r].x-p[l].x > d) l++;
        ll minY = min(minL[l-1], minR[r+1]), maxY = max(maxL[l-1], maxR[r+1]);
        if (maxY-minY <= d) return true;
    }
    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int x, y; scanf("%d%d", &x, &y);
        p[i] = mp(x-y, x+y);
    }

    sort(p+1, p+n+1);

//    fto(i, 1, n) printf("%d %d\n", p[i].x, p[i].y);
    minL[0] = oo; maxL[0] = -oo;
    fto(i, 1, n) {
        minL[i] = min(minL[i-1], p[i].y);
        maxL[i] = max(maxL[i-1], p[i].y);
    }
    minR[n+1] = oo; maxR[n+1] = -oo;
    fdto(i, n, 1) {
        minR[i] = min(minR[i+1], p[i].y);
        maxR[i] = max(maxR[i+1], p[i].y);
    }

    ll l = 0, r = (ll)oo*2, res = r+1;
    while (l <= r) {
        ll mid = (l+r)/2;
        if (Check(mid)) {
            res = min(res, mid);
            r = mid-1;
        }
        else l = mid+1;
    }

    printf("%.9g", res/2.0);

    return 0;
}