#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
char str[5010];

bool tst() {
    int i, j;
    for (i=1;i<n;i++) {
        int f = 1;
        for (j=i;j<i+n;j++) {
            if (str[j%n]!=str[(i+i+n-j-1)%n]) f = 0;
        }
        int g = 0;
        for (j=i;j<i+n;j++) {
            if (str[j%n]!=str[j-i]) g = 1;
        }
        if (f&&g) return 1;
    }
    return 0;
}

int main() {
    int i;

    scanf("%s",str);
    n = strlen(str);
    if (n%2==0) {
        for (i=0;i<n;i++) if (str[i]!=str[0]) break;
        if (i==n) {
            puts("Impossible");
            return 0;
        }
        if (tst()) printf("1\n");
        else printf("2\n");
        return 0;
    }
    else {
        for (i=0;i<n;i++) if (i!=n/2&&str[i]!=str[0]) break;
        if (i==n) {
            puts("Impossible");
            return 0;
        }
        if (tst()) printf("1\n");
        else printf("2\n");
        return 0;
    }

    return 0;
}