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
#define maxN 1005
#define maxK 20
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

int n, a[maxN], cntIgnore;
bool _ignore[maxN], visited[maxN];
vector<int> ke[maxN];

ll GCD(ll a, ll b) {return (b == 0) ? a : GCD(b, a%b);}
ll LCM(ll a, ll b) {return a/GCD(a, b)*b;}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x); a[i] = x;
        if (x == i) {_ignore[i] = true; ++cntIgnore;}
        else ke[x].pb(i);
    }

    ll ans = 1;
    fto(i, 1, n) {
        if (!_ignore[i] && ke[i].size() == 0) {
            puts("-1");
            return 0;
        }
        else {
            memset(visited, false, sizeof visited);
            int u = i, cnt = 0;
            while (!visited[u]) {
                visited[u] = true;
                u = a[u];
                ++cnt;
            }
            if (cnt%2 == 0) cnt /= 2;
            ans = LCM(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}