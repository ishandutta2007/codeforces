#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mo=1e9+7,N=200000;
int I[N+10],nI[N+10];
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int n,x[N+10],y[N+10],len;
int C(int k1,int k2){
	return 1ll*I[k1]*nI[k2]%mo*nI[k1-k2]%mo;
}
int main(){
	scanf("%d",&n); I[0]=1;
	for (int i=1;i<=n;i++) I[i]=1ll*I[i-1]*i%mo;
	for (int i=0;i<=n;i++) nI[i]=quick(I[i],mo-2);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	int now=1;
	while (1){
		if (n==1) break;
		if (now==1&&(n%2)==1) break;
		for (int i=1;i<n;i++){
			if (now==1) x[i]=(x[i]+x[i+1])%mo;
			else x[i]=(x[i]-x[i+1]+mo)%mo;
			now=-now;
		}
		n--;
	}
	//cout<<"asd "<<n<<endl;
	if (n>4){
		int N=n/4*4; 
		memcpy(y,x,sizeof x);
	//	for (int i=1;i<=n;i++) cout<<x[i]<<" "; cout<<endl;
		for (int i=1;i<=n-N;i++){
			int fir=i; x[i]=0;
			for (int j=0;j<=N/2;j++){
			//	cout<<i<<" "<<fir<<endl; 
				x[i]=(x[i]+1ll*C(N/2,j)*y[fir])%mo;
				fir+=2;
			}
		//	cout<<i<<" "<<n-N<<endl;
		}
		int lim=n-N;// cout<<lim<<endl;
		while (n>lim){
			if (n==lim) break; now=-now; n--;//cout<<n<<endl;
		}
	//	for (int i=1;i<=n;i++) cout<<x[i]<<" "; cout<<endl;
	}
	//cout<<"end "<<n<<endl;
	while (1){
		if (n==1) break;
		for (int i=1;i<n;i++){
			if (now==1) x[i]=(x[i]+x[i+1])%mo;
			else x[i]=(x[i]-x[i+1]+mo)%mo;
			now=-now;
		}
		n--;
	}
	printf("%d\n",x[n]);
	return 0;
}