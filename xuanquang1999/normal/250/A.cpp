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

int n, a[maxN], cnt;
vector<int> ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    int l = 0;
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        if (x < 0) {
            if (cnt == 2) {
                ans.pb(i-1-l);
                l = i-1;
                cnt = 0;
            }
            ++cnt;
        }
    }
    ans.pb(n-l);

    printf("%d\n", ans.size());
    fto(i, 0, ans.size()-1) printf("%d ", ans[i]);

    return 0;
}