#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
ll inf=1e16;

struct starryskytree_min{
	static const int N=1<<17;
	ll mn[N*2],ad[N*2];
	void init(vector<int>& vc){
		rep(i,N*2) mn[i]=inf,ad[i]=0;
		rep(i,vc.size()) mn[i+N]=vc[i];
		for(int i=N-1;i>0;i--) mn[i]=min(mn[i*2],mn[i*2+1]);
	}
	void add(int a,int b,int v,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			ad[k]+=v;
			return;
		}
		add(a,b,v,l,(l+r)/2,k*2);
		add(a,b,v,(l+r)/2,r,k*2+1);
		mn[k]=min(mn[k*2]+ad[k*2],mn[k*2+1]+ad[k*2+1]);
	}
	ll getmin(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return inf;
		if(a<=l&&r<=b) return mn[k]+ad[k];
		return ad[k]+min(getmin(a,b,l,(l+r)/2,k*2),getmin(a,b,(l+r)/2,r,k*2+1));
	}
	ll getval(int x){
		return getmin(x,x+1);
	}
}smin;
struct starryskytree_max{
	static const int N=1<<17;
	ll mx[N*2],ad[N*2];
	void init(vector<int>& vc){
		rep(i,N*2) mx[i]=-inf,ad[i]=0;
		rep(i,vc.size()) mx[i+N]=vc[i];
		for(int i=N-1;i>0;i--) mx[i]=max(mx[i*2],mx[i*2+1]);
	}
	void add(int a,int b,int v,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			ad[k]+=v;
			return;
		}
		add(a,b,v,l,(l+r)/2,k*2);
		add(a,b,v,(l+r)/2,r,k*2+1);
		mx[k]=max(mx[k*2]+ad[k*2],mx[k*2+1]+ad[k*2+1]);
	}
	ll getmax(int a,int b,int l=0,int r=N,int k=1){
		if(b<=l||r<=a) return -inf;
		if(a<=l&&r<=b) return mx[k]+ad[k];
		return ad[k]+max(getmax(a,b,l,(l+r)/2,k*2),getmax(a,b,(l+r)/2,r,k*2+1));
	}
	ll getval(int x){
		return getmax(x,x+1);
	}
}smax;

const int MN=200000;
int N,a[MN];

void init(){
	int s=0;
	vector<int> v0,v1;
	rep(i,N){
		if(i%2==0) s+=a[i];
		else s-=a[i];
		if(i%2==0) v0.pb(s);
		else v1.pb(s);
	}
	smin.init(v0);
	smax.init(v1);
}
int query(){
	int l,r;
	scanf("%d%d",&l,&r);
	r++;
	if(l%2==0){
		ll pre=0;
		if(l>0) pre=smax.getval(l/2-1);
		ll mx_= smax.getmax(l/2,r/2);
		// show(l/2);
		// show(r/2);
		// show(smax.getval(0));
		// show(smax.getval(1));
		// show(smax.getval(2));
		ll mn_= smin.getmin(l/2,(r+1)/2);
		ll mx=pre-mn_ +1;
		ll mn=pre-mx_ +1;
		// show(mx_);
		// show(mn);
		// show(mx);
		if(mx>=0) return 0;
		if(mn<=0) return 0;
		ll sm;
		if(r%2==0) sm=smax.getval(r/2-1) -pre;
		else sm=smin.getval(r/2) -pre-2;
		// show(smin.getval(r/2));
		// show(pre);
		// show(sm);
		if(sm!=0) return 0;
		return 1;
	}else{
		ll pre=smin.getval(l/2);
		ll mx= smax.getmax(l/2,r/2) - pre +1;
		ll mn= smin.getmin(l/2+1,(r+1)/2) -pre +1;
		if(mx>=0) return 0;
		if(mn<=0) return 0;
		ll sm;
		if(r%2==0) sm=smax.getval(r/2-1) -pre +2;
		else sm=smin.getval(r/2) - pre;
		if(sm!=0) return 0;
		return 1;
	}
}
int main(){
	scanf("%d",&N);
	rep(i,N) scanf("%d",a+i),a[i]*=2;
	init();
	int Q;
	scanf("%d",&Q);
	rep(tt,Q){
		int t;
		scanf("%d",&t);
		if(t==1){	//add
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			k*=2;
			r++;
			if(l%2==0){
				int r_=r;
				l=l/2,r=(r+1)/2;
				smin.add(l,r,k);
				if(r_%2==1){
					smin.add(r,N/2+2,k);
					smax.add(r_/2,N/2+2,k);
				}
			}else{
				int r_=r;
				l=l/2,r=r/2;
				smax.add(l,r,-k);
				if(r_%2==0){
					smax.add(r,N/2+2,-k);
					smin.add(r,N/2+2,-k);
				}
			}
		}else{
			printf("%d\n",query());
		}
	}
}