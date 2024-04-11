// author: xay5421
// created: Mon Sep 20 23:28:06 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
void NTT(vector<int>&a,int g,int lim){
	a.resize(lim);
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=lim>>1;(j^=k)<k;k>>=1);
	}
	vector<int>w(lim>>1);w[0]=1;
	for(int i=1;i<lim;i<<=1){
		int wn=po(g,(P-1)/(i<<1));
		for(int j=(i>>1)-1;j>0;--j)w[j<<1]=w[j];
		for(int j=1;j<i;j+=2)w[j]=mu(w[j-1],wn);
		for(int j=0;j<lim;j+=i<<1)
			for(int k=0;k<i;++k){
				int x=a[j+k],y=mu(a[i+j+k],w[k]);
				a[j+k]=ad(x,y),a[i+j+k]=su(x,y);
			}
	}
	if(g==332748118)for(int i=0,I=po(lim,P-2);i<(int)a.size();++i)a[i]=mu(a[i],I);
}
vector<int>operator*(vector<int>a,vector<int>b){
	if(SZ(a)<=50&&SZ(b)<=50){
		vector<int>c(SZ(a)+SZ(b)-1);
		rep(i,0,SZ(a)-1)rep(j,0,SZ(b)-1)uad(c[i+j],mu(a[i],b[j]));
		return c;
	}
	int need=(int)a.size()+b.size()-1,lim=1;
	while(lim<=need)lim<<=1;
	NTT(a,3,lim),NTT(b,3,lim);
	for(int i=0;i<lim;++i)a[i]=mu(a[i],b[i]);
	NTT(a,332748118,lim);
	return a.resize(need),a;
}
vector<int>operator+(vector<int>a,vector<int>b){
	if(a.size()<b.size()){
		for(int i=0;i<(int)a.size();++i)(b[i]+=a[i])%=P;
		return b;
	}else{
		for(int i=0;i<(int)b.size();++i)(a[i]+=b[i])%=P; 
		return a;
	}
}
vector<int>pinv(const vector<int>&a,int n=-1){
	if(n==-1)n=a.size();
	if(n==1)return vector<int>(1,po(a[0],P-2));
	vector<int>b=pinv(a,(n+1)>>1),tmp=vector<int>(a.begin(),a.begin()+n);
	int lim=1;
	while(lim<=n*2-2)lim<<=1;
	NTT(b,3,lim),NTT(tmp,3,lim);
	for(int i=0;i<lim;++i)b[i]=mu(su(2,mu(b[i],tmp[i])),b[i]);
	NTT(b,332748118,lim);
	return b.resize(n),b;
}
vector<int>pdao(const vector<int>&a){
	vector<int>b((int)a.size()-1);
	for(int i=1;i<(int)a.size();++i)b[i-1]=mu(a[i],i);
	return b;
}
vector<int>pji(const vector<int>&a){
	vector<int>b((int)a.size()+1);
	for(int i=0;i<(int)a.size();++i)b[i+1]=mu(a[i],po(i+1,P-2));
	return b;
}
vector<int>pln(const vector<int>&a){
	vector<int>b(pdao(a)*pinv(a));
	b.resize((int)a.size()-1);
	return pji(b);
}
vector<int>pexp(const vector<int>&a,int n=-1){
	if(n==-1)n=a.size();
	if(n==1)return vector<int>(1,1);
	vector<int>b=pexp(a,(n+1)>>1),c(b);
	c.resize(n),c=pln(c),--c[0];
	for(int i=0;i<n;++i)c[i]=su(a[i],c[i]);
	vector<int>d(b*c);
	return d.resize(n),d;
}
const int N=300005;
int n,m,K,pre[N],nex[N],num[N],tot[N];
struct ufs{
	int fa[N],bad[N];
	ufs(){rep(i,1,N-1)fa[i]=i,bad[i]=0;}
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	void mer(int k1,int k2){
		k1=fd(k1),k2=fd(k2);
		if(k1==k2)return;
		bad[k1]=bad[k1]|bad[k2];
		fa[k2]=k1;
	}
}o;
int main(){
	rd(n),rd(m),rd(K);
	rep(i,1,n){
		int sz;
		rd(sz);
		rep(j,1,sz){
			rd(num[j]);
		}
		rep(j,1,sz-1){
			if(nex[num[j]]!=0&&nex[num[j]]!=num[j+1]){
				o.bad[o.fd(num[j])]=1;
			}
			nex[num[j]]=num[j+1];
			if(pre[num[j+1]]!=0&&pre[num[j+1]]!=num[j]){
				o.bad[o.fd(num[j])]=1;
			}
			pre[num[j+1]]=num[j];
			o.mer(num[j],num[j+1]);
		}
	}
	rep(i,1,K){
		++tot[o.fd(i)];
	}
	vector<int>v;
	static int vis[N];
	int tim=0;
	auto chk=[&](int k1){
		++tim;
		while(k1){
			if(vis[k1]==tim)return 0;
			vis[k1]=tim;
			k1=nex[k1];
		}
		return 1;
	};
	rep(i,1,K)if(o.fd(i)==i){
		if(!o.bad[i]&&chk(i)){
			v.push_back(tot[i]);
		}
	}
	/*vector<int>res(prod(0,SZ(v)-1,v));
	res.resize(m+1);*/
	vector<int>res(m+1);
	uad(res[0],1);
	for(auto x:v){
		if(x<=m)usu(res[x],1);
	}
	res=pinv(res);
	printf("%d\n",res[m]);
	return 0;
}