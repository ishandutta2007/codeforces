#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,pii> piii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n, k, R;
int avail[1010];
int on[1010];

bool query() {
	int cnt = 0;
	for (int i=0;i<n;i++) {
		cnt += on[i];
	}
	if (cnt>=R) return false;
	int rem = k;
	vector<int> loc;
	for (int i=0;i<n&&rem>0;i++) {
		if (avail[i]&&!on[i]) {
			rem--;
			on[i] = 1;
			loc.push_back(i);
		}
	}
	printf("%d ",loc.size());
	for (int &v : loc) printf("%d ",v+1);
	puts("");
	fflush(stdout);
	int x;
	scanf("%d",&x); x--;
	for (int i=0;i<k;i++) {
		on[(x+i)%n] = 0;
	}
	return true;
}

int calc(int n, int k) {
	if (n%k==0) return (k-1)*(n/k-1);
	return (k-1)*(n/k-1)+(n%k-1);
}

int main(){
	scanf("%d",&n);
	int maxi = 0, maxk = 1;
	for (k=1; k <= n; k++) {
		if (maxi<=calc(n,k)) {
			maxi=calc(n,k);
			maxk=k;
		}
	}
	k = maxk;
	for (int i=0;i<=n/k;i++) {
		for (int j=0;j<k-1;j++) {
			if (i*k+j<n-1) avail[i*k+j] = 1;
		}
	}
	R = calc(n,k);
	//printf("%d\n",R);
	while(query());
	puts("0");
	fflush(stdout);

	return 0;
}