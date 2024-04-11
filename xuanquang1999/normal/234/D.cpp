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
#define maxN 105
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

int n, m, k, minA[maxN], maxA[maxN];
bool fav[maxN];

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &m, &k);
    fto(i, 1, k) {
        int x; scanf("%d", &x);
        fav[x] = true;
    }

    scanf("%d", &n);
    fto(i, 1, n) {
        string s;
        cin >> s;

        int p, cnt0 = 0, cntFav = 0;
        scanf("%d", &p);
        fto(j, 1, p) {
            int x; scanf("%d", &x);
            if (x == 0) ++cnt0;
            else if (fav[x]) ++cntFav;
        }

        maxA[i] = cntFav + min(cnt0, k-cntFav);
        minA[i] = cntFav + max(0, cnt0 - ((m-k) - (p-cntFav-cnt0)));
    }

//    fto(i, 1, n) printf("%d %d\n", minA[i], maxA[i]);

    fto(i, 1, n) {
        int maxO = 0, minO = 0;
        fto(j, 1, n) {
            if (i != j) {
                maxO = max(maxO, maxA[j]);
                minO = max(minO, minA[j]);
            }
        }
        if (minA[i] >= maxO) puts("0");
        else if (maxA[i] < minO) puts("1");
        else puts("2");
    }

    return 0;
}