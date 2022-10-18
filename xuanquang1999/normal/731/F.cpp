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
#define ull unsigned long long
#define maxN 200005
#define maxX 400005
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

int n, a[maxN], d[maxX];
bool visited[maxX];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]), ++d[a[i]];
    fto(i, 1, maxX-1) d[i] += d[i-1];

    ll ans = 0;
    fto(i, 1, n) {
        if (!visited[a[i]]) {
//            debug(a[i]);
            visited[a[i]] = true;
            ll sum = 0;
            ftoa(j, 0, maxX/2-1, a[i]) {
                ll x = d[j+a[i]-1] - ((j > 0) ? d[j-1] : 0);
                //if (j <= a[i] && a[i] < j+a[i]) --x;
                sum += x*j;
            }
//            debug(sum);
            ans = max(ans, sum);
        }
    }

    cout << ans;

    return 0;
}