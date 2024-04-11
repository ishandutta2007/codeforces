#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, l, r) for(int i = r; i >= l; --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); ++it)
#define ll long long
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 100005
#define oo 1000000007

int n;
vector<int> res;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        vector<int>::iterator it = lower_bound(res.begin(), res.end(), x);
        if (it == res.end()) res.pb(x);
        else *it = x;
    }
    cout << res.size();

    return 0;
}