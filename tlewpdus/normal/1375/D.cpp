#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
int arr[1100];

int cnt[1100];
int MEX() {
	for (int i=0;i<n;i++) {
		cnt[arr[i]]++;
	}
	int ret = 0;
	for (int i=0;i<=n;i++) {
		if (cnt[i]==0) {
			ret = i;
			break;
		}
	}
	for (int i=0;i<n;i++) {
		cnt[arr[i]]--;
	}
	return ret;
}

int done[1100];

int main(){
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&arr[i]);
		vector<int> ans;
		for (int i=0;i<n;i++) {
			if (arr[i]==i) continue;
			for (int j=i+1;j<n;j++) {
				if (arr[j]==i) {
					arr[j] = MEX();
					ans.push_back(j);
//					printf("%d!\n",j+1);
				}
			}
			int p = i;
			do {
				arr[p] = MEX();
				ans.push_back(p);
				int v = MEX();
				if (v<n&&v>i) p = v;
				else break;
			} while(p!=i);
//			printf("%d!\n",i+1);
//			for (int j=0;j<n;j++) printf("%d ",arr[j]); puts("");
		}
		printf("%d\n",ans.size());
		for (int &v : ans) printf("%d ",v+1);
		puts("");
//		for (int i=1;i<n;i++) {
//			if (arr[i]<arr[i-1]) puts("WRONG");
//		}
//		if (ans.size()>2*n) {
//			puts("WWWW");
//		}
	}

	return 0;
}