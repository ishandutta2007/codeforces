#include <bits/stdc++.h>
using namespace std;

int p[10013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

int n;

int main() {
	scanf("%d",&n);
	iota(p,p+n+1,0);
	for (int i=1;i<=n;i++) {
		int a;
		scanf("%d",&a);
		merge(i,a);
	}
	int ans = 0;
	for (int i=1;i<=n;i++) ans+=find(i)==i;
	printf("%d\n",ans);

	return 0;
}