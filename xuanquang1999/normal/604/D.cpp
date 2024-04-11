//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(ll i = (r); i >= (l); --i)
#define fto(i, l, r) for(ll i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1000005
#define MOD 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ll p, k, cnt;
bool visited[maxN];
ll ans;

ll sqrmod(ll x) {
    return (x*x)%MOD;
}

ll powmod(ll x, ll p) {
    if (p == 0) return 1;
    if (p%2 == 0) return sqrmod(powmod(x, p/2));
    return (x*powmod(x, p-1))%MOD;
}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> p >> k;
    fto(x, 0, p-1) {
        if (!visited[x]) {
            ll t = x;
            while (!visited[t]) {
                visited[t] = true;
                t = (t*k)%p;
            }
            ++cnt;
        }
    }
    if (k != 1) --cnt;

    cout << powmod(p, cnt);

    return 0;
}