#include <bits/stdc++.h>
using namespace std;

int x[3], y[3];

int main() {
	for (int i=0;i<3;i++) scanf("%d%d",&x[i],&y[i]);
	if (x[0]==x[1] && x[1]==x[2]) return printf("1\n"), 0;
	if (y[0]==y[1] && y[1]==y[2]) return printf("1\n"), 0;
	for (int i=0;i<3;i++) {
		if (x[0]==x[1] && (y[2]<=min(y[0],y[1]) || y[2]>=max(y[0],y[1]))) return printf("2\n"), 0;
		if (y[0]==y[1] && (x[2]<=min(x[0],x[1]) || x[2]>=max(x[0],x[1]))) return printf("2\n"), 0;
		rotate(x,x+1,x+3);
		rotate(y,y+1,y+3);
	}
	printf("3\n");

	return 0;
}