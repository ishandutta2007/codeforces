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

const ldb PI=acos(-1);
template<typename T> struct pt{
	T x,y;
	pt(){}
	pt(T a,T b):x(a),y(b){}
};
template<typename T> pt<T> operator + (pt<T> a,pt<T> b){return pt<T>(a.x+b.x,a.y+b.y);}
template<typename T> pt<T> operator - (pt<T> a,pt<T> b){return pt<T>(a.x-b.x,a.y-b.y);}
template<typename T> pt<T> operator * (pt<T> a,T b){return pt<T>(a.x*b,a.y*b);}
template<typename T> pt<T> operator / (pt<T> a,T b){return pt<T>(a.x/b,a.y/b);}
template<typename T> T dot(pt<T> a,pt<T> b){return a.x*b.x+a.y*b.y;}
template<typename T> T cross(pt<T> a,pt<T> b){return a.x*b.y-a.y*b.x;}
template<typename T> ldb abs(pt<T> a){return sqrt(dot(a,a));}

template<typename T> bool operator == (pt<T> a,pt<T> b){
	return cross(a,b)==0;
}
template<typename T> bool operator != (pt<T> a,pt<T> b){
	return cross(a,b)!=0;
}
template<typename T> bool operator < (pt<T> a,pt<T> b){
	return cross(a,b)<0;
}
template<typename T> bool operator <= (pt<T> a,pt<T> b){
	return cross(a,b)<=0;
}

struct line{
	pt<ldb> v;ldb c;
	line(){}
	line(pt<ldb> a,pt<ldb> b):v(b-a),c(cross(v,b)){}
};
pt<ldb> sec(line a,line b){return (b.v*a.c-a.v*b.c)/cross(a.v,b.v);}

const int N=200050;
int x[N],y[N];
set<pair<pair<pt<ll>,pt<ll>>,int>> segs;
void split(pt<ll> x){
	auto it=segs.lower_bound({{x,x},0});
	if(it==segs.begin())return;
	it--;
	if(x<it->first.second){
		int i=it->second;
		pt<ll> L=it->first.first;
		pt<ll> R=it->first.second;
		segs.erase(it);
		segs.insert({{L,x},i});
		segs.insert({{x,R},i});
	}
}
int main(){
	cout<<fixed<<setprecision(12);
	int n,h;
	rd(n,h);
	ra(x,y,n);
	pt<ldb> H=pt<ldb>(x[n],y[n]+h);
	pt<ll> Hll=pt<ll>(x[n],y[n]+h);
	int dir=2;
	for(int i=2;i<=n;i++){
		pt<ll> A=pt<ll>(x[i-1],y[i-1]);
		pt<ll> B=pt<ll>(x[i],y[i]);
		pt<ll> L=A-Hll;
		pt<ll> R=B-Hll;
		int ndir;
		if(R<L)swap(L,R),ndir=1;
		else if(L==R)ndir=0;
		else ndir=2;
		split(L);
		split(R);
		if(L!=R){
			/*if(ndir!=dir&&ndir!=2){
				segs.erase(segs.upper_bound({{L,L},N}),segs.lower_bound({{R,R},0}));
			}else{
				if(ndir==2)segs.erase(segs.lower_bound({{L,L},0}),segs.lower_bound({{R,R},0}));
				else segs.erase(segs.upper_bound({{L,L},N}),segs.upper_bound({{R,R},N}));
			}*/
			segs.erase(segs.lower_bound({{L,L},0}),segs.lower_bound({{R,R},0}));
		}
		if(ndir!=0)dir=ndir;
		//printf(":D\n");

		/*auto it=segs.lower_bound({{L,-1e9},0});
		while(it!=segs.end()){
			//auto seg=*it;
			//cout<<"("<<seg.first.first<<", "<<seg.first.second<<") "<<seg.second<<" !\n";
			if(it->second<=R)segs.erase(it++);
			else break;
		}*/
		segs.insert({{L,R},i});
		//for(auto seg:segs)cout<<seg.second<<" |";
		//cout<<"\n";
	}
	ldb ans=0;
	for(auto seg:segs){
		int i=seg.second;
		pt<ll> _L=seg.first.first;
		pt<ll> _R=seg.first.second;
		pt<ldb> L=pt<ldb>(_L.x,_L.y);
		pt<ldb> R=pt<ldb>(_R.x,_R.y);
		if(cross(pt<ll>(x[i-1],y[i-1])-Hll,pt<ll>(x[i],y[i])-Hll)==0){
			ans+=abs(pt<ldb>(x[i-1],y[i-1])-pt<ldb>(x[i],y[i]));
			//cout<<i<<" "<<abs(pt(x[i-1],y[i-1])-pt(x[i],y[i]))<<"\n";
		}else{
			pt<ldb> p1=H+L;
			pt<ldb> p2=H+R;
			line l1=line(H,p1);
			line l2=line(H,p2);
			line sl=line(pt<ldb>(x[i-1],y[i-1]),pt<ldb>(x[i],y[i]));
			pt<ldb> A=sec(l1,sl);
			pt<ldb> B=sec(l2,sl);
			ans+=abs(A-B);
			//cout<<i<<" "<<abs(A-B)<<"\n";
		}
	}
	cout<<ans<<"\n";
	return 0;
}