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

ll tree[530000];
const int key = 262144;
void upd(int s, int e, ll val) {
	s+=key;
	e+=key;
	while(s<=e) {
		if (s&1) tree[s++] += val;
		if (~e&1) tree[e--] += val;
		s/=2; e/=2;
	}
}
ll getv(int idx) {
	ll ans = 0;
	idx += key;
	while(idx) {
		ans += tree[idx];
		idx/=2;
	}
	return ans;
}

int n;
ll m;
ll arr[200100], brr[200100];
ll orda[200100], ordb[200100];
int ans[200100];

void tupd(int s, int e, ll val) {
	if (s>e) return;
	if (s<0&&e<0) {
		upd(s+n,e+n,val);
	}
	else if (s>=n&&e>=n) {
		upd(s-n,e-n,val);
	}
	else if (s<0) {
		upd(0,e,val);
		upd(s+n,n-1,val);
	}
	else if (e>=n) {
		upd(s,n-1,val);
		upd(0,e-n,val);
	}
	else upd(s,e,val);
}

int main() {
	scanf("%lld%d",&m,&n);
	for (int i=0;i<n;i++) scanf("%lld",&arr[i]),arr[i]=(arr[i]-1)*2;
	for (int i=0;i<n;i++) scanf("%lld",&brr[i]),brr[i]=(brr[i]-1)*2;
	iota(orda,orda+n,0);
	sort(orda,orda+n,[](int a, int b){return arr[a]<arr[b];});
	iota(ordb,ordb+n,0);
	sort(ordb,ordb+n,[](int a, int b){return brr[a]<brr[b];});
	sort(arr,arr+n); sort(brr,brr+n);
	for (int i=0;i<n;i++) {
		if (arr[i]<m) {
			int j = lower_bound(brr,brr+n,arr[i]+m)-brr;
			if (j!=n) tupd(j-i,n-1-i,m*2+arr[i]);
			int k = lower_bound(brr,brr+n,arr[i])-brr-1;
			if (k>=0) tupd(-i,k-i,arr[i]);
			k++; j--;
			if (k<=j) tupd(k-i,j-i,-arr[i]);
		}
		else {
			int j = lower_bound(brr,brr+n,arr[i]-m)-brr-1;
			if (j>=0) tupd(-i,j-i,m*2-arr[i]);
			int k = lower_bound(brr,brr+n,arr[i])-brr;
			if (k<n) tupd(k-i,n-1-i,-arr[i]);
			j++; k--;
			if (j<=k) tupd(j-i,k-i,arr[i]);
		}
		if (brr[i]<m) {
			int j = upper_bound(arr,arr+n,brr[i]+m)-arr;
			if (j!=n) tupd(i-n+1,i-j,brr[i]);
			int k = upper_bound(arr,arr+n,brr[i])-arr-1;
			if (k>=0) tupd(i-k,i,brr[i]);
			k++; j--;
			if (k<=j) tupd(i-j,i-k,-brr[i]);
		}
		else {
			int j = upper_bound(arr,arr+n,brr[i]-m)-arr-1;
			if (j>=0) tupd(i-j,i,-brr[i]);
			int k = upper_bound(arr,arr+n,brr[i])-arr;
			if (k<n) tupd(i-n+1,i-k,-brr[i]);
			k--; j++;
			if (j<=k) tupd(i-k,i-j,brr[i]);
		}
	}
	ll mini = 1e18;
	int at = 0;
	for (int i=0;i<n;i++) {
		if (mini>getv(i)) {
			mini=getv(i);
			at=i;
		}
	}
	printf("%lld\n",mini/2);
	for (int i=0;i<n;i++) {
		ans[orda[i]] = ordb[(i+at)%n];
	}
	for (int i=0;i<n;i++) printf("%d ",ans[i]+1);
	printf("\n");

	return 0;
}