// author: xay5421
// created: Sun Nov 14 21:15:23 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int P;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
int n,K,fac[85],ifac[85],f1[85][85],f2[85][85],f3[85][85],pw[100005];
// f1[i][j]  i  j 
// f2[i][j]  i  j 
// f3[i][j]  i  j 
int C(int k1,int k2){
	if(k2<0||k1-k2<0)return 0;
	return mu(fac[k1],ifac[k2],ifac[k1-k2]);
}
int down(int k1,int k2){
	int res=1;
	rep(i,0,k2-1)res=mu(res,k1-i);
	return res;
}
int main(){
	scanf("%d%d%d",&n,&K,&P);
	pw[0]=1;
	rep(i,1,100004)pw[i]=ad(pw[i-1],pw[i-1]);
	fac[0]=1;
	rep(i,1,84)fac[i]=mu(fac[i-1],i);
	ifac[84]=po(fac[84],P-2);
	per(i,84,1)ifac[i-1]=mu(ifac[i],i);
	f1[0][0]=1;
	rep(i,1,n){
		rep(j,0,K){
			f1[i][j]=pw[i*j],f2[i][j]=down(pw[j]-1,i);
			rep(k,0,j-1){
				usu(f1[i][j],mu(f1[i][k],C(j,k)));
				usu(f2[i][j],mu(f2[i][k],C(j,k)));
			}
		}
	}
	auto F=[&](int i,int j,int i_,int j_){
		return mu(f2[i-i_][j-j_],C(i,i_),C(j,j_),pw[(i-i_)*j_]);
	};
	rep(i,1,n){
		rep(j,0,K){
			rep(i_,0,i-1){
				if(i==n&&(n&1)&&i_==i-1)continue;
				rep(j_,0,j-1){
					uad(f3[i][j],mu(F(i,j,i_,j_),su(f1[i_][j_],f3[i_][j_])));
				}
			}
		}
	}
	int ans=0;
	rep(j,0,K){
		uad(ans,mu(C(K,j),su(f1[n][j],f3[n][j])));
	}
	printf("%d\n",ans);
	return 0;
}