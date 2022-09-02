// author: xay5421
// created: Thu Apr 22 11:07:21 2021
#include<bits/stdc++.h>
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const double eps=1e-8;
const int N=1005;
int n;
int sgn(double x){return fabs(x)<eps?0:x<0?-1:1;}
struct vec{
	double x,y;
	bool operator<(const vec&k)const{
		int k1=sgn(x-k.x);
		if(k1!=0)return k1<0;
		return sgn(y-k.y)<0;
	}
	double _len(){return x*x+y*y;}
	double len()const{return sqrt(x*x+y*y);}
	vec norm()const{
		return (vec){x/len(),y/len()};
	}
	void trans(){
		double t=_len();
		x/=t,y/=t;
	}
	vec operator+(const vec&k)const{
		return(vec){x+k.x,y+k.y};
	}
	vec operator-(const vec&k)const{
		return(vec){x-k.x,y-k.y};
	}
}p[N];
map<vec,map<vec,int> >cnt;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		p[i]=(vec){1.*a/b,1.*c/d};
		p[i].trans();
	}
	rep(i,1,n){
		rep(j,i+1,n){
			++cnt[p[i]+p[j]][(max(p[i],p[j])-min(p[i],p[j])).norm()];
		}
	}
	int res=0;
	for(auto&x:cnt){
		if(SZ(x.Y)==1)continue;
		int cur=1,sum=0;
		for(auto&y:x.Y){
			cur=mu(cur,y.Y+1);
			uad(sum,y.Y);
		}
		usu(cur,ad(sum,1));
		uad(res,cur);
	}
	printf("%d\n",res);
	return 0;
}