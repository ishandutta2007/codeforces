#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,u[207],ans=-1;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;++i){
			scanf("%d",&u[i]);
		}
		ans=max(u[1],n-u[m]+1);
		for (int i=1;i<m;++i){
			ans=max(ans,(u[i+1]-u[i])/2+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}