#include<bits/stdc++.h>
#define N 200005
#define W 20

int T;

int s[W][N];

int main(){
	for(int i=1;i<=2e5;i++)
		for(int j=0;j<W;j++)
			s[j][i]=s[j][i-1]+((i>>j)&1);
	scanf("%d",&T);
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=0;
		for(int i=0;i<W;i++)
			ans=std::max(ans,s[i][r]-s[i][l-1]);
		printf("%d\n",r-l+1-ans);
	}
}