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

int n;
int arr[110];

int main() {
    int i;

    scanf("%d",&n);
    int m = 0;
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        m = max(m,arr[i]);
    }
    for (i=m;;i++) {
        int ls = 0, rs = 0;
        for (int j=0;j<n;j++) {
            ls += arr[j];
            rs += i-arr[j];
        }
        if (ls<rs) break;
    }
    printf("%d\n",i);

    return 0;
}