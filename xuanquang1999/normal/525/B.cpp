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
#define maxN 200005

int n, k, a[maxN], cnt;
char s[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%s", &s); n = strlen(s);
    scanf("%d", &k);
    fto(i, 0, k-1) {
        scanf("%d", &a[i]);
        --a[i];
    }
    sort(a, a+k);

    int j = 0;
    fto(i, 0, n/2-1) {
        while (j < k && a[j] <= i) {
            ++j;
            ++cnt;
        }
        if (cnt%2) swap(s[i], s[n-1-i]);
    }

    printf("%s", s);

    return 0;
}