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
#define maxN 105

int n, a[maxN], ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    while (true) {
        bool ok = true;
        fto(i, 2, n)
            if (a[i] >= a[1]) ok = false;
        if (ok) {
            printf("%d", ans);
            return 0;
        }

        int k = 0, maxA = 0;
        fto(i, 2, n)
            if (a[i] > maxA) {
                maxA = a[i];
                k = i;
            }
        --a[k], ++a[1];
        ++ans;
    }

    return 0;
}