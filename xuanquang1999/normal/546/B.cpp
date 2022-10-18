using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define lli pair<long long, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define mod 1000000009
int n, a[maxN], curmin, ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);
    sort(a, a+n);

    curmin = a[0], ans = 0;
    fto(i, 1, n-1) {
        ans+=max(0, curmin+1-a[i]);
        a[i]=max(a[i], curmin+1);
        curmin=max(curmin, a[i]);
    }

    printf("%d", ans);

    return 0;
}