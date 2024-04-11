#include <bits/stdc++.h>
using namespace std;

set<int> e[30];
int n, a[100005], i, x, y, cnt, ds[30];
char c;

int ld(int x){return ds[x]=(ds[x]==x)?x:ld(ds[x]);}

int main(){
	for(i=0;i<30;i++) ds[i]=i;
	for(scanf("%d",&n),getchar(),i=1;i<=n;i++)
		c=getchar(),a[i]=c-'a';
	for(getchar(),i=1;i<=n;i++){
		c = getchar();
		y = c-'a';
		x = a[i];
		if(x>y) swap(x,y);
		if(x == y) continue;
		if(ld(x)==ld(y)) continue;
		ds[ld(x)] = ld(y);
		e[x].insert(y);
	}
	for(i=0;i<26;i++) cnt+=e[i].size();
	printf("%d\n",cnt);
	for(i=0;i<26;i++){
		for(auto v : e[i])
			printf("%c %c\n",i+'a',v+'a');
	}
	return 0;
}