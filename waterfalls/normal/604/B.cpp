#include <bits/stdc++.h>
using namespace std;

int n,k;
int w[100013];

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&w[i]);
	sort(w,w+n);
	int ans = 0;
	int two = max(0,n-k);
	for (int i=0;i<two;i++) ans = max(ans,w[i]+w[two*2-1-i]);
	for (int i=two*2;i<n;i++) ans = max(ans,w[i]);
	printf("%d\n",ans);

	return 0;
}