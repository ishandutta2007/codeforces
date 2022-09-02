#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,x[N],y[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	long double all=1-pow(0.5,n)*(1+n+1ll*n*(n-1)/2);
//	cout<<all<<endl;
	long double ans=0;
	for(int k=1;k<n;++k){
		long double k1=pow(0.5,k-1)*(1-pow(0.5,n-1-k))/all/4.;
		for(int i=1,j=k%n+1;i<=n;++i,j=j%n+1){
//			printf("%d %d %d %Lf\n",k,i,j,k1);
			ans+=k1*(1ll*x[i]*y[j]-1ll*x[j]*y[i]-abs(__gcd(x[i]-x[j],y[i]-y[j])));
		}
//		printf("%d:%Lf\n",k,ans);
		if(clock()>=2.2*CLOCKS_PER_SEC)break;
	}
	printf("%.10lf\n",(double)ans/2+1);
	return 0;
}