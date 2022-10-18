#include<bits/stdc++.h>
#define lf double
#define N 105
#define M 10005

int n,x,m,a[N];

lf f[N][M];

int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		m+=a[i];
		for(int j=i;j;j--)
			for(int k=m;k>=a[i];k--)
				f[j][k]+=f[j-1][k-a[i]]*j/((lf)n-j+1);
	}
	lf ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=m;j++)
			ans+=f[i][j]*std::min(((lf)n/(lf)(n-i)+1)*x*0.5,(lf)(m-j)/(lf)(n-i));
	printf("%.11lf\n",ans);
}