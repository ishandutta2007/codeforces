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
ll h;
ll arr[1010];

int main() {
    int i, j;

    scanf("%d%lld",&n,&h);
    for (i=0;i<n;i++) scanf("%lld",&arr[i]);
    for (i=1;i<=n;i++) {
        sort(arr,arr+i);
        ll sum = 0;
        for (j=i-1;j>=0;j-=2) sum += arr[j];
        if (sum>h) break;
    }
    printf("%d\n",i-1);

    return 0;
}