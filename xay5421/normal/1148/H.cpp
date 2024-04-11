#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
const int N=200005,M=N*120;
int n;
struct SEG1{
	int mn[N*4];
	void upd(int k1){
		mn[k1]=min(mn[k1*2],mn[k1*2+1]);
	}
	void mdf(int k1,int k2,int k3,int k4,int k5){
		if(k2==k3){
			mn[k1]=k5;
			return;
		}
		int mid=(k2+k3)>>1;
		if(k4<=mid)mdf(k1*2,k2,mid,k4,k5);
		else mdf(k1*2+1,mid+1,k3,k4,k5);
		upd(k1);
	}
	pair<int,int>res;
	void qry(int k1,int k2,int k3,int k4,int k5){
		if(mn[k1]>k5)return;
		if(k2==k3){
			res={k2,mn[k1]};
			return;
		}
		int mid=(k2+k3)>>1;
		if(k4<=mid)qry(k1*2,k2,mid,k4,k5);
		if(!res.X)qry(k1*2+1,mid+1,k3,k4,k5);
	}
	pair<int,int>qry(int x,int y){
		res={0,0};
		qry(1,0,n,x,y);
		return res;
	}
}A;
int ind,lc[M],rc[M];
LL sum1[M],sum2[M],tg1[M],tg2[M];
struct SEG2{
	vector<int>rt,pos;
	void cp(int&k1,int k2){
		k1=++ind;
		lc[k1]=lc[k2];
		rc[k1]=rc[k2];
		sum1[k1]=sum1[k2];
		sum2[k1]=sum2[k2];
		tg1[k1]=tg1[k2];
		tg2[k1]=tg2[k2];
	}
	void ins(int&k1,int k2,int l,int r,int lx,int rx,LL w1,LL w2){
		cp(k1,k2);
		if(l>rx||r<lx)return;
		if(lx<=l&&r<=rx){
			tg1[k1]+=w1,tg2[k1]+=w2;
			sum1[k1]+=w1*(r-l+1),sum2[k1]+=w2*(r-l+1);
			return;
		}
		int mid=(l+r)>>1;
		ins(lc[k1],lc[k2],l,mid,lx,rx,w1,w2);
		ins(rc[k1],rc[k2],mid+1,r,lx,rx,w1,w2);
		sum1[k1]=sum1[lc[k1]]+sum1[rc[k1]]+(r-l+1)*tg1[k1];
		sum2[k1]=sum2[lc[k1]]+sum2[rc[k1]]+(r-l+1)*tg2[k1];
	}
	void ins(int l,int r,int tim,LL w1,LL w2){
		rt.PB(0),pos.PB(tim);
		ins(rt.back(),SZ(rt)==1?0:rt[SZ(rt)-2],0,n,l,r,w1,w2);
	}
	pair<LL,LL>res;
	void qry(int k1,int l,int r,int lx,int rx){
		if(l>rx||r<lx)return;
		if(lx<=l&&r<=rx){
			res.X+=sum1[k1];
			res.Y+=sum2[k1];
			return;
		}
		int mid=(l+r)>>1;
		qry(lc[k1],l,mid,lx,rx);
		qry(rc[k1],mid+1,r,lx,rx);
		int len=min(r,rx)-max(l,lx)+1;
		res.X+=tg1[k1]*len;
		res.Y+=tg2[k1]*len;
	}
	LL qry(int l,int r){
		int q=upper_bound(pos.begin(),pos.end(),r)-pos.begin()-1;
		if(q<0)return 0;
		res={0,0};
		qry(rt[q],0,n,l,r);
		return res.X*(r+1)-res.Y;
	}
}B[N];
map<int,pair<int,int> >mp;
LL sol(int a,int l,int r,int k,int tim){
	//D("A.mdf %d %d\n",a,tim);
	A.mdf(1,0,n,a,tim);
	auto ex=[&](int x,int l,int r){
		if(mp.count(x)){
			if(r<mp[x].X){
				B[x].ins(l,mp[x].X-1,tim,1,tim);
				umin(mp[x].X,l);
				return;
			}
			if(l>mp[x].Y){
				B[x].ins(mp[x].Y+1,r,tim,1,tim);
				umax(mp[x].Y,r);
				return;
			}
			B[x].ins(mp[x].X,mp[x].Y,tim,-1,-tim);
			//D("!! B[%d].ins(%d,%d,%d,%d,%d)\n",x,mp[x].X,mp[x].Y,tim,-1,-tim);
			umin(mp[x].X,l);
			umax(mp[x].Y,r);
		}else{
			mp[x]={l,r};
		}
		B[x].ins(mp[x].X,mp[x].Y,tim,1,tim);
		//D("@@ B[%d].ins(%d,%d,%d,%d,%d)\n",x,mp[x].X,mp[x].Y,tim,1,tim);
	};
	ex(a==0?1:0,tim,tim);
	if(mp.count(a)){
		int p,q;
		tie(p,q)=mp[a];
		mp.erase(a);
		B[a].ins(p,q,tim,-1,-tim);
		//D("## B[%d].ins(%d,%d,%d,%d,%d)\n",a,p,q,tim,-1,-tim);
		while(p<=q){
			pair<int,int>nex=A.qry(a+1,q);
			//D("qry %d %d={%d,%d}\n",a+1,q,nex.X,nex.Y);
			if(!nex.X){
				break;
			}
			if(nex.Y<p){
				ex(nex.X,p,q);
				break;
			}
			if(nex.Y<q){
				ex(nex.X,nex.Y+1,q);
			}
			tie(a,q)=nex;
		}
	}
	/*for(auto x:mp){
		D("(%d,[%d,%d]) ",x.X,x.Y.X,x.Y.Y);
	}
	D("\n");*/
	return B[k].qry(l,r);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	LL ans=0;
	rep(i,1,n){
		//D(">>> %d\n",i);
		int a,l,r,k;
		scanf("%d%d%d%d",&a,&l,&r,&k);
		a=(a+ans)%(n+1),l=(l+ans)%i+1,r=(r+ans)%i+1,k=(k+ans)%(n+1);
		if(l>r)swap(l,r);
		ans=sol(a,l,r,k,i);
		printf("%lld\n",ans);
	}
	return 0;
}