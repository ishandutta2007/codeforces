#include <bits/stdc++.h>

using namespace std;

pair<double,double> cal(double a1,double b1,double c1,double a2,double b2,double c2){
	double dz=a1*b2-a2*b1,dx=b1*c2-b2*c1,dy=c1*a2-c2*a1;
	return pair<double,double>(-dx/dz,-dy/dz);
}
double solve(int n,int v1,int v2,int len){
	if (n==1) return (len+.0)/v1;
	n--;
	pair<double,double> cur=cal(2LL*n*v1,-(v2+v1),0,v1,v2,len);
	return cur.first+cur.second;
}
int main(){
	int n,len,v1,v2,k;
	cin>>n>>len>>v2>>v1>>k;
	n=(n+k-1)/k;
	printf("%.9f",solve(n,v1,v2,len));
}