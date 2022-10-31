#include <bits/stdc++.h>
using namespace std;

int n;
char s[213];

int main() {
	scanf("%d %s",&n,&s);
	int ans = 0;
	for (int i=0;i<n;i++) for (int j=i;j<n;j++) {
		int dx = 0;
		int dy = 0;
		for (int k=i;k<=j;k++) {
			if (s[k]=='U') dx-=1;
			if (s[k]=='D') dx+=1;
			if (s[k]=='L') dy-=1;
			if (s[k]=='R') dy+=1;
		}
		if (!dx && !dy) ans+=1;
	}
	printf("%d\n",ans);

	return 0;
}