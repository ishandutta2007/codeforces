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
int deg[100100];

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n-1;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        deg[a]++;deg[b]++;
    }
    for (i=0;i<n;i++) if (deg[i]==2) {
        puts("NO");
        return 0;
    }
    puts("YES");

    return 0;
}