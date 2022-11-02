#include <stdio.h>

#define N 200500
#define BASE 1000000007

using namespace std;

int n,m,g,f[N+5],r[N+5],res;

int pow(int x,int y){
	int res=1;
	while (y){
		if (y%2==1)res=((long long)(res)*x)%BASE;
		x=((long long)(x)*x)%BASE;
		y/=2;
	}
	return res;
}

int C(int k,int n){
	int res=((long long)f[n])*r[k]%BASE;
	res=((long long)res)*r[n-k]%BASE;
	return res;
}

int main(){
	scanf("%d%d%d",&n,&m,&g);
	f[0]=1;
	for (int i=1;i<=N;i++)f[i]=(((long long)f[i-1])*i)%BASE;
	for (int i=0;i<=N;i++)r[i]=pow(f[i],BASE-2);
	if (m==0){printf("%d\n",n%2==1-g);return 0;}
	for (int i=g;i<=n;i+=2)
		if (i+1<n+m)res=(res+C(n-i,n+m-i-1))%BASE;
	if ((n%2!=g)&&(m==1))res++;
	printf("%d\n",res);
}