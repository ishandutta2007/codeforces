#include <bits/stdc++.h>
using namespace std;

int n,k;
char s[100013];
int sums[100013];

bool check(int d) {
	for (int i=1;i<=n;i++) {
		if (s[i]=='1') continue;
		int low = max(1,i-d);
		int high = min(n,i+d);
		if (sums[high]-sums[low-1]>=k) return true;
	}
	return false;
}

int main() {
	scanf("%d%d %s",&n,&k,s+1);
	k+=1;
	for (int i=1;i<=n;i++) sums[i] = sums[i-1]+(s[i]=='0');
	int low = 0;
	int high = n;
	while (high-low>1) {
		if (check((low+high+1)/2)) high = (low+high+1)/2;
		else low = (low+high+1)/2;
	}
	printf("%d\n",high);

	return 0;
}