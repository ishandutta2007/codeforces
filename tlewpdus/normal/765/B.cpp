#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>

using namespace std;

int n;
char buf[10000];

int main() {
	int i, p = 0, flag = 1;
	gets(buf);
	n = strlen(buf);
	for (i=0;i<n;i++) {
		if (buf[i]<'a'+p) {}
		else if (buf[i]=='a'+p) p++;
		else flag = 0;
	}
	if (!flag) printf("NO\n");
	else printf("YES\n");

	return 0;
}