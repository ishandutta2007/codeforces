#include <bits/stdc++.h>
using namespace std;

int a,b;
int ans[3];

int main() {
	scanf("%d%d",&a,&b);
	for (int i=1;i<=6;i++) {
		if (abs(i-a)<abs(i-b)) ans[0]+=1;
		if (abs(i-a)==abs(i-b)) ans[1]+=1;
		if (abs(i-a)>abs(i-b)) ans[2]+=1;
	}
	for (int i=0;i<3;i++) printf("%d ",ans[i]);
	printf("\n");

	return 0;
}