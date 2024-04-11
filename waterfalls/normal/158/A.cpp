#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[100013];

int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int on = 1;
	while (a[on]>=a[k] && a[on]>0) on+=1;
	printf("%d\n",on-1);

	return 0;
}