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
#define maxK 25
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

int n, k, a[maxN], b[maxN], fa[maxK][maxN], fb[maxK][maxN];

void buildFA() {
    fto(j, 1, n) fa[0][j] = a[j];
    fto(i, 1, k) {
        fto(j, 1, n-(1<<i)+1) fa[i][j] = max(fa[i-1][j], fa[i-1][j+(1<<(i-1))]);
    }
}

int queryFA(int l, int r) {
    int i = log2(r-l+1);
    return max(fa[i][l], fa[i][r-(1<<i)+1]);
}

void buildFB() {
    fto(j, 1, n) fb[0][j] = b[j];
    fto(i, 1, k) {
        fto(j, 1, n-(1<<i)+1) fb[i][j] = min(fb[i-1][j], fb[i-1][j+(1<<(i-1))]);
    }
}

int queryFB(int l, int r) {
    int i = log2(r-l+1);
    return min(fb[i][l], fb[i][r-(1<<i)+1]);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n) scanf("%d", &b[i]);

    k = log2(n);
    buildFA();
    buildFB();

    ll ans = 0;
    fto(l, 1, n) {
//        debug(l);
        int lo = l, hi = n, r2 = lo-1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (queryFA(l, mid) <= queryFB(l, mid)) {
                r2 = max(r2, mid);
                lo = mid+1;
            }
            else hi = mid-1;
        }

        lo = l, hi = n;
        int r1 = hi+1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (queryFA(l, mid) >= queryFB(l, mid)) {
                r1 = min(r1, mid);
                hi = mid-1;
            }
            else lo = mid+1;
        }
//        printf("%d %d\n", r1, r2);
        ans += r2-r1+1;
    }

    cout << ans;

    return 0;
}