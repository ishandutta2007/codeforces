// author: xay5421
// created: Sun Oct 24 21:29:25 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1005;
double f[N][N];
bool vis[N][N];
double sol(int n,int m){
	if(n==0){
		return f[0][m]=1./(m+1);
	}
	if(m==0){
		return f[n][0]=1;
	}
	if(vis[n][m])return f[n][m];
	vis[n][m]=1;
	double k1=1.*m/(m+1)*(1-sol(m-1,n))-1;
	double b1=1;
	double k2=1./(m+1)+1.*m/(m+1)*(1-sol(m-1,n))-(1-sol(m,n-1));
	double b2=1-sol(m,n-1);
	double p=(b1-b2)/(k2-k1);
	return f[n][m]=k1*p+b1;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%.20f %.20f\n",sol(n,m),1-sol(n,m));
	return 0;
}