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
#define maxN 1000005
#define EPS 1e-9

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct point {
    int x, y, bx, by, id;
    bool inline operator < (const point &o) const {
        if (bx < o.bx) return true;
        if (bx > o.bx) return false;

        if (bx%2 == 1) return y < o.y;
        return y > o.y;
    }
};

int n;
point p[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    //int sqrtN = sqrt(n);
    fto(i, 1, n) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].bx = p[i].x/1000; p[i].by = p[i].y/1000;
        p[i].id = i;
    }

    sort(p+1, p+n+1);

    fto(i, 1, n) printf("%d ", p[i].id);



    return 0;
}