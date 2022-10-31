#include <bits/stdc++.h>
using namespace std;

int p[100013];
int s[100013], e[100013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) {
	e[find(a)]+=1;
	if (find(a)==find(b)) return;
	s[find(b)]+=s[find(a)];
	e[find(b)]+=e[find(a)];
	p[find(a)] = find(b);
}

int n,m;

int main() {
	scanf("%d%d",&n,&m);
	iota(p,p+n+1,0);
	fill(s,s+n+1,1);
	for (int i=0;i<m;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	int ans = 0;
	for (int i=1;i<=n;i++) if (find(i)==i) {
		if (e[i]==s[i]-1) ans+=1;
	}
	printf("%d\n",ans);

	return 0;
}