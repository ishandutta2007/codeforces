#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=100005;
int n,m[2];
double x[2][N],y[2][N];
double eps=1e-2;
double sqr(double x){return x*x;}
int get_val(const vector<double>&a,const vector<double>&b){
	int ret=0;
	for(int i=0,j=0;i<SZ(a);++i){
		while(j<SZ(b)&&b[j]<a[i]-eps)++j;
		if(j<SZ(b)&&b[j]<a[i]+eps)++ret,++j;
	}
	return ret;
}
void check(int i,int j){
	vector<pair<double,int> >d[2];
	rep(_,0,1){
		if(_==1)i=j;
		rep(k,0,m[_]-1){
			d[_].eb(sqrt(sqr(x[_][i]-x[_][k])+sqr(y[_][i]-y[_][k])),k);
		}
		sort(d[_].begin(),d[_].end());
	}
	auto&a=d[0];
	auto&b=d[1];
	vector<pair<int,int> >ans;
	for(int i=0,j=0;i<SZ(a);++i){
		while(j<SZ(b)&&b[j].first<a[i].first-eps)++j;
		if(j<SZ(b)&&b[j].first<a[i].first+eps)ans.eb(a[i].second,b[j].second);
	}
	if(SZ(ans)>=0.9*n){
		rep(_,0,2){
			if(SZ(ans)>n){
				ans.clear();
				eps*=0.9;
				for(int i=0,j=0;i<SZ(a);++i){
					while(j<SZ(b)&&b[j].first<a[i].first-eps)++j;
					if(j<SZ(b)&&b[j].first<a[i].first+eps)ans.eb(a[i].second,b[j].second);
				}
			}else{
				ans.clear();
				eps*=1.1;
				for(int i=0,j=0;i<SZ(a);++i){
					while(j<SZ(b)&&b[j].first<a[i].first-eps)++j;
					if(j<SZ(b)&&b[j].first<a[i].first+eps)ans.eb(a[i].second,b[j].second);
				}
			}
		}
		vector<bool>v0(m[0]);
		vector<bool>v1(m[1]);
		each(x,ans)v0[x.first]=1,v1[x.second]=1;
		int u=0,v=0;
		while(SZ(ans)<n){
			while(v0[u])++u;
			while(v1[v])++v;
			v0[u]=1,v1[v]=1;
			ans.eb(u,v);
		}
		ans.resize(n);
		each(x,ans)printf("%d %d\n",x.first+1,x.second+1);
		exit(0);
	}
}
vector<int>hull[2];
double cross(double a,double b,double c,double d){return a*d-b*c;}
#define LEN(i) (x[i]-x[id[0]])*(x[i]-x[id[0]])+(y[i]-y[id[0]])*(y[i]-y[id[0]])
#define VEC(i) x[i]-x[id[0]],y[i]-y[id[0]]
#define VEC2(i,j) x[j]-x[i],y[j]-y[i]
void get_convex_hull(int n,double*x,double*y,vector<int>&hull){
	static int id[N];
	iota(id,id+n,0);
	swap(id[0],*min_element(id,id+n,[&](int lhs,int rhs){return tie(y[lhs],x[lhs])<tie(y[rhs],x[rhs]);}));
	sort(id+1,id+n,[&](int lhs,int rhs){
		double t=cross(VEC(lhs),VEC(rhs));
		if(t!=0)return t>0;
		return LEN(lhs)>LEN(rhs);
	});
	hull={id[0]};
	rep(_,1,n-1)if(_==1||cross(VEC(id[_-1]),VEC(id[_]))!=0){
		int i=id[_];
		while(SZ(hull)>1&&cross(VEC2(hull[SZ(hull)-2],hull.back()),VEC2(hull[SZ(hull)-2],i))<=0){
			hull.pop_back();
		}
		hull.pb(i);
	}
}
#undef LEN
#undef VEC
#undef VEC2
int main(){
	rd(n);
	rep(_,0,1){
		rd(m[_]);
		rep(i,0,m[_]-1)scanf("%lf%lf",&x[_][i],&y[_][i]);
		get_convex_hull(m[_],x[_],y[_],hull[_]);
	}
	if(n<=100){
		rep(i,0,m[0]-1)rep(j,0,m[1]-1){
			check(i,j);
		}
	}else{
		vector<vector<double> >dis[2];
		rep(_,0,1){
			dis[_].resize(SZ(hull[_]));
			rep(i,0,SZ(hull[_])-1){
				dis[_][i].assign(SZ(hull[_]),0);
				rep(j,0,SZ(hull[_])-1)if(i!=j){
					dis[_][i][j]=sqrt(sqr(x[_][hull[_][i]]-x[_][hull[_][j]])+sqr(y[_][hull[_][i]]-y[_][hull[_][j]]));
				}
				sort(dis[_][i].begin(),dis[_][i].end());
			}
		}
		vector<tuple<int,int,int> >vals;
		rep(i,0,SZ(hull[0])-1)rep(j,0,SZ(hull[1])-1){
			vals.eb(get_val(dis[0][i],dis[1][j]),hull[0][i],hull[1][j]);
		}
		sort(vals.begin(),vals.end());
		reverse(vals.begin(),vals.end());
		rep(i,0,SZ(vals)-1){
			check(get<1>(vals[i]),get<2>(vals[i]));
		}
	}
	return 0;
}