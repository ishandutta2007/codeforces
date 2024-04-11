//Resubmit
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
#define maxN 100005

int n, m, a[maxN];
ll cnt;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) scanf("%d", &a[i]);
    a[0] = 1;

    fto(i, 1, m)
        if (a[i] >= a[i-1]) cnt+=a[i]-a[i-1];
        else cnt+=n-a[i-1]+a[i];

    cout << cnt;

    return 0;
}