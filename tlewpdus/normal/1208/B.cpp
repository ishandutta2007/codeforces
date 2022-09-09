#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
int arr[2010];
int cnt[2010];

int main() {
	scanf("%d",&n);
	vector<int> comp;
	for (int i=0;i<n;i++) scanf("%d",&arr[i]), comp.push_back(arr[i]);
	sort(comp.begin(),comp.end());
	for (int i=0;i<n;i++) arr[i]= lower_bound(comp.begin(),comp.end(),arr[i])-comp.begin();

	for (int i=0;i<=n;i++) {
		for (int j=0;j<n;j++) cnt[j] = 0;
		for (int j=i;j<n;j++) cnt[arr[j]]++;
		int cur = 0;
		for (int j=0;j<n;j++) if (cnt[j]>=2) cur++;
		int fl = 0;
		for (int j=0;j<=n-i;j++) {
			if (!cur) fl = 1;
			if (j==n-i) break;
			cnt[arr[j]]++;
			if (cnt[arr[j]]==2) cur++;
			cnt[arr[j+i]]--;
			if (cnt[arr[j+i]]==1) cur--;
		}
		if (fl) {
			printf("%d\n",i);
			return 0;
		}
	}

	return 0;
}