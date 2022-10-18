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
#define maxK 505
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

int nTest;
double p, q;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        scanf("%lf%lf", &p, &q);
        double ans;
        if (p == 0 && q == 0) ans = 1;
        else if (p == 0) ans = 0.5;
        else if (q == 0) ans = 1;
        else {
            double x = p/4;
//            printf("%.5f %.5f %.5f %.5f\n", p, q, x, 0.5*x/q);
            if (x < q) {
                ans = 0.5 + 0.25*x/q; // (0.5*x*p)/(p*q);
            }
            else {
                double y = q/x*p;
                ans = 1.0 - (0.25*y)/p;
            }
        }
        printf("%.10f\n", ans);
    }

    return 0;
}