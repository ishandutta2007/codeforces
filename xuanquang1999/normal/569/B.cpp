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
#define maxN 100005

int n, a[maxN];
bool avail[maxN], ok[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    memset(avail, true, sizeof(avail));
    fto(i, 0, n-1)
        if (a[i] <= n && avail[a[i]]) {
            ok[i] = true;
            avail[a[i]] = false;
        }

    int j = 1;
    fto(i, 0, n-1)
        if (!ok[i]) {
            while (!avail[j]) ++j;
            a[i] = j;
            ++j;
        }

    fto(i, 0, n-1) printf("%d ", a[i]);

    return 0;
}