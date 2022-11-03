#include<bits/stdc++.h>

using namespace std;

int n;
double p;

long long C(int x,int y){
	long long ret=1;
	for (int i=0;i<y;++i) ret*=x-i;
	for (int i=0;i<y;++i) ret/=y-i;
	return ret;
}

long long calc(int m){
	long long ret=0;
	for (int i=1;i<=3;++i){
		long long P=C(m,i)*C(n-m,3-i);
		if (i>=2) ret+=P*2;
		if (i==1) ret+=P;
	}
	return ret;
}

int main(){
	scanf("%d%lf",&n,&p);
	long long np=(p+1e-8)*10000;
	for (int i=0;i<=n;++i){
		if (calc(i)*10000>=np*C(n,3)*2){printf("%d\n",i); return 0;}
	}
	
	return 0;
}