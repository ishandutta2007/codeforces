#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n, x, y, d;

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d%d",&n,&x,&y,&d); --x; --y;
        if (x%d==y%d) {
            printf("%d\n",abs(x-y)/d);
            continue;
        }
        int v = 2*n+2;
        if (y%d==0) {
            v = min(v,y/d+(x+d-1)/d);
        }
        if (y%d==(n-1)%d) {
            v = min(v,(n-1-y)/d+(n-2-x+d)/d);
        }
        printf("%d\n",(v==2*n+2)?-1:v);
    }

    return 0;
}