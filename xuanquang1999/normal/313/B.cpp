using namespace std;

#include <bits/stdc++.h>
#define maxN 100005

char ch[maxN];
int n, l, r, d[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%s", &ch);
    scanf("%d", &n);

    d[0] = 0;

    int k = strlen(ch);
    for (int i=1; i<k; ++i) {
        if (ch[i] == ch[i-1]) d[i] = d[i-1] + 1;
        else d[i] = d[i-1];
    }

    for (int iTest=1; iTest<=n; ++iTest) {
        scanf("%d%d", &l, &r);
        --l; --r;
        printf("%d\n", d[r] - d[l]);
    }

    return 0;
}