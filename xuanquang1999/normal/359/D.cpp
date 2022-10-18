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
#define maxN 300005
#define maxK 20
#define MOD 1000000007

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

int GCD(int a, int b) {return (b == 0) ? a : GCD(b, a%b);}

int n, k, a[maxN], b[maxK][maxN], maxL;
set<int> ans;

int build() {
    fto(j, 1, n) b[0][j] = a[j];
    fto(i, 1, k) {
        fto(j, 1, n-(1<<i)+1) b[i][j] = GCD(b[i-1][j], b[i-1][j+(1<<(i-1))]);
    }
}

int query(int l, int r) {
    int i = log2(r-l+1);
    return GCD(b[i][l], b[i][r-(1<<i)+1]);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
//    printf("%d %d\n", 3+(1<<(2-1)), 3+1<<(2-1));
    scanf("%d", &n);
    k = log2(n);
    fto(i, 1, n) scanf("%d", &a[i]);

    build();
//    fto(l, 1, n) {
//        fto(r, l, n) printf("%d ", query(l, r));
//        puts("");
//    }
    maxL = -1;
    fto(i, 1, n) {
        int lo = 1, hi = i, l = i;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (query(mid, i)%a[i] == 0) {
                l = min(l, mid);
                hi = mid-1;
            }
            else lo = mid+1;
        }
        lo = i, hi = n;
        int r = i;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (query(i, mid)%a[i] == 0) {
                r = max(r, mid);
                lo = mid+1;
            }
            else hi = mid-1;
        }
        if (r-l > maxL) {
            maxL = r-l;
            ans.clear(); ans.insert(l);
        }
        else if (r-l == maxL) ans.insert(l);

//        printf("%d %d %d\n", i, l, r);
    }

    printf("%d %d\n", ans.size(), maxL);
    forit(it, ans) printf("%d ", *it);

    return 0;
}