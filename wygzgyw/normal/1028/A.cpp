#include <bits/stdc++.h>
using namespace std;
const int maxn=120;
int n,m,x,y,cnt;
char s[maxn];
int main() {
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			if (s[j]=='B') cnt++,x+=i,y+=j;
	}
	printf("%d %d\n",x/cnt,y/cnt);
	return 0;
}