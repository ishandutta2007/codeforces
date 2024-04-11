#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const long double PI=acos(-1),eps=1e-10;
const int N=100005;
int n,m,x[N],y[N];
double L[N],R[N];
bool chk(double mid){
	vector<pair<double,double> >segs;
	rep(i,1,n){
		double dis=sqrt(1LL*x[i]*x[i]+1LL*y[i]*y[i]);
		double cur=atan2(y[i],x[i]);
		double alpha=acos(mid/dis);
		L[i]=cur-alpha;
		R[i]=cur+alpha;
		if(L[i]<0){
			L[i]+=PI*2;
			R[i]+=PI*2;
		}
		segs.eb(L[i],R[i]);
	}
	sort(segs.begin(),segs.end());
	segs.resize(n*2);
	rep(i,0,n-1){
		segs[i+n]=segs[i];
		segs[i+n].first+=PI*2,segs[i+n].second+=PI*2;
	}
	const int K=20;
	vector<vector<int> >f(n*2+1,vector<int>(K,0));
	int cur=n*2-1;
	per(i,n*2-1,0){
		while(segs[i].second<segs[cur].first){
			--cur;
		}
		f[i][0]=cur+1;
	}
	f[n*2][0]=n*2;
	rep(j,1,K-1){
		rep(i,0,n*2){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	rep(i,0,n-1){
		int k=i;
		per(j,K-1,0)if(m>>j&1){
			k=f[k][j];
		}
		if(k>=i+n)
			return 1;
	}
	return 0;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
	double mn=1e100;
	rep(i,1,n){
		mn=min(mn,sqrt(1LL*x[i]*x[i]+1LL*y[i]*y[i]));
	}
	if(mn<eps){
		puts("0");
		return 0;
	}
	double l=0,r=mn;
	rep(_,1,60){
		double mid=(l+r)/2.;
		if(chk(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	printf("%.20f\n",l);
	return 0;
}