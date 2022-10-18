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
#define maxN 200005
#define double long double

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

double l, PI = acos(-1), ans;

double sqr(double x) {
    return x*x;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(n, 3, 5) {
        cin >> l;
        double OA = l/sqrt(2-2*cos(2*PI/n));
        double SO = sqrt(sqr(l)-sqr(OA));
        double OH = sqrt(sqr(OA)-sqr(l/2));
//        debug(OA);
//        debug(SO);
//        debug(OH);
//        debug(((OH*l/2)*n*SO)/3);
        ans += ((OH*l/2)*n*SO)/3;
    }

    cout << setprecision(10) << ans;

    return 0;
}