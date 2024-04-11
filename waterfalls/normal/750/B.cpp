#include <bits/stdc++.h>
using namespace std;

int n;
char dir[113];

void quit() {
	printf("NO\n");
	exit(0);
}

int main() {
	scanf("%d",&n);
	int h = 0;
	for (int i=0;i<n;i++) {
		int d;
		scanf("%d %s",&d,&dir);
		if (h==0 && dir[0]!='S') quit();
		if (h==20000 && dir[0]!='N') quit();
		if (dir[0]=='E' || dir[0]=='W') continue;
		if (dir[0]=='N') h-=d;
		else h+=d;
		if (h<0 || h>20000) quit();
	}
	if (h!=0) quit();
	printf("YES\n");

	return 0;
}