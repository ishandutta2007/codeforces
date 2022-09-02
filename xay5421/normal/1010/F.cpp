// author: xay5421
// created: Wed Jan  6 19:45:22 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=100005;
const int P=998244353;
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
void NTT(deque<int>&a,int g,int lim){
	a.resize(lim);
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=lim>>1;(j^=k)<k;k>>=1);
	}
	deque<int>w(lim>>1);
	w[0]=1;
	for(int i=1;i<lim;i<<=1){
		for(int j=1,wn=po(g,(P-1)/(i<<1));j<i;++j)w[j]=mu(w[j-1],wn);
		for(int j=0;j<lim;j+=i<<1){
			for(int k=0;k<i;++k){
				int x=a[j+k],y=mu(a[i+j+k],w[k]);
				a[j+k]=ad(x,y),a[i+j+k]=su(x,y);
			}
		}
	}
	if(g!=3){
		const int I=po(lim,P-2);
		rep(i,0,lim-1)a[i]=mu(a[i],I);
	}
}
deque<int>operator*(deque<int>a,deque<int>b){
	int need=SZ(a)+SZ(b)-1,lim=1;
	while(lim<=need)lim<<=1;
	NTT(a,3,lim),NTT(b,3,lim);
	rep(i,0,lim-1)a[i]=mu(a[i],b[i]);
	NTT(a,332748118,lim);
	return a.resize(need),a;
}
deque<int>operator+(deque<int>a,deque<int>b){
	if(SZ(a)>SZ(b))swap(a,b);
	rep(i,0,SZ(a)-1)uad(b[i],a[i]);
	return b;
}
int n,sz[N],son[N],fa[N]; LL x;
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs1(int k1,int k2){
	sz[k1]=1,fa[k1]=k2;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dfs1(to[i],k1),sz[k1]+=sz[to[i]];
		if(sz[to[i]]>sz[son[k1]])son[k1]=to[i];
	}
}
deque<int>sol(int k1){
	if(!son[k1])return{0,1};
	vector<deque<int> >f;
	for(int k2=k1;k2;k2=son[k2]){
		deque<int>t;
		for(int i=lnk[k2];i;i=nxt[i])if(to[i]!=fa[k2]&&to[i]!=son[k2])t=sol(to[i]);
		if(t.empty())t={0};
		++t[0];
		t.push_front(0);
		f.push_back(t);
	}
	function<void(int,int,deque<int>&,deque<int>&)>fun=[&](int l,int r,deque<int>&g,deque<int>&h){
		if(l==r){
			g=h=f[l];
			return;
		}
		deque<int>gl,gr,hl,hr;
		int mid=(l+r)>>1;
		fun(l,mid,gl,hl),fun(mid+1,r,gr,hr);
		g=gl*gr,h=hl+gl*hr;
	};
	deque<int>g,h;
	fun(0,SZ(f)-1,g,h);
	return h;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%lld",&n,&x);
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	dfs1(1,0);
	deque<int>res(sol(1));
	int ans=0,w=1;
	rep(i,1,SZ(res)-1){
		uad(ans,mu(res[i],w));
		w=mu(w,mu(int((x+i)%P),po(i,P-2)));
	}
	printf("%d\n",ans);
	return 0;
}