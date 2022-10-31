#include <bits/stdc++.h>
using namespace std;

int n;
int can[375][2];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		char c;
		int a,b;
		scanf(" %c%d%d",&c,&a,&b);
		for (int j=a;j<=b;j++) can[j][c=='M']+=1;
	}
	int high = 0;
	for (int i=1;i<=366;i++) high = max(high,min(can[i][0],can[i][1]));
	printf("%d\n",2*high);

    return 0;
}