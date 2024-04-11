#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long double a,b,c,d;
int check(long double k){
	long double k1=min(min((a-k)*(d+k),(a-k)*(d-k)),min((a+k)*(d+k),(a+k)*(d-k)));
	long double k2=max(max((a-k)*(d+k),(a-k)*(d-k)),max((a+k)*(d+k),(a+k)*(d-k)));
	long double k3=min(min((b-k)*(c+k),(b-k)*(c-k)),min((b+k)*(c+k),(b+k)*(c-k)));
	long double k4=max(max((b-k)*(c+k),(b-k)*(c-k)),max((b+k)*(c+k),(b+k)*(c-k)));
	return max(k1,k3)<=min(k2,k4);
}
int main(){
	long double l=1e9,r=-1e9;
	double k1; scanf("%lf",&k1); a=k1; l=min(l,a); r=max(r,a);
	scanf("%lf",&k1); b=k1; l=min(l,b); r=max(r,b);
	scanf("%lf",&k1); c=k1; l=min(l,c); r=max(r,c);
	scanf("%lf",&k1); d=k1; l=min(l,d); r=max(r,d);
	r=r-l+1; l=0;
	for (int i=1;i<=80;i++){
		long double mid=(l+r)/2;
		if (check(mid)) r=mid; else l=mid;
	}
	printf("%.15lf\n",(double)(l+r)/2.0);
	return 0;
}