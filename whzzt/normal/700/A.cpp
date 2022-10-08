#include<bits/stdc++.h>

using namespace std;

int n,dis,v1,v2,k,m;
bool check(double t){
	double x=(dis*1.0/v1-t)/(1.0/v1-1.0/v2);
	double T=x/v2;
	double cur=T+T*(v2-v1)/(v1+v2);
	return cur*(m-1)+T<=t;
}

int main(){
	cin>>n>>dis>>v1>>v2>>k;m=(n+k-1)/k;
	double l=0,r=dis*1.0/v1,mid=(l+r)*0.5;
	for (int i=0;i<100;i++) {
		if(check(mid)) r=mid; else l=mid;
		mid=(l+r)*0.5;
	}
	printf("%.6lf\n",mid);
	return 0;
}