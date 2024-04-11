// author: xay5421
// created: Thu Dec 17 08:58:49 2020
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
typedef __uint128_t bits;
bits full;
const int I100=po(100,P-2);
int n,p[10][10],f[130][10];
map<bits,int>mp[10];
int dfs(int k1,const bits&k2){
	if(k1==n){
		return k2==full;
	}
	if(mp[k1].count(k2))return mp[k1][k2];
	int&res=mp[k1][k2];
	vector<bits>b(n);
	rep(i,0,(1<<n)-1)if(k2>>i&1)rep(j,0,n-1)if(~i>>j&1)b[j]|=bits(1)<<(i^(1<<j));
	rep(i,0,(1<<n)-1){
		bits k3=k2;
		rep(j,0,n-1){
			if(i>>j&1)k3|=b[j];
		}
		uad(res,mu(f[i][k1],dfs(k1+1,k3)));
	}
	return res;
}
int main(){
	scanf("%d",&n);
	rep(i,0,n-1)rep(j,0,n-1)scanf("%d",&p[i][j]),p[i][j]=mu(p[i][j],I100);
	rep(i,0,(1<<n)-1){
		full|=bits(1)<<i;
		rep(j,0,n-1){
			f[i][j]=1;
			rep(k,0,n-1){
				if(i>>k&1)f[i][j]=mu(f[i][j],p[j][k]);
				else f[i][j]=mu(f[i][j],su(1,p[j][k]));
			}
		}
	}
	bits tem=1;
	printf("%d\n",dfs(0,tem));
	return 0;
}