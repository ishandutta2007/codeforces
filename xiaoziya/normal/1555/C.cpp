#include<stdio.h>
const int maxn=100005;
int T,n;
int a[3][maxn],pre[maxn],suf[maxn];
inline int min(int a,int b){
	return a<b? a:b;
}
inline int max(int a,int b){
	return a>b? a:b;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		pre[0]=suf[n+1]=0;
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]+a[2][i];
		for(int i=n;i>=1;i--)
			suf[i]=suf[i+1]+a[1][i];
		int ans=2000000000;
		for(int i=1;i<=n;i++)
			ans=min(ans,max(pre[i-1],suf[i+1]));
		printf("%d\n",ans);
	}
	return 0;
}