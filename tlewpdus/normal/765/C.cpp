#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>

using namespace std;

int k, a, b;

int main() {
	int i;

	scanf("%d%d%d",&k,&a,&b);
	int am = a/k, bm = b/k;
	if ((a%k==0||bm>0)&&(b%k==0||am>0)) printf("%d\n",am+bm);
	else printf("-1\n");

	return 0;
}