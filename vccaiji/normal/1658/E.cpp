#include<bits/stdc++.h>
using namespace std;
int a[2100][2100];
int b[4100000];
int c[4100000];
bool ans[2100][2100]={};
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			b[a[i][j]]=i;
			c[a[i][j]]=j;
		}
	}
	int maxx1=-1000000,maxx2=-1000000,minn1=1000000,minn2=1000000;
	for(int i=n*n;i>=1;i--){
		int u=b[i],v=c[i];
		if((maxx1<=u+v+k)&&(minn1>=u+v-k)&&(maxx2<=u-v+k)&&(minn2>=u-v-k)){
			ans[u][v]=1;
			maxx1=max(maxx1,u+v);
			maxx2=max(maxx2,u-v);
			minn1=min(minn1,u+v);
			minn2=min(minn2,u-v);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans[i][j]) printf("M");
			else printf("G");
		}
		printf("\n");
	}
	return 0;
}