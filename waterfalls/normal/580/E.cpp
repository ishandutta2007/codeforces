#include <bits/stdc++.h>
using namespace std;

int n,m,k;
char s[100013];

int main() {
	scanf("%d%d%d %s",&n,&m,&k,&s);
	m+=k;
	for (int i=0;i<m;i++) {
		int t,l,r,c;
		scanf("%d%d%d%d",&t,&l,&r,&c);
		l-=1, r-=1;
		if (t==1) memset(s+l,c+'0',r-l+1);
		else printf("%s\n",memcmp(s+l,s+l+c,r-l+1-c) ? "NO" : "YES");
	}	
}