#include <bits/stdc++.h>
using namespace std;

int n;
int a[150013];
bool bad[150013];
vector<int> pos;

bool good(int i) {
	if (i<1 || i>n) return true;
	if (i%2==1) return a[i]<min(a[i-1],a[i+1]);
	else return a[i]>max(a[i-1],a[i+1]);
}

bool check(int i, int j) {
	swap(a[i],a[j]);
	bool ok = 1;
	for (int p: pos) {
		ok&=good(p);
	}
	for (int d=-1;d<=1;d++) {
		ok&=good(i+d);
		ok&=good(j+d);
	}
	swap(a[i],a[j]);
	return ok;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0] = 1e9;
	a[n+1] = (n%2==0 ? 0 : 1e9);
	for (int i=1;i<n;i++) {
		if (i%2==1 && a[i]>=a[i+1]) bad[i] = bad[i+1] = 1;
		if (i%2==0 && a[i]<=a[i+1]) bad[i] = bad[i+1] = 1;
		if (bad[i]) {
			pos.push_back(i);
			pos.push_back(i+1);
		}
	}
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	if (pos.size()>30) return printf("0\n"), 0;
	int ans = 0;
	for (int i: pos) {
		for (int j=1;j<=n;j++) {
			if (bad[j] && j<=i) continue;
			ans+=check(i,j);
		}
	}
	printf("%d\n",ans);

	return 0;
}