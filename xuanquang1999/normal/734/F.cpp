//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ftoa(i, l, r, a) for(int i = (l); i <= (r); i += a)
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
#define oo 5000000000000000000LL

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

int n, a[maxN], b[maxN], c[maxN], d[maxN], cnt[32];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &b[i]);
    fto(i, 1, n) scanf("%d", &c[i]);

    fto(i, 1, n) d[i] = b[i]+c[i];

    ll sum = 0;
    fto(i, 1, n) sum += d[i];
    if (sum%(2*n) != 0) {
        puts("-1");
        return 0;
    }

    sum /= 2*n;

    fto(i, 1, n) {
        if (d[i] < sum || (d[i]-sum)%n != 0) {
            puts("-1");
            return 0;
        }
        else a[i] = (d[i]-sum)/n;
    }

    fto(k, 0, 31) {
        fto(i, 1, n) cnt[k] += (a[i]>>k)&1;
    }

    fto(i, 1, n) {
        ll B = 0, C = 0;
        fto(k, 0, 31) {
            if ((a[i]>>k)&1) {
                B += (1LL<<k)*cnt[k];
                C += (1LL<<k)*n;
            }
            else {
                C += (1LL<<k)*cnt[k];
            }
        }
        if (B != b[i] && C != c[i]) {
            puts("-1");
            return 0;
        }
    }

    fto(i, 1, n) printf("%d ", a[i]);





    return 0;
}