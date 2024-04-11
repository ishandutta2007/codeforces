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
int arr[300100];
vector<int> vec[2];

int main() {
    int i;

    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        scanf("%d",&arr[i]);
        arr[i] ^= arr[i-1];
    }
    long long ans = 0;
    for (i=0;i<=n;i++) vec[i%2].push_back(arr[i]);
    for (i=0;i<2;i++) {
        sort(vec[i].begin(),vec[i].end());
        int j, p = 0;
        for (j=0;j<vec[i].size();j++) {
            if (j+1==vec[i].size()||vec[i][j]!=vec[i][j+1]) {
                ans += (1LL*j-p+1)*(1LL*j-p)/2;
                p = j+1;
            }
        }
    }
    printf("%lld\n",ans);

    return 0;
}