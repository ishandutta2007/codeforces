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
#define maxN 1005
#define oo 1000000007

int n, m, a[maxN][maxN];
bool b[maxN][maxN], good[maxN][maxN];
vector<int> row;

bool Check(int x) {
    //debug(x);
    fto(i, 0, n-1)
        fto(j, 0, m-1) b[i][j] = (x <= a[i][j]);

    memset(good, false, sizeof(good));
    fto(j, 0, m-1) {
        row.clear();
        fto(i, 0, n-1)
            if (b[i][j] == 1) row.pb(i);
        int k = row.size();
        fto(i, 0, k-2)
            fto(j, i+1, k-1) {
                int r1 = row[i], r2 = row[j];
                if (good[r1][r2]) return true;
                else good[r1][r2] = true;
            }
    }

    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, n-1)
        fto(j, 0, m-1) scanf("%d", &a[i][j]);

    int l = 0, r = oo, res = -1;
    while (l <= r) {
        int mid = (l+r)/2;
//        debug(l);
//        debug(r);
//        debug(mid);
        if (Check(mid)) {
            if (res < mid) res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }

    printf("%d", res);

    return 0;
}