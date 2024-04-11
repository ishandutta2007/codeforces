#include<bits/stdc++.h>

int T;

bool vis[105][105];

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<24;i++) for(int j=0;j<60;j++)
			vis[i][j]=0;
		int a,b,x;
		scanf("%02d:%02d %d",&a,&b,&x);
		int res=0;
		while(!vis[a][b]){
			vis[a][b]=1;
			res+=(a==b%10*10+b/10);
			b+=x,a+=b/60,b%=60,a%=24;
		}
		printf("%d\n",res);
	}
}