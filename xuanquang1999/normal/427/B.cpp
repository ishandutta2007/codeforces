#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define fdto(i, r, l) for(int i = (r); i >= (l); ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define forrit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mapii map<int, int>
#define maxN 200005
#define oo 1000000007

int n, a[maxN], t, c, ans;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &t, &c);
    fto(i, 1, n) scanf("%d", &a[i]);

    int l = 1;
    fto(r, 1, n+1) {
        if (r == n+1 || a[r] > t) {
            ans += max(0, (r-l)-c+1);
            l = r+1;
        }
    }

    cout << ans;

    return 0;
}