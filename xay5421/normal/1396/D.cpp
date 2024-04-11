// author: xay5421
// created: Wed Nov 25 15:23:45 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=2005,P=1000000007;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
int n,K,L,bin[N],f[N];
vector<int>vy;
multiset<int>G[N];
vector<int>H[N];
struct ff{int x,y,c;bool operator<(const ff&k)const{return x<k.x;}}a[N];
template<typename T>
void erase(multiset<T>&S,T x){
	S.erase(x);
}
int sum[N*4],mx[N*4],tg[N*4],len[N*4];
void upd(int k1){
	sum[k1]=ad(sum[k1*2],sum[k1*2+1]);
	mx[k1]=max(mx[k1*2],mx[k1*2+1]);
}
void pst(int k1,int k2){
	tg[k1]=k2,sum[k1]=mu(len[k1],k2+1),mx[k1]=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void bud(int k1,int k2,int k3){
	len[k1]=vy[k3+1]-vy[k2];
	tg[k1]=0,sum[k1]=0,mx[k1]=0;
	if(k2==k3){
		pst(k1,f[k2]);
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void mdfmin(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k1==1)D("umin %d %d %d\n",k4,k5,k6);
	if(k2>k5||k3<k4||mx[k1]<k6)return;
	int mid=(k2+k3)>>1;
	if(k4<=k2&&k3<=k5){
		if(k2==k3)pst(k1,k6);
		else{
		    psd(k1);
			if(mx[k1*2]>=k6)pst(k1*2+1,k6),mdfmin(k1*2,k2,mid,k4,k5,k6);
			else mdfmin(k1*2+1,mid+1,k3,k4,k5,k6);
			upd(k1);
		}
		return;
	}
	psd(k1);
	mdfmin(k1*2,k2,mid,k4,k5,k6),mdfmin(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
void getf(){
	memset(bin,0,sizeof(bin));
	int j=SZ(vy);
	int tt=0;
	for(int i=SZ(vy);i>=1;--i){
		for(auto x:H[i]){
			if(!--bin[x])--tt;
		}
		while(j>=0&&tt<K){
			for(auto x:H[j]){
				if(!bin[x]++)++tt;
			}
			--j;
		}
		f[i-1]=vy[j+1];
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&K,&L);
	rep(i,1,n){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
		vy.PB(a[i].y);
	}
	vy.PB(-1),vy.PB(L);
	sort(vy.begin(),vy.end()),vy.erase(unique(vy.begin(),vy.end()),vy.end());
	rep(i,1,n)a[i].y=lower_bound(vy.begin(),vy.end(),a[i].y)-vy.begin();
	sort(a+1,a+1+n);
	a[0].x=-1,a[n+1].x=L;
	int ans=0;
	for(int i=1,j;i<=n;i=j){
		j=i+1;
		while(j<=n&&a[i].x==a[j].x)++j;
		rep(k,0,SZ(vy))H[k].clear();
		rep(k,0,K)G[k].clear();
		rep(k,i,n){
			G[a[k].c].insert(a[k].y);
			H[a[k].y].PB(a[k].c);
		}
		getf();
		bud(1,0,SZ(vy)-2);
		per(k,n,i){
			ans=ad(ans,mu(mu(a[i].x-a[i-1].x,a[k+1].x-a[k].x),sum[1]));
			D("\t%d\n",ans);
			auto it=G[a[k].c].lower_bound(a[k].y);
			int w=0;
			if(it==G[a[k].c].begin())w=-1;
			else w=vy[*prev(it)];
			if(it!=--G[a[k].c].end()){
				if(*it<*next(it))mdfmin(1,0,SZ(vy)-2,*it,*next(it)-1,w);
			}else mdfmin(1,0,SZ(vy)-2,*it,SZ(vy)-2,w);
			G[a[k].c].erase(it);
		}
		D(">> %d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
}