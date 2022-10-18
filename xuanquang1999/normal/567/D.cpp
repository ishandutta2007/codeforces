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

int n, k, a, m, cnt;
set<int> s;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &k, &a);
    scanf("%d", &m);

    s.insert(0);
    s.insert(n+1);
    cnt = (n+1)/(a+1);

    fto(i, 1, m) {
        int x;
        scanf("%d", &x);

        set<int>::iterator it = s.upper_bound(x);
        int l = *(--it), r = *(++it);
        cnt = cnt - (r-l)/(a+1) + (x-l)/(a+1) + (r-x)/(a+1);

        if (cnt < k) {
            printf("%d", i);
            return 0;
        }

        s.insert(x);
    }

    printf("-1");
    return 0;
}