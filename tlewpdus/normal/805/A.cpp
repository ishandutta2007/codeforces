#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int l, r;
	scanf("%d%d",&l,&r);
	if (r>=l+1) printf("2\n");
	else printf("%d\n",l);
	return 0;
}