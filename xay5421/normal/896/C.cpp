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
const int N=100005;
int n,m,seed,vmax,a[N];
int rnd(){
    int ret=seed;
    seed=(seed*7LL+13)%1000000007;
    return ret;
}
struct node{
	int l,r;
	mutable LL x;
	bool operator<(const node&rhs)const{
		return r<rhs.r;
	}
};
set<node>S;
set<node>::iterator split(int r){
	if(r==0)return S.begin();
	auto it=S.lower_bound((node){0,r,0});
	if(it->r==r){
		return next(it);
	}
	node cur=*it;
	S.erase(it);
	S.insert((node){cur.l,r,cur.x});
	return S.insert((node){r+1,cur.r,cur.x}).first;
}
void add(int l,int r,int x){
	auto rr=split(r);
	auto ll=split(l-1);
	for(auto it=ll;it!=rr;++it){
		it->x+=x;
	}
}
void set_(int l,int r,int x){
	auto rr=split(r);
	auto ll=split(l-1);
	S.erase(ll,rr);
	S.insert((node){l,r,x});
}
void sol3(int l,int r,int k){
	auto rr=split(r);
	auto ll=split(l-1);
	vector<tuple<LL,int> >v;
	for(auto it=ll;it!=rr;++it){
		v.eb(it->x,it->r-it->l+1);
	}
	sort(v.begin(),v.end());
	for(auto&x:v){
		if(k<=get<1>(x)){
			printf("%lld\n",get<0>(x));
			return;
		}
		k-=get<1>(x);
	}
}
int power(int a,int b,int mod){
	int c=1;
	for(;b;b>>=1,a=1LL*a*a%mod)if(b&1)c=1LL*c*a%mod;
	return c;
}
void sol4(int l,int r,int x,int y){
	auto rr=split(r);
	auto ll=split(l-1);
	int res=0;
	for(auto it=ll;it!=rr;++it){
		res=(res+1LL*power(it->x%y,x,y)*(it->r-it->l+1))%y;
	}
	printf("%d\n",res);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	rep(i,1,n)a[i]=rnd()%vmax+1,S.insert((node){i,i,a[i]});
	rep(i,1,m){
		int opt=rnd()%4+1;
		int l=rnd()%n+1;
		int r=rnd()%n+1;
		if(l>r)swap(l,r);
		int x,y;
		if(opt==3){
			x=rnd()%(r-l+1)+1;
		}else{
			x=rnd()%vmax+1;
		}
		if(opt==1){
			add(l,r,x);
		}else if(opt==2){
			set_(l,r,x);
		}else if(opt==3){
			D("!\n");
			sol3(l,r,x);
		}else{
			y=rnd()%vmax+1;
			D("y=%d\n",y);
			sol4(l,r,x,y);
		}
	}
	for(auto&x:S)D("%d %d\n",x.l,x.r);
	return 0;
}