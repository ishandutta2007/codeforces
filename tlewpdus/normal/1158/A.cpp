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

int n, m;
ll arr[100100], brr[100100];

int main() {
    int i, j;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) scanf("%lld",&arr[i]);
    for (i=0;i<m;i++) scanf("%lld",&brr[i]);
    ll maxi = 0, mini = 1e9;
    for (i=0;i<n;i++) maxi = max(maxi,arr[i]);
    for (i=0;i<m;i++) mini = min(mini,brr[i]);
    if (maxi>mini) {
        puts("-1");
        return 0;
    }
    ll sum =0;
    for (i=0;i<n;i++) sum+=arr[i];
    sum*=m;
    if (mini==maxi) {
        for (i=0;i<m;i++) sum += brr[i]-maxi;
        printf("%lld\n",sum);
        return 0;
    }
    for (i=0;i<m;i++) sum += brr[i]-maxi;
    sort(arr,arr+n);
    sum += arr[n-1]-arr[n-2];
    printf("%lld\n",sum);

    return 0;
}