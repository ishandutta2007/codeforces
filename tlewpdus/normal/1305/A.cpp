#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
int arr[110], brr[110];

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&arr[i]);
		for (int i=0;i<n;i++) scanf("%d",&brr[i]);
		sort(arr,arr+n);
		sort(brr,brr+n);
		for (int i=0;i<n;i++) printf("%d ",arr[i]); puts("");
		for (int i=0;i<n;i++) printf("%d ",brr[i]); puts("");
	}

	return 0;
}