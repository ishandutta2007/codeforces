#include<bits/stdc++.h> 
using namespace std;
const int p=1000000007;
int qow(int a,int n){
	int ans=1;
	for(;n;n>>=1){
		if(n&1)ans=1ll*ans*a%p;
		a=1ll*a*a%p;
	}
	return ans;
}
int inverse(int a){
	return qow(a,p-2);
}
int o[110][110];
int f[110];
int ans[110];
void gauss(int n){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(o[j][i]){
				for(int k=i;k<=n;k++)swap(o[i][k],o[j][k]);
				swap(f[i],f[j]);
				break;
			}
		}
		assert(o[i][i]);
		int u=inverse(o[i][i]);
		for(int j=i+1;j<=n;j++){
			int uu=1ll*u*(p-o[j][i])%p;
			for(int k=i;k<=n;k++)o[j][k]=(o[j][k]+1ll*o[i][k]*uu)%p;
			f[j]=(f[j]+1ll*f[i]*uu)%p;
		}
	}
	for(int i=n;i;i--){
		int t=f[i];
		for(int j=i+1;j<=n;j++)t=(t+1ll*(p-o[i][j])*ans[j])%p;
		ans[i]=1ll*t*inverse(o[i][i])%p;
	}
}
int maxy[110];
int ooo[110][110];
int oo[110][110][110];
int main(){
	int r,a1,a2,a3,a4,b;
	cin>>r>>a1>>a2>>a3>>a4;
	int u=inverse(a1+a2+a3+a4);
	a1=1ll*a1*u%p;
	a2=1ll*a2*u%p;
	a3=1ll*a3*u%p;
	a4=1ll*a4*u%p;
	b=inverse(a2);
	for(int i=-r;i<=r;i++){
		for(int j=0;i*i+j*j<=r*r;j++)maxy[i+r+1]=j;
	}
	for(int i=r;i>=-r;i--){
		for(int j=-r;j<=r;j++){
			if(i*i+j*j<=r*r){
				if(i<maxy[j+r+1]){
				    for(int k=1;k<=2*r+1;k++)oo[j+r+1][i+r][k]=(1ll*b*oo[j+r+1][i+r+1][k]%p+1ll*(p-a1)*b%p*oo[j+r][i+r+1][k]%p+1ll*(p-a3)*b%p*oo[j+r+2][i+r+1][k]%p+1ll*(p-a4)*b%p*oo[j+r+1][i+r+2][k]%p)%p;
				    ooo[j+r+1][i+r]=(p-b+1ll*b*ooo[j+r+1][i+r+1]%p+1ll*(p-a1)*b%p*ooo[j+r][i+r+1]%p+1ll*(p-a3)*b%p*ooo[j+r+2][i+r+1]%p+1ll*(p-a4)*b%p*ooo[j+r+1][i+r+2]%p)%p;
				}
				else oo[j+r+1][i+r][j+r+1]=1;
			}
		}
	}
	for(int i=-r;i<=r;i++){
		int j=-maxy[i+r+1];
		for(int k=1;k<=2*r+1;k++)o[i+r+1][k]=(1ll*a1*oo[i+r][j+r][k]%p+1ll*a3*oo[i+r+2][j+r][k]%p+1ll*a4*oo[i+r+1][j+r+1][k]%p+p-oo[i+r+1][j+r][k])%p;
		f[i+r+1]=(p-1+ooo[i+r+1][j+r]+3ll*p-1ll*a1*ooo[i+r][j+r]%p-1ll*a3*ooo[i+r+2][j+r]%p-1ll*a4*ooo[i+r+1][j+r+1]%p)%p;
	}
	gauss(2*r+1);
	int anss=ooo[r+1][r];
	for(int k=1;k<=2*r+1;k++)anss=(anss+1ll*oo[r+1][r][k]*ans[k])%p;
	cout<<anss;
	return 0;
}