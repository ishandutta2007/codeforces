// author: xay5421
// created: Mon Nov 15 16:08:03 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244353;
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
struct ufs{
	int n;
	vector<int>fa;
	ufs(int n):n(n){
		fa.assign(n,0);
		rep(i,0,n-1)fa[i]=i;
	}
	int fd(int k1){
		return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);
	}
	int chk(int k1,int k2){
		return fd(k1)==fd(k2);
	}
	int mer(int k1,int k2){
		k1=fd(k1),k2=fd(k2);
		if(k1==k2)return 0;
		fa[k1]=k2;
		return 1;
	}
};
const int N=255;
int n,p[N],q[N],base_cyc,nex[N],pre[N],w[2][2],vis[N],S1[N][N],fac[N],inv[N],ifac[N],f1[N],f2[N],f3[N],ans[N];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
void init(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	S1[0][0]=1;
	rep(i,1,n)rep(j,1,n){
		S1[i][j]=ad(mu(S1[i-1][j],i-1),S1[i-1][j-1]);
	}
}
int down(int k1,int k2){
	if(k2==0)return 1;
	if(k1<0||k1-k2<0)return 0;
	return mu(fac[k1],ifac[k1-k2]);
}
int main(){
	scanf("%d",&n);
	init();
	ufs o(n+1);
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n)scanf("%d",&q[i]);
	rep(i,1,n){
		if(p[i]!=0&&q[i]!=0){
			if(!o.mer(p[i],q[i])){
				++base_cyc;
			}
		}
	}
	rep(i,1,n){
		if(p[i]==0&&q[i]==0){
			++w[0][0];
		}else if(p[i]==0){
			++w[0][1];
			vis[o.fd(q[i])]|=1;
		}else if(q[i]==0){
			++w[1][0];
			vis[o.fd(p[i])]|=2;
		}
	}
	rep(i,1,n)if(vis[i]==3)--w[0][1],--w[1][0],++w[0][0];
	rep(i,0,w[0][1]){
		rep(j,i,w[0][1]){
			uad(f1[i],mu(C(w[0][1],j),S1[j][i],down(w[0][0]+w[0][1]-j-1,w[0][1]-j)));
		}
	}
	rep(i,0,w[1][0]){
		rep(j,i,w[1][0]){
			uad(f2[i],mu(C(w[1][0],j),S1[j][i],down(w[0][0]+w[1][0]-j-1,w[1][0]-j)));
		}
	}
	rep(i,0,w[0][0]){
		f3[i]=mu(S1[w[0][0]][i],fac[w[0][0]]);
	}
	rep(a,0,w[0][1])rep(b,0,w[1][0])rep(c,0,w[0][0]){
		uad(ans[a+b+c],mu(f1[a],f2[b],f3[c]));
	}
	rep(i,0,n-1){
		if(n-base_cyc-i<0)printf("%d ",0);
		else printf("%d ",ans[n-base_cyc-i]);
	}
	return 0;
}