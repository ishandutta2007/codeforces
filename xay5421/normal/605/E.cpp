#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=1005;
int n;
double p[N],E[N],a[N][N];
bool vis[N];
template<typename T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1)p[i]=1.,E[i]=1.;
	rep(i,1,n)rep(j,1,n){
		scanf("%lf",&a[i][j]),a[i][j]/=100.;
	}
	rep(i,1,n){
		double mn=1e100;
		int pos=-1;
		rep(j,1,n){
			if(vis[j]||p[j]==1.)continue;
			if(umin(mn,E[j]/(1.-p[j])))pos=j;
		}
		if(pos==-1)break;
		vis[pos]=1;
		E[pos]=mn;
		rep(j,1,n)if(!vis[j]){
			E[j]+=mn*p[j]*a[j][pos];
			p[j]*=1.-a[j][pos];
		}
	}
	printf("%.20f\n",E[1]);
	return 0;
}