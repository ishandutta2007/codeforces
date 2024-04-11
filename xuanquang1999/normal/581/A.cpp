#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 100005
#define oo 1000000007

int n, m;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    if (n < m) swap(n, m);
    printf("%d %d", m, (n-m)/2);

    return 0;
}