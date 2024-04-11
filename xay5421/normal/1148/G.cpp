#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define PB push_back
#define EB emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005,M=10000005;
int n,K,a[N];
bool bad[N],pd[N];
vector<int>d[N];
int p[M/10],mind[M],mu[M];
bool ban[M];
void sieve(){
	ban[0]=ban[1]=1;
	mu[1]=1;
	rep(i,2,M-1){
		if(!ban[i])p[++*p]=i,mu[i]=-1,mind[i]=i;
		for(int j=1;j<=*p&&i*p[j]<M;++j){
			ban[i*p[j]]=1;
			mind[i*p[j]]=p[j];
			if(i%p[j]==0)break;
			mu[i*p[j]]=-mu[i];
		}
	}
}
void getd(vector<int>&d,int x){
	vector<int>num;
	while(x>1){
		int t=mind[x];
		num.PB(t);
		while(x%t==0)x/=t;
	}
	rep(j,0,(1<<SZ(num))-1){
		int cur=1;
		rep(i,0,SZ(num)-1)if(j>>i&1)cur*=num[i];
		d.PB(cur);
	}
}
int cnt[M];
void ad(int id,int num){
	for(auto x:d[id]){
		cnt[x]+=num;
	}
}
int ask(int id){
	int res=0;
	for(auto x:d[id]){
		res+=mu[x]*cnt[x];
	}
	return res;
}
mt19937 rng(233);
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	sieve();
	scanf("%d%d",&n,&K);
	rep(i,1,n){
		//a[i]=rng()%999999+2;
		scanf("%d",&a[i]);
		getd(d[i],a[i]);
	}
	vector<int>tp;
	rep(i,1,n)ad(i,1);
	rep(i,1,n){
		if(ask(i)>1){
			tp.PB(i);
			rep(j,1,n){
				if(__gcd(a[i],a[j])==1){
					tp.PB(j);
					if(SZ(tp)==3)goto QAQ;
				}
			}
		}
	}
	QAQ:;
	if(!SZ(tp)){
		vector<int>v;
		rep(i,1,n)ad(i,-1);
		rep(i,1,n){
			if(ask(i)==0){
				v.PB(i);
				ad(i,1);
			}
		}
		assert(SZ(v)>=K);
		v.resize(K);
		for(auto x:v)printf("%d ",x);
		return 0;
	}
	for(auto x:tp)ad(x,-1),bad[x]=1;
	vector<int>v,v2;
	rep(i,1,n)if(ask(i)>0)v.PB(i);else v2.PB(i);
	if(SZ(v2)>=K){
		v2.resize(K);
		for(auto x:v2)printf("%d ",x);
		return 0;
	}
	rep(i,1,n)if(!bad[i])ad(i,-1);
	auto sol=[&](int mid){
		rep(i,1,mid)if(!bad[i])ad(i,1);
		int tt=0;
		rep(i,1,mid)if(!bad[i]&&ask(i)>=1)++tt;
		rep(i,1,mid)if(!bad[i])ad(i,-1);
		return tt;
	};
	if(SZ(v)>=K-3){
		int l=K-4,r=n,res=n,key=SZ(v);
		while(l<=r){
			int mid=(l+r)>>1;
			int tem=sol(mid);
			if(tem>=K-3)r=mid-1,res=mid,key=tem;
			else l=mid+1;
		}
		int lim=-1;
		if(key>=K)lim=K;
		else lim=K-2;
		rep(i,1,res)if(!bad[i])ad(i,1);
		for(int i=1;i<=res&&key>lim;++i)
			if(!ban[i]&&ask(i)==1&&__gcd(a[i],a[res])==1){
				--key;
				pd[i]=1;
			}
		rep(i,1,res)if(!bad[i]&&!pd[i]&&ask(i)>=1){
			printf("%d ",i);
		}
		if(key==K-2){
			printf("%d %d\n",tp[0],tp[1]);
		}
		if(key==K-3){
			printf("%d %d %d\n",tp[0],tp[1],tp[2]);
		}
	}
	return 0;
}