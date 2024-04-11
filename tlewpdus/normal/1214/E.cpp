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
int arr[100100];
int ord[100100];
vector<int> val[200100];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	iota(ord,ord+n,0);
	sort(ord,ord+n,[](int a, int b){
		return arr[a]>arr[b];
	});
	for (int i=0;i<n;i++) val[i].push_back(ord[i]*2+1);
	int maxi = n-1;
	for (int i=0;i<n;i++) {
		int d = arr[ord[i]];
		if (val[i+d].empty()) {
			maxi = max(maxi,i+d);
			val[i+d].push_back(ord[i]*2+2);
		}
		else {
			maxi = max(maxi,i+d-1);
			val[i+d-1].push_back(ord[i]*2+2);
		}
	}
	for (int i=0;i<=maxi;i++) {
		for (int j=1;j<val[i].size();j++) printf("%d %d\n",val[i][0],val[i][j]);
	}
	for (int i=1;i<=maxi;i++) {
		printf("%d %d\n",val[i-1][0],val[i][0]);
	}

	return 0;
}