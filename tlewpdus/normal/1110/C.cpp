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
int pre[30] = {0,0,1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int main() {
    int i, j;

    scanf("%d",&n);
    for (i=0;i<n;i++) {
        int v;
        scanf("%d",&v);
        for (j=2;j<=25;j++) {
            if (v<=(1<<j)-1) break;
        }
        if (v==(1<<j)-1) printf("%d\n",pre[j]);
        else printf("%d\n",(1<<j)-1);
    }

    return 0;
}