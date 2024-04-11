#include <bits/stdc++.h>
using namespace std;

int n;
int loc[100013];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int x;
		scanf("%d",&x);
		loc[x] = i;
	}
	int prev = 0;
	int ans = 0;
	for (int i=1;i<=n;i++) {
		if (loc[i]>loc[i-1]) prev+=1;
		else prev = 1;
		ans = max(ans,prev);
	}
	printf("%d\n",n-ans);

	return 0;
}