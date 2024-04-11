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

int n, k, a[maxN], ans = oo;
vector<int> v;

int Solve(int k) {
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
//    forit(it, v) printf("%d ", *it);
//    puts("");
//    debug(k);
    int cnt = 0;
    forit(it, v) {
        if (k > 0) {
            k -= *it;
            cnt += 2;
        }
    }
    if (k > 0) return oo;
    return cnt;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) scanf("%d", &a[i]);

    int cnt = 0;
    fto(i, 1, n+1) {
        if (i == n+1 || (i > 1 && (a[i] >= 0)^(a[i-1] >= 0))) {
            if (a[i-1] >= 0) v.pb(cnt);
            cnt = 0;
        }
        ++cnt;
    }

    if (a[1] >= 0) {
        k += *v.begin();
        v.erase(v.begin());
    }

    if (v.size() == 0) {
        if (a[1] >= 0) {
            if (a[n] < 0) {
                if (n-k > 0) puts("-1");
                else puts("1");
            }
            else puts("0");
        }
        else {
            if (n == k) puts("1");
            else puts("-1");
        }
        return 0;
    }


    if (a[n] >= 0) {
        int x = *v.rbegin();
        v.pop_back();
        ans = min(ans, Solve(n-k-x)+2);
    }
    ans = min(ans, Solve(n-k)+1);

    if (ans == oo) puts("-1");
    else printf("%d", ans);

    return 0;
}