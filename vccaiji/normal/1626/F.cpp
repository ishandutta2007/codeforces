#include<bits/stdc++.h>
using namespace std;
int p=998244353;
int n;
int a[11000000];
int k;
int ans[13000000]={};
int t[20];
int main(){
	int a0,x,y,M;
	scanf("%d%d%d%d%d%d",&n,&a0,&x,&y,&k,&M);
	a[0]=a0;
	for(int i=1;i<=n-1;i++) a[i]=(y+1ll*a[i-1]*x)%M; 
	t[0]=1;
	for(int i=1;i<=k;i++) t[i]=(1ll*n*t[i-1])%p;
	int f=1;
	for(int i=k;i>=1;i--){
		int ff=(f/__gcd(f,i))*i;
		int oo=0;
		if(i<k) oo=(1ll*(k-i)*t[k-i-1])%p;
		for(int j=0;j<=f-1;j++){
			for(int jj=j-f+ff;jj>=j+f;jj-=f) ans[jj]=(1ll*oo*(jj-j)+ans[j])%p;
		}
		for(int j=ff-1;j>=0;j--) ans[j]=(1ll*(n-1)*ans[j]+1ll*t[k-i]*j+ans[j-j%i])%p;
		f=ff;
	}
	int anss=0;
	for(int i=0;i<=n-1;i++) anss=(anss+1ll*((1ll*k*t[k-1])%p)*(a[i]-a[i]%f)+ans[a[i]%f])%p;
	printf("%d",anss);
	return 0;
}