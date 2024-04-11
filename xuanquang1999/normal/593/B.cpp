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
#define maxN 100005
#define oo 1000000007

int n;
ll x1, x2;
pair<ll, ll> y[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    cin >> x1 >> x2;
    fto(i, 1, n) {
        int ta, tb;
        scanf("%d%d", &ta, &tb);
        ll a = ta, b = tb;
        y[i] = mp(a*x1+b, a*x2+b);
    }
    sort(y+1, y+n+1);

    fto(i, 1, n-1)
        if (y[i].ss > y[i+1].ss) {
            puts("YES");
            return 0;
        }

    puts("NO");

    return 0;
}