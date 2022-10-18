using namespace std;
#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define ii pair<int, int>
#define mp make_pair
#define pb push_back

char a[1005], b[1005];
int ans, n;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d\n", &n);
    scanf("%s\n", &a);
    scanf("%s\n", &b);

    fto(i, 0, n-1) {
        int c1 = max(a[i], b[i]), c2 = min(a[i], b[i]);
        ans+=min(c1-c2, c2+10-c1);
    }

    printf("%d", ans);

    return 0;
}