#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
int arr[200100];

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int mini = INF;
		for (int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
		}
		int good = 0;
		int j = -1;
		for (int i=0;i<n;i++) {
			if (arr[i]-i-1>=mini) {
				puts("YES");
				printf("%d %d\n",j+1,i+1);
				good = 1;
				break;
			}
			if (mini>arr[i]-i) {
				mini=arr[i]-i;
				j = i;
			}
		}
		if (good) continue;
		mini = INF;
		j = -1;
		for (int i=n-1;i>=0;i--) {
			if (arr[i]+i-1>=mini) {
				puts("YES");
				printf("%d %d\n",i+1,j+1);
				good = 1;
				break;
			}
			if (mini>arr[i]+i) {
				mini=arr[i]+i;
				j=i;
			}
		}
		if (!good) {
			puts("NO");
			continue;
		}
	}

	return 0;
}