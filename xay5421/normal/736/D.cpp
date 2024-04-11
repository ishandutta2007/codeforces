// author: xay5421
// created: Mon Nov 30 22:11:58 2020
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=2005,M=500005;
int n,m,u[M],v[M];
bitset<N*2>f[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d",&u[i],&v[i]);
		f[u[i]][v[i]]=1;
	}
	rep(i,1,n){
		f[i][i+n]=1;
	}
	rep(i,1,n){
		if(!f[i][i]){
			rep(j,i+1,n)if(f[j][i]){swap(f[i],f[j]);break;}
		}
		rep(j,1,n)if(i!=j&&f[j][i])f[j]^=f[i];
	}
	rep(i,1,m){
		puts(f[v[i]][u[i]+n]?"NO":"YES");
	}
	return 0;
}