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
ll arr[8010];
ll brr[8010];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++)scanf("%lld",&arr[i]);
    for (int i=0;i<n;i++)scanf("%lld",&brr[i]);
    ll ans = 0;
    vector<ll> vec;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (arr[i]==arr[j]) {
                vec.push_back(arr[i]);
                break;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (ll &v : vec) if ((v|arr[i])==v) {
            ans += brr[i];
            break;
        }
    }
    printf("%lld\n",ans);

	return 0;
}