#include <bits/stdc++.h>
using namespace std;

int n,k;
char s[1000013];
int z[1000013];
int a[1000013];

int main() {
	scanf("%d%d %s",&n,&k,&s);
	int l = 0, r = 0;
	for (int i=1;i<n;i++) {
		z[i] = min(z[i-l],max(0,r-i));
		while (s[i+z[i]]==s[z[i]]) z[i]+=1;
		if (i+z[i]>r) l = i, r = i+z[i];
	}
	for (int sum=1;sum<=n;sum++) {
		if (z[sum]<1LL*(k-1)*sum) continue;
		a[sum*k-1]+=1;
		a[sum*k+min(z[sum*k],sum)]-=1;
	}
	for (int i=1;i<n;i++) a[i]+=a[i-1];
	for (int i=0;i<n;i++) printf("%d",a[i] ? 1 : 0);
	printf("\n");

	return 0;
}