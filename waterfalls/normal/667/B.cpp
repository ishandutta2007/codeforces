#include <bits/stdc++.h>
using namespace std;

int n;
int l[100013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&l[i]);
	int tot = accumulate(l,l+n,0);
	int high = *max_element(l,l+n);
	printf("%d\n",2*high-tot+1);

	return 0;
}