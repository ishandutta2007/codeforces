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
#define maxN 100005

int n, k, nB, a[maxN], b[maxN], total, minS, ans;
vector<int> g[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    b[0] = a[0]; nB = 1;
    fto(i, 1, n-1)
        if (a[i] != a[i-1]) {
            ++total;
            b[nB] = a[i]; ++nB;
        }

    fto(i, 0, nB-1) g[b[i]].pb(i);

    //fto(i, 0, nB-1) debug(b[i]);


    minS = total+1;
    fto(i, 1, k) {
        int cnt = total;
        forit(it, vector<int>, g[i]) {
            int j = *it;
            --cnt;
            if (j != 0 && j != nB-1 && b[j-1] == b[j+1]) --cnt;
        }
        if (cnt < minS) {
            minS = cnt;
            ans = i;
        }
    }

    printf("%d", ans);

    return 0;
}