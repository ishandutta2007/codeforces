using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
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

int n;
mapii s;
vector<int> ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n*n) {
        int x;
        scanf("%d", &x); ++s[x];
    }

    fto(i, 1, n) {
        int x = (--s.end())->fi;
        forit(it, vector<int>, ans) {
            int k = __gcd(*it, x);
            if (s[k] == 2) s.erase(k);
            else s[k] -= 2;
        }
        if (s[x] == 1) s.erase(x);
        else --s[x];
        ans.pb(x);
    }

    forit(it, vector<int>, ans) printf("%d ", *it);

    return 0;
}