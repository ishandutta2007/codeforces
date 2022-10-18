using namespace std;
#include <bits/stdc++.h>
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
#define maxN 200005

int n, ans[maxN];
ii a[maxN];
map<int, int> fl, fr;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }
    sort(a, a+n);

    int j = 1;
    fdto(i, n-1, 0) {
        int h = a[i].fi, k = a[i].se, l, r;
        if (fl.find(k+1) != fl.end() && fr.find(k-1) != fr.end()) {
            l = fr[k-1]; r = fl[k+1];
            fl.erase(k+1); fl[l] = r;
            fr.erase(k-1); fr[r] = l;
        }
        else if (fl.find(k+1) != fl.end()) {
            l = k; r = fl[k+1];
            fl.erase(k+1); fl[k] = r;
            fr[r] = l;
        }
        else if (fr.find(k-1) != fr.end()) {
            l = fr[k-1]; r = k;
            fr.erase(k-1); fr[k] = l;
            fl[l] = r;
        }
        else {
            l = k; r = k;
            fl[k] = k; fr[k] = k;
        }
        while (j <= r-l+1) {
            ans[j] = h;
            ++j;
        }
    }

    fto(i, 1, n) printf("%d ", ans[i]);

    return 0;
}