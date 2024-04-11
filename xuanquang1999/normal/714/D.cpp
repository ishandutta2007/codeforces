//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n;
vector<int> ansX1, ansY1, ansX2, ansY2;

int ask(int x1, int y1, int x2, int y2) {
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

bool isIn(int l, int x, int r) {
    return (l <= x && x <= r);
}

void solve() {
    int x1 = 1, y1 = 1, x2 = n, y2 = n;

    int l = x1, r = x2, res = l-1;
    while (l <= r) {
        int mid = (l+r)/2;
        int x = ask(x1, y1, mid, y2);
        fto(i, 0, (int)ansX1.size()-1) {
            if (isIn(x1, ansX1[i], mid) && isIn(x1, ansX2[i], mid) && isIn(y1, ansY1[i], y2) && isIn(y1, ansY2[i], y2)) --x;
        }
        if (x == 0) {
            res = max(res, mid);
            l = mid+1;
        }
        else r = mid-1;
    }
    x2 = res+1;

    l = x1, r = x2, res = r+1;
    while (l <= r) {
        int mid = (l+r)/2;
        int x = ask(mid, y1, x2, y2);
        fto(i, 0, (int)ansX1.size()-1) {
            if (isIn(mid, ansX1[i], x2) && isIn(mid, ansX2[i], x2) && isIn(y1, ansY1[i], y2) && isIn(y1, ansY2[i], y2)) --x;
        }
        if (x == 0) {
            res = min(res, mid);
            r = mid-1;
        }
        else l = mid+1;
    }
    x1 = res-1;

    l = y1, r = y2, res = l-1;
    while (l <= r) {
        int mid = (l+r)/2;
        int x = ask(x1, y1, x2, mid);
        fto(i, 0, (int)ansX1.size()-1) {
            if (isIn(x1, ansX1[i], x2) && isIn(x1, ansX2[i], x2) && isIn(y1, ansY1[i], mid) && isIn(y1, ansY2[i], mid)) --x;
        }
        if (x == 0) {
            res = max(res, mid);
            l = mid+1;
        }
        else r = mid-1;
    }
    y2 = res+1;

    l = y1, r = y2, res = r+1;
    while (l <= r) {
        int mid = (l+r)/2;
        int x = ask(x1, mid, x2, y2);
        fto(i, 0, (int)ansX1.size()-1) {
            if (isIn(x1, ansX1[i], x2) && isIn(x1, ansX2[i], x2) && isIn(mid, ansY1[i], y2) && isIn(mid, ansY2[i], y2)) --x;
        }
        if (x == 0) {
            res = min(res, mid);
            r = mid-1;
        }
        else l = mid+1;
    }
    y1 = res-1;

    ansX1.pb(x1);
    ansY1.pb(y1);
    ansX2.pb(x2);
    ansY2.pb(y2);
//    puts("Rec:");
//    printf("%d %d %d %d\n", x1, y1, x2, y2);
}

int main () {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, 2) solve();

    printf("!");
    fto(i, 0, 1) printf(" %d %d %d %d", ansX1[i], ansY1[i], ansX2[i], ansY2[i]);

    return 0;
}