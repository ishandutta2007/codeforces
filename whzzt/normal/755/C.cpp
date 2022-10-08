#include"bits/stdc++.h"
using namespace std;
const int N=10005;
int fa[N],n,sz;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	scanf("%d",&n);sz=n;int x;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		int fx=find(x),fi=find(i);
		if(fx!=fi)fa[fx]=fi,sz--;
	}
	printf("%d\n",sz);
	return 0;
}