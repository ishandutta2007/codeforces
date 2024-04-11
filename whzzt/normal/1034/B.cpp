#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll calc(int n,int m){
	if(n>m)swap(n,m);
	if(n==1)return m/6*3+(m%6>3?m%6-3:0);
	if(n==2){
		if(m<=2)return 0;
		if(m==3)return 2;
		if(m==7)return 6;
		return m;
	}
	if(n==3){
		if(m<=3)return 2*(m-1);
		return m/2*3+(m%2);
	}
	if(n==4)return m*2;
	return (ll)(n-2)/2*m+calc(n-(n-2)/2*2,m);
}
int main(){
	scanf("%d%d",&n,&m);
	printf("%lld\n",calc(n,m)*2);
}