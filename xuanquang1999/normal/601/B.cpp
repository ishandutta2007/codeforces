//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
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

int a[maxN], tmp[maxN], l[maxN], r[maxN], n, q;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, n) scanf("%d", &tmp[i]);
    --n;
    fto(i, 1, n) a[i] = abs(tmp[i]-tmp[i+1]);

    stack<int> s;
    fto(i, 1, n) {
        while (!s.empty() && a[s.top()] < a[i]) s.pop();
        if (!s.empty()) l[i] = s.top()+1;
        else l[i] = 1;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    fdto(i, n, 1) {
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        if (!s.empty()) r[i] = s.top()-1;
        else r[i] = n;
        s.push(i);
    }
//    debuga1(l, 1, n);
//    debuga1(r, 1, n);
    fto(iq, 1, q) {
        int u, v;
        scanf("%d%d", &u, &v); --v;
        ll ans = 0;
        fto(i, u, v) ans += a[i]*(ll)(i-max(u, l[i])+1)*(ll)(min(r[i], v)-i+1);
        cout << ans << endl;
    }


    return 0;
}