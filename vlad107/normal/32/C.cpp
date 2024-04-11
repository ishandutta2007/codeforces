#include <stdio.h>
int n,m,s;
long long f(long long x){
	long long res=x/s+1;
	int k=0;
	while (k<=x){
		long long cr=(x-k)/s+1;
		if (cr!=res)break;k++;
	}
	return res*k;
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	--n;--m;
	if (s>n&&s>m)
		printf("%I64d\n",(n+1)*1LL*(m+1));
	else printf("%I64d\n",f(n)*f(m));
}