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
const int inf=1000000000;
const int N=300005;
int l[N],r[N],n,rk;
struct node{
	int l,r,c;
	bool operator <(const node &a)const{
		return l==a.l?r<a.r:l<a.l;
	}
};
set<node> S;
vector<pii> dif[N];
void split(int p){
	set<node>::iterator it;
	it=S.lower_bound((node){p,0,0});
	if (it->l==p) return; it--;
	int l=it->l,r=it->r,c=it->c;
	S.erase(it);
	S.insert((node){l,p-1,c});
	S.insert((node){p,r,c});
}
void work(int l,int r,int id){
	set<node>::iterator it;
	it=S.lower_bound((node){l,0,0});
	for (;it->l<=r;S.erase(it++))
		dif[id].PB(pii(it->c,-(it->r-it->l+1)));
	dif[id].PB(pii(id,r-l+1));
	S.insert((node){l,r,id});
}
void build_chg(){
	S.clear();
	S.insert((node){1,inf,0});
	S.insert((node){inf+1,inf+1,0}); 
	For(i,1,n){
		split(l[i]);
		split(r[i]+1);
		work(l[i],r[i],i);
	}
}
ll Func(int v){
	static int a[N];
	memset(a,0,sizeof(a));
	int p=1,s=0; a[0]=inf;
	ll ans=0;
	For(i,1,n){
		for (auto j:dif[i]){
			a[j.fi]+=j.se;
			if (p<=j.fi) s+=j.se;
		}
		for (;s>=v;s-=a[p++]);
		ans+=p-1;
	}
	//cout<<v<<' '<<ans<<endl;
	return ans;
}
ll Func2(int v){
	static int a[N];
	memset(a,0,sizeof(a));
	int p=1,s=0; a[0]=inf;
	ll ans=0,ss=0,sss=0;
	For(i,1,n){
		for (auto j:dif[i]){
			a[j.fi]+=j.se;
			if (j.fi>=p) s+=j.se;
			sss+=1ll*min(j.fi,p-1)*j.se;
		}
		for (;s>=v;)
			sss+=s,s-=a[p++];
		ans+=sss;
	}
	//cerr<<v<<' '<<ans<<endl;
	return ans;
}
int main(){
	scanf("%d%d",&n,&rk);
	For(i,1,n) scanf("%d%d",&l[i],&r[i]),--r[i];
	build_chg();
	int l=0,r=inf,ans;
	while (l<=r){
		int mid=(l+r)/2;
		if (Func(mid)>=rk)
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	ll res=Func2(ans)-(Func(ans)-rk)*ans;
	printf("%lld\n",res);
}