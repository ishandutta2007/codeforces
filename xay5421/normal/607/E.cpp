// author: xay5421
// created: Wed Jul  7 09:42:12 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=50005;
const double eps=1e-6;
int n,m,lst[N],go[N*2];
double sx,sy,k[N],b[N];
struct node{
	double v;
	int id;
};
struct BIT{
	int t[N*2];
	void upd(int k1){
		for(int i=k1;i<=n*2;i+=i&-i)++t[i];
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
}t;
vector<node>v;
void init(double R){
	v.clear();
	rep(i,1,n){
		double a_=k[i]*k[i]+1;
		double b_=k[i]*2*(b[i]-sy)-2*sx;
		double c_=sx*sx+(b[i]-sy)*(b[i]-sy)-R*R;
		double dt=b_*b_-4*a_*c_;
		if(dt<0)continue;
		double xl=(-b_-sqrt(dt))/(2*a_);
		double xr=(-b_+sqrt(dt))/(2*a_);
		double yl=xl*k[i]+b[i];
		double yr=xr*k[i]+b[i];
		/*D("%.20f %.20f diff=%.20f\n",sqrt((xl-sx)*(xl-sx)+(yl-sy)*(yl-sy)),R,sqrt((xl-sx)*(xl-sx)+(yl-sy)*(yl-sy))-R);
		assert(sgn(sqrt((xl-sx)*(xl-sx)+(yl-sy)*(yl-sy))-R)==0);
		assert(sgn(sqrt((xr-sx)*(xr-sx)+(yr-sy)*(yr-sy))-R)==0);*/
		v.push_back((node){atan2(yl-sy,xl-sx),i});
		v.push_back((node){atan2(yr-sy,xr-sx),i});
	}
	sort(v.begin(),v.end(),[&](const node&k1,const node&k2){
		return k1.v<k2.v;
	});
}
LL calc(double R){
	init(R);
	fill(lst+1,lst+1+n,-1);
	fill(go+1,go+1+n*2,0);
	rep(i,0,SZ(v)-1){
		if(lst[v[i].id]!=-1){
			go[i]=lst[v[i].id];
			go[lst[v[i].id]]=i;
		}
		lst[v[i].id]=i;
	}
	fill(t.t+1,t.t+1+n+n,0);
	LL res=0;
	rep(i,0,SZ(v)-1)if(i<go[i]){
		res+=t.qry(go[i])-t.qry(i);
		t.upd(go[i]);
	}
	return res;
}
double cross(double x,double y,double x_,double y_){return x*y_-y*x_;}
double fun(int i,int j){
	double tx=(b[j]-b[i])/(k[i]-k[j]);
	double ty=k[i]*tx+b[i];
	return sqrt((tx-sx)*(tx-sx)+(ty-sy)*(ty-sy));
}
double sol(double R){
	init(R);
	fill(lst+1,lst+1+n,-1);
	fill(go+1,go+1+n,0);
	rep(i,0,SZ(v)-1){
		if(lst[v[i].id]!=-1){
			go[i]=lst[v[i].id];
			go[lst[v[i].id]]=i;
		}
		lst[v[i].id]=i;
	}
	LL res=0;
	double ans=0;
	set<int>S;
	rep(i,0,SZ(v)-1)if(i<go[i]){
		for(auto it=S.lower_bound(i+1);it!=S.end()&&*it<go[i];++it){
			++res;
			ans+=fun(v[i].id,v[*it].id);
		}
		S.insert(go[i]);
	}
	//assert(res<=m);
	return ans+(m-res)*R;
	
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%lf%lf%d",&n,&sx,&sy,&m);
	sx/=1000,sy/=1000;
	rep(i,1,n){	
		scanf("%lf%lf",&k[i],&b[i]);
		k[i]/=1000,b[i]/=1000;
	}
	double l=0,r=1e10,ansr=0;
	while(r-l>eps){
		D("l=%.20f r=%.20f\n",l,r);
		double mid=(l+r)/2.;
		if(calc(mid)<=m)ansr=mid,l=mid;
		else r=mid;
	}
	printf("%.20f\n",sol(ansr));
	return 0;
}