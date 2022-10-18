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
#define maxN 100005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, a[maxN], fl[maxN], fr[maxN], ans[maxN], cnt[maxN], len;
vector<int> v;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n) {
        int p = lower_bound(v.begin(), v.end(), a[i])-v.begin();
        if (p == v.size()) v.pb(a[i]);
        else v[p] = a[i];
        fl[i] = p+1;
    }
    len = v.size();
    v.clear();

    fdto(i, n, 1) {
        int p = lower_bound(v.begin(), v.end(), -a[i])-v.begin();
        if (p == v.size()) v.pb(-a[i]);
        else v[p] = -a[i];
        fr[i] = p+1;
    }
    v.clear();

//    fto(i, 1, n) printf("%d ", fl[i]);
//    puts("");
//    fto(i, 1, n) printf("%d ", fr[i]);
//    puts("");

    fto(i, 1, n) {
        if (fl[i]+fr[i]-1 == len) ++cnt[fl[i]];
    }

    fto(i, 1, n) {
        if (fl[i]+fr[i]-1 != len) printf("1");
        else if (cnt[fl[i]] > 1) printf("2");
        else printf("3");
    }

    return 0;
}