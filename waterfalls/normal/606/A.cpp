#include <bits/stdc++.h>
using namespace std;

int one[3], two[3];

int main() {
	for (int i=0;i<3;i++) scanf("%d",&one[i]);
	for (int i=0;i<3;i++) scanf("%d",&two[i]);
	int a = 0,b = 0;
	for (int i=0;i<3;i++) {
		if (one[i]>two[i]) a+=(one[i]-two[i])/2;
		else b+=two[i]-one[i];
	}
	if (a>=b) printf("Yes\n");
	else printf("No\n");

	return 0;
}