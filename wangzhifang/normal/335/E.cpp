#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_n 30000
#define max_h 30
using namespace std;
char str[10];
double pw2[max_h+1],ipw2[max_h+2];
template<typename T,typename Tp>T quickpow(T x,Tp k){
	T ret=1;
	for(; k; k>>=1,x*=x)
		(k&1)&&(ret*=x);
	return ret;
}
int main(){
	int n,h;
	double ans;
	scanf("%s%d%d",str,&n,&h);
	if(str[0]=='B'){
		printf("%d\n",n);
		return 0;
	}
	pw2[0]=ipw2[0]=1;
	for(int i=0; ++i<=h; pw2[i]=pw2[i-1]*2,ipw2[i]=ipw2[i-1]/2);
	ans=n,ipw2[h+1]=ipw2[h]/2;
	for(int i=0; ++i<=h; )
		for(int j=0; ++j<n; ans+=(ipw2[i]-ipw2[i+1]*((j-1)/(pw2[i]-1)+1))*(n-j)*quickpow(1-ipw2[i],j-1));
	printf("%.9lf\n",ans);
	return 0;
}