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
#define maxN 1000005

int n, k, e2, p[maxN];
ll tmp;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    tmp = n; printf("%I64d\n", tmp*(tmp+1));

    ++n; k = n;
    e2 = 1;
    while (e2 < n) e2*=2;

    while (e2 > 0) {
        fto(i, e2-n+1, n) p[i]=e2-i;
        n = e2-n;
        while (e2 > 0 && e2 >= n*2) e2/=2;
    }

    fto(i, 1, k) printf("%d ", p[i]);

    return 0;
}