#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb long double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const ldb eps=1e-10;
const ldb PI=acos(-1);

struct pt{
	ldb x,y;
	pt(){}
	pt(int _x,int _y):x(_x),y(_y){}
	pt(ldb _x,ldb _y):x(_x),y(_y){}
};
pt operator - (pt a,pt b){return pt(a.x-b.x,a.y-b.y);}
pt operator + (pt a,pt b){return pt(a.x+b.x,a.y+b.y);}
pt operator * (pt a,ldb b){return pt(a.x*b,a.y*b);}
pt operator / (pt a,ldb b){return pt(a.x/b,a.y/b);}
ldb cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
ldb dot(pt a,pt b){return a.x*b.x+a.y*b.y;}
ldb sq(pt a){return dot(a,a);}
ldb abs(pt a){return sqrt(dot(a,a));}
ldb sq_dist(pt a,pt b){return sq(a-b);}
ldb dist(pt a,pt b){return abs(a-b);}
int sgn(ldb x){return x<0?-1:x>0?1:0;}

pt rot(pt a,ldb alpha){return pt(a.x*cos(alpha)-a.y*sin(alpha),a.x*sin(alpha)+a.y*cos(alpha));}
pt norm(pt a){return a/abs(a);}
ldb norm(ldb alpha){
	while(alpha>PI)alpha-=2*PI;
	while(alpha<=PI)alpha+=2*PI;
	return alpha;
}
ldb ang(pt a){return atan2(a.y,a.x);}

struct line{
	pt v;ldb c;
	line(pt a,pt b):v(a-b),c(cross(v,a)){}
	ldb side(pt p){return c-cross(v,p);}
	ldb dot(pt p){return ::dot(v,p);}
	ldb dist(pt p){
		return abs(side(p))/abs(v);
	}
};

struct circle{
	pt o;int r;
    circle(){}
    circle(int x,int y,int _r):o(x,y),r(_r){}
    bool sec(line l){
		ldb d=l.dist(o);
		if(d<=r-eps)return true;
		else return false;
    }
    bool is_tangent(line l){
		ldb d=l.dist(o);
		if(d>r-eps&&d<=r+eps)return true;
		else return false;
    }
};

const int N=1050;
circle C[N];
int n,k,sol;

int Solve(){
	sol=1;
	for(int i=1;i<=n;i++){
		vector<pair<ldb,int>> evs;
		int cnt=0;
		for(int j=1;j<=n;j++)if(j!=i){
			ldb beta=ang(C[j].o-C[i].o);
			ldb d=dist(C[i].o,C[j].o);
			ldb L1=beta+acos((C[i].r+C[j].r)/d)+eps;
			ldb R1=beta+abs(acos((C[i].r-C[j].r)/d));
			ldb L2=beta-abs(acos((C[i].r-C[j].r)/d));
			ldb R2=beta-acos((C[i].r+C[j].r)/d)-eps;
			L1=norm(L1);
			R1=norm(R1);
			L2=norm(L2);
			R2=norm(R2);
			if(L1>R1)cnt++;
			evs.pb({L1,1});
			evs.pb({R1,-1});
			if(L2>R2)cnt++;
			evs.pb({L2,1});
			evs.pb({R2,-1});
		}
		sort(evs.begin(),evs.end());
		for(auto e:evs){
			ckmx(sol,cnt+1);
			cnt+=e.second;
		}
	}
	return sol;
}
int main(){
	rd(n,k);
	for(int i=1;i<=n;i++){
		int x,y,r;rd(x,y,r);
		C[i]=circle(x,y,r);
	}
	ll ans=(ll)k*(k-1)/2+(ll)k*Solve()+n;
	printf("%lld\n",ans);
	return 0;
}