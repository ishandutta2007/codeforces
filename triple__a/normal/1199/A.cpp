#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
int a[maxn],n,x,y;
bool ck(int u,int x,int y){
	for (int i=max(1,u-x);i<=min(n,u+y);++i){
		if (a[u]>a[i]) return 0; 
	}
	return 1;
}

int ans(){
	for (int i=1;i<=n;++i){
		if (ck(i,x,y)) return i;
	}
}
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	printf("%d\n",ans());
	return 0;
}