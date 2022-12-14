#include<cstdio>

using namespace std;

double ex(double a,int n){
	if(n==0) return 1;
	double tmp=ex(a,n/2);
	tmp*=tmp;
	if(n%2==1) tmp*=a;
	return tmp;
}

int main(){
	int M,N;
	scanf("%d%d",&M,&N);
	double ans=M;
	for(int i=1;i<M;i++){
		double tmp=ex((double)i/M,N);
		ans-=tmp;
	}
	printf("%.9f\n",ans);
	return 0;
}