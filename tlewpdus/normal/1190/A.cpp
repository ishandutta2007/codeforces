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

ll n, k;
int m;
ll arr[100100];

int main() {
    scanf("%lld%d%lld",&n,&m,&k);
    for (int i=0;i<m;i++) {
        scanf("%lld",&arr[i]);
        arr[i]--;
    }
    int p = 0, c = 0;
    while(p<m) {
        int q = p;
        while(q<m&&(arr[p]-p)/k==(arr[q]-p)/k) q++;
        c++;
        p=q;
    }
    printf("%d\n",c);

    return 0;
}