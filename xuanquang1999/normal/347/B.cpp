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

int n, a[maxN], pos[maxN], ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    fto(i, 0, n-1) {
        pos[a[i]] = i;
        if (a[i] == i) ++ans;
    }
    fto(i, 0, n-1)
        if (a[i] != i && a[a[i]] == i) {
            printf("%d", ans+2);
            return 0;
        }
    printf("%d", min(n, ans+1));


    return 0;
}