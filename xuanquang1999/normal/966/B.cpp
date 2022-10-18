#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define maxN 300005
#define MOD 1000
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, x1, x2;
ii a[maxN];

void Work(bool swapped) {
    if (swapped) swap(x1, x2);
    vector<int> ans1, ans2;
    fto(i, 1, n) {
        int n2 = (x2+a[i].ff-1)/a[i].ff;
        if (n2 >= i) continue;
        if (a[i-n2].ff >= (x1+i-n2-1)/(i-n2)) {
            fto(j, 1, i-n2) ans1.pb(a[j].ss);
            fto(j, i-n2+1, i) ans2.pb(a[j].ss);
            if (swapped) ans1.swap(ans2);

            puts("Yes");
            printf("%d %d\n", sz(ans1), sz(ans2));
            for(int x: ans1) printf("%d ", x);
            puts("");
            for(int x: ans2) printf("%d ", x);
            puts("");

            exit(0);
        }
    }
    if (swapped) swap(x1, x2);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &x1, &x2);
    fto(i, 1, n) {
        scanf("%d", &a[i].ff);
        a[i].ss = i;
    }

    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);

    Work(false);
    Work(true);



    puts("No");

    return 0;
}