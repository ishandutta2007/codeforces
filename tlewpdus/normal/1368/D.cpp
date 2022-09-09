#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,pii> piii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
int arr[200100];
int bit[21][200100];

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		for (int j=0;j<20;j++) {
			bit[j][i] = (arr[i]>>j&1);
		}
	}
	for (int i=0;i<20;i++) {
		sort(bit[i],bit[i]+n);
	}
	ll sum = 0;
	for (int i=0;i<n;i++) {
		ll x = 0;
		for (int j=0;j<20;j++) {
			x |= (bit[j][i]<<j);
		}
		sum += x*x;
	}
	printf("%lld\n",sum);

	return 0;
}