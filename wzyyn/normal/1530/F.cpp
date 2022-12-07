#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int mo=31607;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int n,a[25][25];
int b[1<<23|5],c[1<<23|5],f[1<<21|5];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			a[i][j]=a[i][j]*power(10000,mo-2)%mo;
		}
	int M=(1<<(n+2))-1;
	for (int i=0;i<=M;i++) b[i]=1;
	for (int i=1;i<=n;i++){
		int dec=1;
		for (int j=1;j<=n;j++)
			dec=dec*a[i][j]%mo;
		for (int j=0;j<1<<n;j++) f[j]=1;
		for (int j=1;j<=n;j++) f[(1<<(j-1))]=a[i][j];
		for (int d=1;d<1<<n;d<<=1)
			for (int j=0;j<1<<n;j++)
				if (j&d) f[j]=f[j^d]*f[d]%mo;
		memset(c,0,sizeof(c));
		for (int j=0;j<=M;j++){
			int mat=(1<<n)-1-(j&((1<<n)-1));
			if (!(j&(2<<n))&&(j&(1<<(n-i)))) mat|=1<<(n-i);
			if (!(j&(1<<n))&&(j&(1<<(i-1)))) mat|=1<<(i-1);
			c[j]=(f[mat]+mo-dec)%mo;
		}
		for (int j=0;j<=M;j++)
			b[j]=b[j]*c[j]%mo;
	}
	for (int d=1;d<=M;d<<=1)
		for (int i=0;i<=M;i+=(d<<1))
			for (int j=0;j<d;j++)
				b[i+j+d]=(b[i+j+d]+mo-b[i+j])%mo;
	cout<<(1+mo-b[M])%mo<<endl;
}