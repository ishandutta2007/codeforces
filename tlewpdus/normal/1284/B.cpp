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
vector<int> arr[100100];
int mina[100100], maxa[100100];
int acc[100100];

int main() {
    scanf("%d",&n);
    ll cnt = 0;
    for (int i=0;i<n;i++) {
        int l;
        scanf("%d",&l);
        arr[i].resize(l);
        int mini = INF, maxi = 0;
        for (int j=0;j<l;j++) {
            scanf("%d",&arr[i][j]);
            if (mini<arr[i][j]) {
                acc[i] = 1;
            }
            mini = min(mini,arr[i][j]);
            maxi = max(maxi,arr[i][j]);
        }
        mina[i] = mini;
        maxa[i] = maxi;
        if (acc[i]) cnt++;
    }
    vector<int> vec;
    for (int i=0;i<n;i++) {
        if (acc[i]) continue;
        vec.push_back(maxa[i]);
    }
    sort(vec.begin(),vec.end());
    ll ans = 0;
    for (int i=0;i<n;i++) {
        if (acc[i]) continue;
        ans += (int)vec.size()-(upper_bound(vec.begin(),vec.end(),mina[i])-vec.begin());
    }
    printf("%lld\n",ans+1LL*n*n-1LL*(n-cnt)*(n-cnt));

	return 0;
}