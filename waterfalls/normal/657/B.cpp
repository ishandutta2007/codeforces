#include <bits/stdc++.h>
using namespace std;

int n,k,on;
int x[200113];
int a[200113];
int b[200113];

bool sub() {
	for (int i=n+on;i>0;i--) {
		a[i]-=b[i];
		if (a[i]<0) {
			int j = i-1;
			while (j && a[j]==0) j-=1;
			if (j==0) {
				a[i]+=b[i];
				return true;
			}
			a[j] = 0;
			while (j<i) {
				j+=1;
				a[j] = 1;
			}
		}
		b[i] = 0;
	}
	return false;
}

int main() {
	scanf("%d%d",&n,&k);
	on = 100;
	for (int i=n+on;i>=on;i--) {
		scanf("%d",&a[i]);
		x[i] = a[i];
		if (a[i]<0) {
			a[i]+=(1<<30);
			b[i-30]+=1;
		}
	}
	for (int i=n+on;i>0;i--) {
		a[i-1]+=a[i]/2;
		a[i]%=2;
	}
	bool neg = sub();
	if (neg) {
		swap(a,b);
		sub();
	}
	vector<int> has;
	for (int i=0;i<=n+on;i++) {
		if (a[i]) has.push_back(i);
	}
	int ans = 0;
	for (int i=on;i<=n+on;i++) {
		if (has.back()>i) continue;
		if (has.front()<i-40) continue;
		long long cur = 0;
		for (int j=i-40;j<=i;j++) {
			cur*=2;
			cur+=a[j];
		}
		if (neg) cur = -cur;
		long long can = x[i]-cur;
		if (can==0 && i==on) continue;
		if (abs(can)<=k) ans+=1;
	}
	printf("%d\n",ans);

	return 0;
}