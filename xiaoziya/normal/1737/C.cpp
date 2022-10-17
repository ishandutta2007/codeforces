#include<bits/stdc++.h>
using namespace std;
int T,n,X,Y,flg,x[3],y[3];
inline int chk(int a,int b){
	return a==1||a==n||b==1||b==n;
}
inline int get(int u,int v){
	if(abs(x[u]-x[v])+abs(y[u]-y[v])==1){
		int p=2*x[v]-x[u],q=2*y[v]-y[u];
		if(p==X&&q==Y)
			return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d%d%d%d",&n,&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&X,&Y);
		flg=0;
		for(int i=0;i<=2;i++)
			flg|=(X==x[i]&&Y==y[i]);
		if(chk(x[0],y[0])&&chk(x[1],y[1])&&chk(x[2],y[2])){
			for(int i=0;i<=2;i++)
				if((x[i]==1||x[i]==n)&&(y[i]==1||y[i]==n))
					flg|=X==x[i]||Y==y[i];
			puts(flg==0? "NO":"YES");
			continue;
		}
		int o[2][2]={0,0,0,0};
		o[x[0]&1][y[0]&1]=o[x[1]&1][y[1]&1]=o[x[2]&1][y[2]&1]=1;
		flg|=o[X&1][Y&1];
		puts(flg==0? "NO":"YES");
	}
	return 0;
}