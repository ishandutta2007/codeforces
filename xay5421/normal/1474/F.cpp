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
using LL=long long;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
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
int norm(LL x){
	x%=P;
	if(x<0)x+=P;
	return x;
}
int n,m,dp[55][155],inv[155],ifac[155];
LL a[55],a_[55],b[155];
int down(LL x,int y){
	int z=1;
	rep(i,1,y)z=mu(z,norm(x-i+1));
	return z;
}
int C(LL x,int y){
	if(y<0||x-y<0)return 0;
	return mu(down(x,y),ifac[y]);
}
int calc(int up,int dw,LL len){
	int w1=1;
	int res=0;
	rep(i,0,dw){
		if(i){
			w1=mu(w1,dw-i+1);
			w1=mu(w1,inv[i]);
			//w2=mu(w2,po(len-i+up,P-2),len-i+1);
		}
		int w2=C(len-i+up-1,up-1);
		uad(res,mu(w1,w2));
	}
	return res;
}
int sol(int lb,int rb){
	rep(i,lb,rb){
		if(a[i]==a[lb])dp[i][a[i]]=1;
	}
	rep(i,lb+1,rb){
		for(int j=min(a_[i-1],a[i]);j<=max(a_[i-1],a[i]);++j){
			int up=0,dw=0;
			const LL len=b[j]-b[j-1]-1; // ?
			if(a[i-1]<a[i]){
				++up;
				uad(dp[i][j],mu(dp[i][j-1],calc(up,dw,len)));
			}
			per(k,i-1,lb){
				if(k>0&&a[k-1]<a[k]){
					if(a[k-1]<j&&j<=a[k]){
						++up;
					}
				}
				uad(dp[i][j],mu(dp[k][j-1],calc(up,dw,len)));
				if(k>0&&a[k-1]>a[k]){
					if(a[k-1]>j&&j>=a[k]){
						++dw;
					}
				}
			}
		}
	}
	int res=0;
	rep(i,lb,rb){
		if(a[i]==a[rb])uad(res,dp[i][a[i]]);
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	inv[0]=inv[1]=1;
	rep(i,2,154)inv[i]=mu(P-P/i,inv[P%i]);
	ifac[0]=ifac[1]=1;
	rep(i,2,154)ifac[i]=mu(ifac[i-1],inv[i]);
	scanf("%d%*d",&n);
	rep(i,1,n){
		int dt;
		scanf("%d",&dt);
		if(dt==0){
			--i,--n;
			continue;
		}
		a[i]=a[i-1]+dt;
	}
	LL maxx=0;
	rep(i,0,n)rep(j,i,n){
		if(a[i]<=a[j]){
			umax(maxx,a[j]-a[i]+1);
		}
	}
	if(maxx==1){
		printf("%d %d\n",1,norm(-a[n]+1));
		return 0;
	}
	rep(i,0,n-1){
		if(a[i]<a[i+1]){
			a_[i]=a[i]+1;
		}else{
			a_[i]=a[i]-1;
		}
	}
	rep(i,0,n){
		b[++m]=a[i]-1;
		b[++m]=a[i];
		b[++m]=a[i]+1;
	}
	sort(b+1,b+1+m);
	m=unique(b+1,b+1+m)-b-1;
	rep(i,0,n)a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	rep(i,0,n-1)a_[i]=lower_bound(b+1,b+1+m,a_[i])-b;
	int ans=0;
	rep(i,0,n){
		int j_=-1;
		rep(j,i,n)if(a[i]<=a[j]&&b[a[j]]-b[a[i]]+1==maxx){
			j_=j;
		}
		if(j_!=-1){
			uad(ans,sol(i,j_));
			i=j_;
		}
	}
	printf("%lld %d\n",maxx,ans);
	return 0;
}