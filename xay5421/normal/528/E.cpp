#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,A[N],B[N],C[N];double ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&A[i],&B[i],&C[i]);
		if(B[i]<0)A[i]*=-1,B[i]*=-1,C[i]*=-1;
	}
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(A[i]*B[j]>A[j]*B[i])swap(A[i],A[j]),swap(B[i],B[j]),swap(C[i],C[j]);
//	for(int i=1;i<=n;++i)printf("k:%lf\n",-1.*A[i]/B[i]);
	for(int i=1;i<=n;++i){
		double x=0,y=0;
		for(int j=i%n+1,k=1;k<n;j=j%n+1,++k){
			double xx=1.*(B[j]*C[i]-B[i]*C[j])/(B[j]*A[i]-B[i]*A[j]);
			double yy=1.*(A[j]*C[i]-A[i]*C[j])/(A[j]*B[i]-A[i]*B[j]);
//			printf("%lf %lf\n",xx,yy);
			ans+=xx*y-yy*x,x+=xx,y+=yy;
//			printf("%lf\n",ans);
		}
	}
	printf("%.20lf\n",ans*3/n/(n-1)/(n-2));
	return 0;
}