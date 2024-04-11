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
const double _0=1e-10;
struct pos{
	double x,y;
	pos operator+(pos w){return (pos){x+w.x,y+w.y};}
	pos operator-(pos w){return (pos){x-w.x,y-w.y};}
	pos operator*(double k){return (pos){x*k,y*k};}
	double abs(){return sqrt(x*x+y*y);}
	double atan2(){return ::atan2(y,x);}
	bool operator<(pos w)const{return x<w.x;}
}ps[50007],ps2[50007];
double _c=cos(0.937),_s=sin(0.937);
void mins(double&a,double b){if(a>b)a=b;}
struct dir{
	double d;int t;
	bool operator<(dir w)const{return d<w.d;}
}ds[100007];
const double pi=acos(-1),_2pi=pi*2;
double fix(double x){
	while(x<0)x+=_2pi;
	while(x>=_2pi)x-=_2pi;
	return x;
}
void Solve(vector<pair<double, double>> PTS, int m, double& ans){
        int n = (int) PTS.size();
	for(int i=1;i<=n;++i){
		double x,y;
	        x = PTS[i - 1].first;
	        y = PTS[i - 1].second;
		ps[i]=ps2[i]=(pos){_c*x+_s*y,-_s*x+_c*y};
	}
	srand(n+m+2571);
	std::random_shuffle(ps+1,ps+n+1);
	for(int i=1;i<=n;++i)std::swap(ps[rand()%n+1],ps[rand()%n+1]);
	std::sort(ps2+1,ps2+n+1);
	for(int i=1;i<=n;++i){
		double L=0,R=ans,M;
		bool ed=0;
		while((R-L)/max(1.0, L)>_0){
			if (L < 1 && R > 1) M=1; else
			if (L < 1) M = (L+R)/2;
			else M = sqrt(L*R);
			if(!ed)M=R,ed=1;
			int ls=std::lower_bound(ps2+1,ps2+n+1,(pos){ps[i].x-M*2-_0,0})-ps2;
			int rs=std::upper_bound(ps2+1,ps2+n+1,(pos){ps[i].x+M*2+_0,0})-ps2;
			int c=0,ab=0;
			if(rs-ls>=m){
				int dp=0;
				for(int j=ls;j<rs;++j){
					pos p=ps2[j]-ps[i];
					double d=p.abs(),r=M*2;
					if(d>r)continue;
					if(d<_0){
						++c;
						continue;
					}
					double a=p.atan2(),b=asin(sqrt(1-d*d/(r*r)));
					double la=fix(a-b),ra=fix(a+b);
					if(la>ra)++c;
					ds[dp++]=(dir){la,1};
					ds[dp++]=(dir){ra,-1};
				}
				std::sort(ds,ds+dp);
				if(c>=m)ab=1;
				for(int j=0;j<dp;++j){
					c+=ds[j].t;
					if(c>=m)ab=1;
				}
			}
			if(ab)R=ans=M;
			else L=M;
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		int n,l,K;
		scanf("%d%d%d",&n,&l,&K);
		vector<int>x(n),y(n);
		rep(i,0,n-1)scanf("%d%d",&x[i],&y[i]);
		set<pair<int,int> >S;
		double ans=2e8;
		rep(i,0,n-1){
			S.emplace(x[i],y[i]);
			if(i>=l){
				S.erase(make_pair(x[i-l],y[i-l]));
			}
			auto it=S.lower_bound(make_pair(x[i]-ans*2-2,0));
			vector<pair<double,double> >ps;
			while(it!=S.end()){
				if(it->first>=x[i]+ans*2+2)break;
				if(sqrt(LL(x[i]-it->first)*(x[i]-it->first)+LL(y[i]-it->second)*(y[i]-it->second))<=ans*2){
					ps.eb(it->first,it->second);
				}
				++it;
			}
			if(SZ(ps)>=K)Solve(ps,K,ans);
		}
		printf("%.20f\n",ans);
	}
	return 0;
}