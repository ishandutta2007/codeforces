#include <bits/stdc++.h>
using namespace std;
#define ll __int128
#define pll pair<ll,ll>
#define mp make_pair
ll abs(ll x){return x<ll(0)?-x:x;}
struct frac{
	ll p,q;
	frac(ll a=0,ll b=1):p(a),q(b){}
	bool operator<(frac b)const{return p*b.q<b.p*q;}
	bool operator>(frac b)const{return b<*this;}
	bool operator==(frac b)const{return p*b.q==b.p*q;}
	frac operator-(frac b)const{return frac(p*b.q-b.p*q,q*b.q);}
	frac operator*(frac b)const{return frac(p*b.p,q*b.q);}
};
template<typename T>struct pt{
	T x,y;
	pt():x(0),y(0){}
	pt(T a,T b):x(a),y(b){}
	pt(pll t):x(t.first),y(t.second){}
	int part()const{return x>T(0)||x==T(0)&&y>T(0)?1:2;}
	T cross(pt b)const{return x*b.y-b.x*y;}
	bool operator<(pt b)const{return mp(part(),cross(b))<mp(b.part(),T(0));}
	bool operator==(pt b)const{return x==b.x&&y==b.y;}
	pt operator-(pt b)const{return pt(x-b.x,y-b.y);}
};
pll get_dir(pt<frac> P){
	assert(P.x.q==P.y.q);
	ll a=P.x.p,b=P.y.p;
	ll g=__gcd(abs(a),abs(b));
	return {a/g,b/g};
}
ll one,two,zer;
pt<frac> goal;
map<ll,map<ll,int>> dir_cnt;
set<pt<ll>> pts;
pt<ll> getPre(set<pt<ll>>::iterator it){
	return it==pts.begin()?*pts.rbegin():*prev(it);
}
pt<ll> getNxt(set<pt<ll>>::iterator it){
	return next(it)==pts.end()?*pts.begin():*next(it);
}
void Add(pt<ll> x){
	pts.insert(x);
	auto it=pts.find(x);
	pt<ll> pre=getPre(it),nxt=getNxt(it);
	if(pre.cross(nxt)>0)zer--;
	if(pre.cross(x)>0)zer++;
	if(x.cross(nxt)>0)zer++;
}
void Del(pt<ll> x){
	auto it=pts.find(x);
	pt<ll> pre=getPre(it),nxt=getNxt(it);
	if(pre.cross(nxt)>0)zer++;
	if(pre.cross(x)>0)zer--;
	if(x.cross(nxt)>0)zer--;
	pts.erase(it);
}
void Cons(pt<frac> x,int f){
	if(x==goal)one+=f;
	else{
		pll dir=get_dir(x-goal);
		two+=dir_cnt[-dir.first][-dir.second]*f;
		dir_cnt[dir.first][dir.second]+=f;
		if(f==1){
			if(dir_cnt[dir.first][dir.second]==1)Add(pt<ll>(dir));
		}else{
			if(dir_cnt[dir.first][dir.second]==0)Del(pt<ll>(dir));
		}
	}
}
const int N=100050;
pt<frac> a[N];
int main(){
	int S,P,G;
	scanf("%i %i %i",&S,&P,&G);
	goal=pt<frac>(frac(S,S+P+G),frac(P,S+P+G));
	int n;
	scanf("%i",&n);
	int m=0;
	while(n--){
		char t;
		scanf("\n%c",&t);
		if(t=='A'){
			scanf("%i %i %i",&S,&P,&G);
			a[++m]=pt<frac>(frac(S,S+P+G),frac(P,S+P+G));
			Cons(a[m],1);
		}else{
			int x;scanf("%i",&x);
			Cons(a[x],-1);
		}
		if(one)printf("1\n");
		else if(two)printf("2\n");
		else if(zer||pts.size()<3)printf("0\n");
		else printf("3\n");
	}
	return 0;
}