#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,d,a[100005],g[100005][10],o[100005],m;
long double b[100005],f[100005][10];
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)scanf("%d",a+i),b[i]=log(a[i]);
	for(int i=0;i<=9;++i)f[0][i]=-orz;
	f[0][1]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=9;++j)f[i][j]=f[i-1][j],g[i][j]=j;
		for(int j=0;j<=9;++j){
			int k=j*a[i]%10;
			if(f[i-1][j]+b[i]>=f[i][k]-1e-10)f[i][k]=f[i-1][j]+b[i],g[i][k]=j;
		}
	}
	if(f[n][d]<-1e-10){
		puts("-1");
		return 0;
	}
	for(int i=n;i;--i){
		if(g[i][d]*a[i]%10==d){
			o[++m]=i;
			d=g[i][d];
		}
	}
	if(!m){
		puts("-1");
		return 0;
	}
	printf("%d\n",m);
	for(int i=1;i<m;++i)printf("%d ",a[o[i]]);
	printf("%d\n",a[o[m]]);
    return 0;
}