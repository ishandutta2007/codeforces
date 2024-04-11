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
#define maxN 500005
#define oo 1000000007
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

int n, k, a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a+n+1);

    ll sum = accumulate(a+1, a+n+1, (ll)0);

    int l, r, resL, resR;
    l = a[1]; r = sum/n; resL = -1;
    while (l <= r) {
        int mid = (l+r)/2;

        ll d = 0;
        fto(i, 1, n) d += max(0, mid-a[i]);

        if (d <= k) {
            resL = max(resL, mid);
            l = mid+1;
        }
        else r = mid-1;
    }

    l = sum/n+(sum%n != 0); r = a[n]; resR = oo;
    while (l <= r) {
        int mid = (l+r)/2;

        ll d = 0;
        fto(i, 1, n) d += max(0, a[i]-mid);

        if (d <= k) {
            resR = min(resR, mid);
            r = mid-1;
        }
        else l = mid+1;
    }
//    printf("%d %d\n", resL, resR);
    printf("%d", resR-resL);

    return 0;
}