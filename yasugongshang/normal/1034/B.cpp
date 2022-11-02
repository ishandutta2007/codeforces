#include<cstdio>
long long calc(int n,int m){
	if(n==1)return m/6*6+(m%6<3?0:m%6-3)*2;
	if(n==2){
		if(m==2)return 0;
		if(m==3||m==7)return 1ll*n*m-2;
		return 1ll*n*m;
	}
	if(n%2==1&&m%2==1)return 1ll*n*m-1;
	return 1ll*n*m;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m){int t=n;n=m;m=t;}
	printf("%lld\n",calc(n,m));
}