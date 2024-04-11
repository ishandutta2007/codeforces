#include <bits/stdc++.h>
using namespace std;

int p[200013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

int n;
int to[200013];
int b[200013];
int has[200013];

int main() {
	scanf("%d",&n);
	iota(p,p+n+1,0);
	for (int i=1;i<=n;i++) {
		scanf("%d",&to[i]);
		merge(i,to[i]);
	}
	int turns = 0;
	for (int i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		if (b[i]) has[find(i)]+=1;
		turns+=b[i];
	}
	int tot = 0;
	for (int i=1;i<=n;i++) {
		tot+=(find(i)==i);
	}
	if (tot==1) tot = 0;
	printf("%d\n",tot+(turns%2==0));

	return 0;
}