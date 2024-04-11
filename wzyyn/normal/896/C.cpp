#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int n,m,seed,vm;
struct node{
	int l,r;
	mutable ll v;
	bool operator <(const node &x)const{
		return l<x.l;
	}
};
set<node> S; 
void split(int p){
	auto it=S.lower_bound((node){p,p,0});
//	cout<<it->l<<' '<<it->r<<' '<<it->v<<endl;
	if (it->l==p) return;
	--it;
	int l=it->l,r=it->r;
	ll v=it->v;
//	cout<<l<<' '<<p<<' '<<r<<endl;
	S.erase(it);
	S.insert((node){l,p-1,v});
	S.insert((node){p,r,v});
}
void add(int l,int r,int x){
	auto it=S.lower_bound((node){l,l,0});
	for (;it->l<=r;++it)
		it->v+=x;
}
void change(int l,int r,int x){
	auto it=S.lower_bound((node){l,l,0}),nxt=it;
	for (;it->l<=r;){
		nxt=it; ++nxt;
		S.erase(it); it=nxt;
	}
	S.insert((node){l,r,x});
}
ll kth(int l,int r,int x){
	vector<pll> tmp;
	auto it=S.lower_bound((node){l,l,0});
	for (;it->l<=r;++it)
		tmp.PB(pll(it->v,it->r-it->l+1));
	sort(tmp.begin(),tmp.end());
	for (auto i:tmp)
		if (x>i.se) x-=i.se;
		else return i.fi;
}
int power(int x,int y,int mo){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int pows(int l,int r,int k,int mo){
	int ans=0;
	auto it=S.lower_bound((node){l,l,0});
	for (;it->l<=r;++it){
	//	cout<<it->l<<' '<<it->r<<' '<<it->v<<endl;
		ans=(ans+1ll*(it->r-it->l+1)*power(it->v%mo,k,mo)%mo)%mo;
	}
	return ans;
}
int rnd(int x){
	int ans=seed;
	seed=(7ll*seed+13)%1000000007;
	return ans%x+1;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&seed,&vm);
	For(i,1,n) S.insert((node){i,i,rnd(vm)});
	S.insert((node){n+1,n+1,0});
	for (;m--;){
		int op=rnd(4);
		int l=rnd(n);
		int r=rnd(n);
		int x;
		if (l>r) swap(l,r);
		if (op==3) x=rnd(r-l+1);
		else x=rnd(vm);
		split(l);
		split(r+1);
		//cout<<op<<' '<<l<<' '<<r<<' '<<x<<endl;
		if (op==1) add(l,r,x);
		if (op==2) change(l,r,x);
		if (op==3) printf("%lld\n",kth(l,r,x));
		if (op==4) printf("%d\n",pows(l,r,x,rnd(vm)));
	}
}