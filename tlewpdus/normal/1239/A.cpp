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

ll arr[100100];
ll calc(int n) {
    arr[0] = 1;
    arr[1] = 1;
    for (int i=2;i<=n;i++) {
        arr[i] = (arr[i-1]+arr[i-2])%MOD;
    }
    return arr[n];
}

int main() {
    int n, m;

    scanf("%d%d",&n,&m);
    printf("%lld\n",(calc(n)+calc(m)+MOD-1)*2%MOD);

	return 0;
}