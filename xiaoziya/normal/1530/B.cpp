#include<stdio.h>
const int maxn=25;
int T,h,w;
int a[maxn][maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&h,&w);
		for(int i=1;i<=w;i+=2)
			a[1][i]=1;
		for(int i=3;i<=h;i+=2)
			a[i][1]=a[i][w]=1;
		for(int i=2;i<w;i++)
			if(a[h][i-1]==0&&a[h][i+1]==0&&a[h-1][i-1]==0&&a[h-1][i+1]==0)
				a[h][i]=1;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++)
				printf("%d",a[i][j]),a[i][j]=0;
			puts("");
		}
		puts("");
	}
	return 0;
}