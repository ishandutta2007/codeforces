#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,p,a[110000],b[110000];
int check(double k){
	double need=0;
	for (int i=1;i<=n;i++){
		double k1=1.0*b[i]/a[i];
		if (k1<k) need+=(k-k1)*a[i]/p;
	}
//	cout<<"fa "<<need<<" "<<k<<endl;
	return need<=k;
}
int main(){
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	double l=0,r=1e15;
	if (check(r)){
		printf("-1\n"); return 0;
	}
	for (int i=1;i<=100;i++){
		double mid=(l+r)/2;
		if (check(mid)) l=mid; else r=mid;
	}
	printf("%.11lf\n",(l+r)/2);
	return 0;
}