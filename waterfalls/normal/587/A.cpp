#include <bits/stdc++.h>
using namespace std;

int n;
int a[1100013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		a[x]+=1;
	}
	int ans = 0;
	for (int i=0;i<1100012;i++) {
		a[i+1]+=a[i]/2;
		ans+=a[i]%2;
	}
	printf("%d\n",ans);

	return 0;
}