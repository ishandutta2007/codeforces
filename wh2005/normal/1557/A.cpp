#include<bits/stdc++.h>
using namespace std;
#define db double
const int N = 2e5+9;
const db inf =1e15+7;
int T,n;
db a[N],sum[N];

db aver(int l,int r){
	if(r<l) return 0;
	db t=0;
	for(int i=l;i<=r;i++) t+=a[i];
	t/=(db)(r-l+1);
	return t;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
		if(n==2){
			printf("%.10lf\n",a[1]+a[2]);
			continue;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) sum[i]=0;
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		db ans=-inf;
		for(int i=n-1;i<n;i++){
			ans=max(ans,sum[i]/i+(sum[n]-sum[i])/(n-i));
		}
		printf("%.10lf\n",ans);
	}	
	return 0;
}