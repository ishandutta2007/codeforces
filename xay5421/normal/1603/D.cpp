// author: xay5421
// created: Sat Oct 30 23:32:59 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#pragma GCC optimize(2,3,"Ofast")
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int brand(){return rng()&0X7FFFFFFF;}
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
const int N=100005;
int brute(int l,int r){
	int tot=0;
	rep(i,l,r)rep(j,i,r){
		if(__gcd(i,j)>=l)++tot;
	}
	return tot;
}
int ban[N],phi[N],p[N];
LL sphi[N];
void sieve(){
	ban[0]=ban[1]=1,phi[1]=1;
	for(int i=2;i<N;++i){
		if(!ban[i]){
			p[++*p]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	rep(i,1,N-1){
		sphi[i]=sphi[i-1]+phi[i];
	}
}
LL sol(int L,int R){
	LL ans=0;
	for(int l=L,r;l<=R;l=r+1){
		r=R/(R/l);
		ans+=1LL*(r-l+1)*sphi[R/l];
	}
	return ans;
}
int T,n,K;
LL f[25][100005];
vector<int>d[100005];
vector<pair<int,int> >segs;
void get_seg(int n){
	segs.clear();
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		segs.eb(l,r);
	}
}
int kk;
LL t[N*4],tg[N*4];
void upd(int k1){
	t[k1]=min(t[k1*2],t[k1*2+1]);
}
void bud(int k1,int k2,int k3){
	tg[k1]=0;
	if(k2==k3){
		t[k1]=f[kk-1][k2-1];
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void pst(int k1,LL k2){
	tg[k1]+=k2,t[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	/*if(k1==1){
		D("add %d %d %d\n",k4,k5,k6);
	}*/
	if(k4<=k2&&k3<=k5){
		pst(k1,k6);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	add(k1*2,k2,mid,k4,k5,k6),add(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
LL res;
void ask(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		umin(res,t[k1]);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	ask(k1*2,k2,mid,k4,k5),ask(k1*2+1,mid+1,k3,k4,k5);
}
LL ask(int l,int r){
	res=INFLL;
	ask(1,1,50005,l,r);
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	sieve();
	for(int i=1;i<=100000;++i)for(int j=i;j<=100000;j+=i)d[j].pb(i);
	memset(f,63,sizeof(f));
	f[0][0]=0;
	f[1][0]=0;
	rep(i,1,100000){
		f[1][i]=f[1][i-1];
		for(auto x:d[i]){
			f[1][i]+=phi[i/x];
		}
	}
	rep(k,2,17){
		kk=k;
		bud(1,1,50005);
		f[k][0]=0;
		D("k=%d\n",k);
		rep(i,1,100000){
			for(auto x:d[i]){
				add(1,1,50005,1,min(50005,x),phi[i/x]);
			}
			//f[k][i]=ask(1,min(50005,i));
			f[k][i]=t[1];
		}
		//D("%lld\n",f[k][100000]);
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&K);
		if(K>17){
			printf("%d\n",n);
		}else{
			printf("%lld\n",f[K][n]);
		}
	}
	return 0;
}