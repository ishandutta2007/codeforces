using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 105
#define maxX 1000005

int n, nB, cnt, ans;
pair<char, int> a[maxN];
char b[2*maxN];
bool avail[maxX];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) cin >> a[i].fi >> a[i].se;

    fto(i, 0, n-1) {
        if (a[i].fi == '+') avail[a[i].se] = true;
        else {
            if (avail[a[i].se] == false) b[nB] = '+', ++nB;
            avail[a[i].se] = false;
        }
    }
    fto(i, 0, n-1) b[nB] = a[i].fi, ++nB;

    fto(i, 0, nB-1) {
        if (b[i] == '-') --cnt; else ++cnt;
        ans = max(ans, cnt);
    }

    printf("%d", ans);

    return 0;
}