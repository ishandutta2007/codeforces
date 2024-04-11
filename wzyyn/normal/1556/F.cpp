#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int mo=1000000007;
const int N=16,M=1<<14|5;
int n,a[N],e[N][N];
int f[M];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			e[i][j]=1ll*a[i]*power(a[i]+a[j],mo-2)%mo;
	for (int i=0;i<1<<n;i++) f[i]=1;
	for (int i=1;i<1<<n;i++)
		for (int j=(i-1)&i;j;j=(j-1)&i){
			int k=i-j,rp=1;
			for (int p=0;p<n;p++) if (j&(1<<p))
				for (int q=0;q<n;q++) if (k&(1<<q))
					rp=1ll*rp*e[p][q]%mo;
			f[i]=(f[i]+mo-1ll*f[j]*rp%mo)%mo;
		}
	int ans=0;
	for (int i=0;i<n;i++)
		for (int j=1;j<1<<n;j++)
			if (j&(1<<i)){
				int rp=1;
				for (int p=0;p<n;p++) if (j&(1<<p))
					for (int q=0;q<n;q++) if (!(j&(1<<q)))
						rp=1ll*rp*e[p][q]%mo;
				ans=(ans+1ll*f[j]*rp)%mo;
			}
	cout<<ans<<endl;
}