// author: xay5421
// created: Wed Oct 27 18:18:35 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=100005;
int n,a[N];
LL sx,sy,d[N],d_[N],x[N],y[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld%lld",&x[i],&y[i]),sx+=x[i],sy+=y[i];
	int Q;
	scanf("%d",&Q);
	__int128 base=0;
	rep(i,1,n){
		base+=1LL*x[i]*x[i]+1LL*y[i]*y[i]; // base<=2e21
	}
	while(Q--){
		vector<pair<LL,LL> >ans;
		__int128 ss=0;
		rep(i,1,n){
			scanf("%lld",&d[i]);
			ss+=d[i];
		}
		ss-=base;
		// nx^2+ny^2-2*sx*x-2*sy*y-ss=0
		auto push=[&](LL x_,LL y_){
			rep(i,1,n){
				d_[i]=1LL*(x_-x[i])*(x_-x[i])+1LL*(y_-y[i])*(y_-y[i]);
			}
			sort(d_+1,d_+1+n);
			bool err=0;
			rep(i,1,n)if(d[i]!=d_[i])err=1;
			if(!err){
				ans.eb(x_,y_);
			}
		};
		auto chk=[&](LL x_,LL y_,LL dd){
			// D("chk %lld %lld\n",x_,y_);
			rep(i,-20,20)rep(j,-20,20){
				LL _x=x_+i,_y=y_+j;
				if(1LL*(_x-x[1])*(_x-x[1])+1LL*(_y-y[1])*(_y-y[1])==dd){
					push(_x,_y);
				}
			}
		};
		rep(i,1,n){
			// (x-x[1])^2+(y-y[1])^2-d[i]=0
			__int128 k1=-2LL*n*x[1]+2LL*sx;
			__int128 k2=-2LL*n*y[1]+2LL*sy;
			__int128 k3=(__int128)n*x[1]*x[1]+(__int128)n*y[1]*y[1]-(__int128)n*d[i]+ss;
			// k1x+k2y+k3=0
			// y=(-k3-k1x)/k2;
			if(k2==0){
				assert(k1!=0);
				long double x_=-k3/k1;
				long double tmp=d[i]-(x_-x[1])*(x_-x[1]);
				if(tmp>=0){
					tmp=sqrt(tmp);
					chk(x_,tmp+y[1],d[i]);
					chk(x_,-tmp+y[1],d[i]);
				}
			}else{
				long double t1=-1.*k1/k2;
				long double t2=-1.*k3/k2-y[1];
				// (x-x[1])^2+(t1x+t2)^2-d[i]=0
				long double A=1+t1*t1;
				long double B=-2*x[1]+2*t1*t2;
				long double C=1.*x[1]*x[1]+t2*t2-d[i];
				long double delta=B*B-4*A*C;
				if(delta>=0){
					long double tmp=sqrt(delta);
					long double x1=(-B+tmp)/(A*2);
					long double x2=(-B-tmp)/(A*2);
					//D("x1=%.5f x2=%.5f\n",(double)x1,(double)x2);
					chk((LL)x1,(LL)(-1.*k3/k2-1.*k1/k2*x1),d[i]);
					chk((LL)x2,(LL)(-1.*k3/k2-1.*k1/k2*x2),d[i]);
				}
			}
		}
		sort(ans.begin(),ans.end()),ans.erase(unique(ans.begin(),ans.end()),ans.end());
		printf("%d ",SZ(ans));
		for(auto x:ans)printf("%lld %lld ",x.first,x.second);
		puts("");
	}
	return 0;
}