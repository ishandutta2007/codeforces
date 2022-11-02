#include <bits/stdc++.h>
using namespace std;
int n,k,mx;
char s[60];
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d %d %s",&n,&k,s+1);
	for (int i=1;i<n;i++) {
		bool flag=1;
		for (int j=1;j<=i;j++)
			if (s[j]!=s[n-i+j]) {
				flag=0; break;
			}
		if (flag) mx=max(mx,i);
	}
	printf("%s",s+1);
	for (int i=2;i<=k;i++)
		for (int j=mx+1;j<=n;j++)
			printf("%c",s[j]);
	printf("\n");
	return 0;
}