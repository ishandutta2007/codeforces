// author: xay5421
// created: Thu Oct 28 09:39:47 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const long double eps=1e-9;
const int N=200005;
int n,L;
int sgn(double x){return fabs(x)<eps?0:x<0?-1:1;}
int main(){
	vector<pair<int,double> >seg; // x.second in [1,2]
	scanf("%d%d",&n,&L);
	int lst=0;
	rep(i,1,n){
		int x,y;
		double s;
		scanf("%d%d%lf",&x,&y,&s);
		if(x>lst){
			seg.eb(x-lst,1);
		}
		seg.eb(y-x,s+1);
		lst=y;
	}
	if(lst<L){
		seg.eb(L-lst,1);
	}
	vector<int>id(SZ(seg));
	rep(i,0,SZ(seg)-1)id[i]=i;
	sort(id.begin(),id.end(),[&](int x,int y){return seg[x].second<seg[y].second;});
	vector<double>e(SZ(seg));
	vector<double>es(SZ(seg));
	vector<double>t(SZ(seg)*4+5),tg(SZ(seg)*4+5);
	function<void(int,double)>pst=[&](int k1,double k2){
		t[k1]+=k2,tg[k1]+=k2;
	};
	function<void(int)>psd=[&](int k1){
		if(tg[k1]){
			pst(k1*2,tg[k1]);
			pst(k1*2+1,tg[k1]);
			tg[k1]=0;
		}
	};
	function<void(int)>upd=[&](int k1){
		t[k1]=min(t[k1*2],t[k1*2+1]);
	};
	function<void(int,int,int)>bud=[&](int k1,int k2,int k3){
		if(k2==k3){
			t[k1]=es[k2];
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
	};
	function<void(int,int,int,int,int,double)>add=[&](int k1,int k2,int k3,int k4,int k5,double k6){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			pst(k1,k6);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		add(k1*2,k2,mid,k4,k5,k6),add(k1*2+1,mid+1,k3,k4,k5,k6);
		upd(k1);
	};
	double __res;
	function<void(int,int,int,int,int)>__ask=[&](int k1,int k2,int k3,int k4,int k5){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			__res=min(__res,t[k1]);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		__ask(k1*2,k2,mid,k4,k5),__ask(k1*2+1,mid+1,k3,k4,k5);
	};
	function<double(int,int)>ask=[&](int l,int r){
		__res=1e100;
		__ask(1,0,SZ(seg)-1,l,r);
		return __res;
	};
	rep(i,0,SZ(seg)-1){
		if(sgn(seg[i].second-1)==0){
			e[i]=0;
		}else{
			e[i]=seg[i].first/(-1.+seg[i].second);
		}
	}
	rep(i,0,SZ(seg)-1){
		es[i]=e[i]+(i==0?0:es[i-1]);
	}
	bud(1,0,SZ(seg)-1);
	for(auto i:id){
		double lim=ask(i,SZ(seg)-1);
		double t=min(e[i]-(seg[i].first/(-1.-seg[i].second)),lim);
		e[i]-=t;
		add(1,0,SZ(seg)-1,i,SZ(seg)-1,-t);
	}
	double ans=0;
	rep(i,0,SZ(seg)-1){
		ans+=(seg[i].first+e[i])/seg[i].second;
	}
	printf("%.20f\n",ans);
	return 0;
}