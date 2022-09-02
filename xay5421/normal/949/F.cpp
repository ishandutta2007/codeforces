// author: xay5421
// created: Tue Nov  9 11:01:35 2021
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
using LL=long long;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int N=2605;
int n;
struct vec{
	int x,y;
	bool operator<(const vec&k)const{return x!=k.x?x<k.x:y<k.y;}
	vec operator-(const vec&k)const{return (vec){x-k.x,y-k.y};}
	vec norm(){
		vec res=*this;
		if(res.x<0||(res.x==0&&res.y<0))res.x=-res.x,res.y=-res.y;
		int g=abs(__gcd(res.x,res.y));
		res.x/=g,res.y/=g;
		return res;
	}
	LL norm2(){
		vec res=*this;
		if(res.x<0||(res.x==0&&res.y<0))res.x=-res.x,res.y=-res.y;
		int g=abs(__gcd(res.x,res.y));
		res.x/=g,res.y/=g;
		return ((LL)res.x<<30)+res.y;
	}
}p[N*2];
set<vec>S;
struct ds{
	vector<LL>v;
	void ps(LL x){
		v.pb(x);
	}
	void init(){
		sort(v.begin(),v.end());
	}
	int count(const LL&x){
		return upper_bound(v.begin(),v.end(),x)-lower_bound(v.begin(),v.end(),x);
	}
}mp[N*2];
LL cross(vec k1,vec k2){return 1LL*k1.x*k2.y-1LL*k1.y*k2.x;}
bool chk(vec cur){
	if(!S.insert(cur).second)return 0;
	S.insert(cur);
	rep(i,1,n*2)if(mp[i].count((p[i]-cur).norm2())!=1){
		return 0;
	}
	puts("Yes");
	printf("%d %d\n",cur.x,cur.y);
	exit(0);
	return 1;
}
void sol(vec a,vec b,vec c,vec d){
	LL area[2]={cross(a-c,d-c),cross(d-c,b-c)};
	if(area[0]+area[1]==0)return;
	LL x=a.x*area[1]+b.x*area[0];
	LL y=a.y*area[1]+b.y*area[0];
	if(x%(area[0]+area[1])!=0)return;
	if(y%(area[0]+area[1])!=0)return;
	x/=area[0]+area[1],y/=area[0]+area[1];
	if(abs(x)>1000000||abs(y)>1000000)return;
	chk((vec){(int)x,(int)y});
}
int main(){
	scanf("%d",&n);
	rep(i,1,n*2)scanf("%d%d",&p[i].x,&p[i].y),S.insert(p[i]);
	shuffle(p+1,p+n*2+1,rng);
	rep(i,1,n*2){
		rep(j,1,n*2)if(i<j){
			auto cur=(p[i]-p[j]).norm2();
			mp[i].ps(cur);
			mp[j].ps(cur);
		}
	}
	rep(i,1,n*2)mp[i].init();
	rep(i,3,n*2){
		rep(j,3,n*2)if(i!=j){
			sol(p[1],p[i],p[2],p[j]);
			if(i<j){
				sol(p[1],p[2],p[i],p[j]);
			}
		}
	}
	puts("No");
	return 0;
}