#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
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
const int N=100005;
int n,l,r,ans;
int t[N*4],c[N];
int p[N],mind[N];
bool ban[N];
void sieve(){
	ban[0]=ban[1]=1;
	rep(i,2,N-1){
		if(!ban[i]){
			p[++*p]=i,mind[i]=i;
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			mind[i*p[j]]=p[j];
			if(i%p[j]==0){
				break;
			}
		}
	}
}
void upd(int k1){
	t[k1]=mu(t[k1*2],t[k1*2+1]);
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		if(k2!=1){
			assert(c[k2]>=0);
			t[k1]=po(k2,c[k2]);
		}else{
			t[k1]=1;
		}
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void fix(int k1,int k2,int k3,int k4){
	if(k2==k3){
		if(k2!=1){
			assert(c[k2]>=0);
			t[k1]=po(k2,c[k2]);
		}
		return;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)fix(k1*2,k2,mid,k4);else fix(k1*2+1,mid+1,k3,k4);
	upd(k1);
}
void add(int x,int dt){
	while(x>1){
		int y=mind[x];
		while(x%y==0){
			c[y]+=dt;
			x/=y;
		}
		fix(1,1,n,y);
	}
}
int calc(int t){
	int res=0;
	rep(x,0,n)if(t+x<=n-x){
		if(x==0){
			fill(c,c+n+1,0);
			bud(1,1,n);
			rep(i,n-t+1,n)add(i,1);
			rep(i,1,t)add(i,-1);
		}else{
			add(n-t-x*2+2,1);
			add(n-t-x*2+1,1);
			add(x,-1);
			add(t+x,-1);
		}
		uad(res,::t[1]);
		// uad(res,mu(C[n][x],C[n-x][t+x]));
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	sieve();
	scanf("%d%d%d%d",&n,&P,&l,&r);
	uad(ans,calc(l));
	if(l+1<=r){
		uad(ans,calc(l+1));
		usu(ans,calc(r+1));
	}
	usu(ans,calc(r+2));
	printf("%d\n",ans);
	return 0;
}