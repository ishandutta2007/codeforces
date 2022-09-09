#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const ll MOD = 998244353;

int n, k;
int arr[200100];
int loc[200100];

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&arr[i]);
	for (int i=1;i<=n;i++) loc[arr[i]] = i;
	vector<int> vec;
	ll sum = 0;
	for (int i=n;i>n-k;i--) vec.push_back(loc[i]), sum += i;
	sort(vec.begin(),vec.end());
	ll ans = 1;
	for (int i=0;i+1<vec.size();i++) {
		ans = ans*(vec[i+1]-vec[i])%MOD;
	}
	printf("%lld %lld\n",sum,ans);

	return 0;
}