#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,h;
int main(){
	scanf("%d%d",&n,&h);
	for (int i=1;i<n;i++){
		double k=1.0*i/n;
		double ans=sqrt(k)*h;
		printf("%.11f ",ans);
	}
	return 0;
}