#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int n, k;
int arr[150000];
int chk[150000];
ll D[150000][4];

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<k;i++) scanf("%d",&arr[i]), arr[i]--;

	if (k==0) {
		puts("0");
		return 0;
	}
	sort(arr,arr+k);
	for (int i=0;i<k;i++) chk[arr[i]/2]=1;
	int ans = 1;
	for (int i=0;i<(1<<n)/2;i++) ans+=chk[i];
	memset(chk,0,sizeof(chk));
	for (int i=0;i<k;i++) chk[arr[i]/4]++;
	for (int i=0;i<(1<<(n-2));i++) {
		int idx=  (1<<(n-2))+i;
		if (chk[i]==0) {
			D[idx][0] = 0;
			D[idx][1] = D[idx][2] = D[idx][3] = -INF;
		}
		else if (chk[i]==1){
			D[idx][0] = -INF;
			D[idx][1] = 1;
			D[idx][2] = 2;
			D[idx][3] = -INF;
		}
		else {
			D[idx][0] = -INF;
			D[idx][1] = 1;
			D[idx][2] = 2;
			D[idx][3] = 3;
		}
	}
	for (int i=(1<<(n-2))-1;i;i--) {
		int arr[] = {0,1,2,3};
		for (int j=0;j<4;j++) D[i][j] = -INF;
		for (int j=0;j<4;j++) {
			for (int k=0;k<4;k++) {
				D[i][j|k] = max(D[i][j|k],D[i*2][j]+D[i*2+1][k]+arr[j|k]);
			}
		}
	}
	printf("%d\n",ans+max({D[1][0],D[1][1],D[1][2],D[1][3]}));

	return 0;
}