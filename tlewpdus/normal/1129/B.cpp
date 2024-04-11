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

int k;

int main() {
    int i, a, b;

    scanf("%d",&k);
    int m;
    for (m=1;;m++) if (m*(2*m+1)+2*m+2>k+1000000) break;
    m = min(m-2,999);

    for (i=999999;;i--) {
        if ((i+k)%(2*m+1)==0) break;
    }
    b = i;
    a = (b+k)/(2*m+1)+m;
    printf("%d\n",2*m+1);
    printf("%d %d ",b,-b-1);
    for (i=0;i<m-1;i++) printf("%d %d ",a,-a-1);
    printf("%d\n",a);

    return 0;
}