#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
ll n,m,k,po;
int main(){
	cin>>n;
	if(n<=0){puts("-1");return 0;}
	if(n%4==0){printf("%I64d %I64d\n",n/4*3,n/4*5);return 0;}
	for(po=1;n%2==0;po*=2,n/=2);
	if(n==1)puts("-1");
	else {
		m=(n*n-1)/2;k=m+1;
		printf("%I64d %I64d\n",m*po,k*po);
	}
	return 0;
}