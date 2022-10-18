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
#define maxN 200005

ll x, y, m, ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> x >> y >> m;

    if (x > y) swap(x, y);

    if (y >= m) {
        printf("0"); return 0;
    }
    if (y <= 0) {
        printf("-1"); return 0;
    }

    if (x < 0) {
        ans = ((-x-1)/y)+1;
        x+=ans*y;
    }

    while (y < m) {
        x = x+y;
        swap(x, y);
        ++ans;
    }

    cout << ans;

    return 0;
}