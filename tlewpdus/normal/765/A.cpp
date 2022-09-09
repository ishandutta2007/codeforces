#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int n;
char buf[10000];

int main() {
	int i;
	scanf("%d",&n);
	gets(buf);
	for (i=0;i<n+1;i++) gets(buf);
	if (n%2) printf("contest\n");
	else printf("home\n");
	return 0;
}