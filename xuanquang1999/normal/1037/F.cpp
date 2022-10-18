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

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, k, a[MAXN], l[MAXN], r[MAXN];
ll deriv[MAXN], cnt[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) scanf("%d", &a[i]);

    stack<int> st;
    st.push(0);
    fto(i, 1, n) {
        while (st.size() > 1 && a[st.top()] <= a[i]) st.pop();
        l[i] = st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();
    st.push(n+1);
    fdto(i, n, 1) {
        while (st.size() > 1 && a[st.top()] < a[i]) st.pop();
        r[i] = st.top();
        st.push(i);
    }

    for(int i = k; i <= n; i += k-1) {
        ++deriv[i];
    }

    int cur = 0;
    fto(i, 1, n) {
        cur += deriv[i];
        cnt[i] += cnt[i-1] + cur;
    }

//    fto(i, 1, n) printf("%d %d %lld\n", l[i], r[i], cnt[i]);

    ll ans = 0;
    fto(i, 1, n) {
        int L = i-l[i]-1, R = r[i]-i-1;
        ll cntSeg = (cnt[L+R+1] - cnt[L] - cnt[R])%MOD;
        ans = (ans + 1LL*a[i]*cntSeg)%MOD;
    }

    cout << ans;

    return 0;
}