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
const int N=100005;
const int M=10000005;
struct node{
	int l,r,T;
	bool operator <(const node &a)const{
		return l==a.l?r<a.r:l<a.l;
	}
};
set<node> S;
int n,Q,x[N],y[N],z[N];
int rt1[N],rt2[N],nd;
int ls[M],rs[M];
ll t[M];
void insert(int &nk,int k,int l,int r,int p,int v){
	nk=++nd; t[nk]=t[k]+v;
	ls[nk]=ls[k]; rs[nk]=rs[k];
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[nk],ls[k],l,mid,p,v);
	else insert(rs[nk],rs[k],mid+1,r,p,v);
}
ll ask(int k,int l,int r,int x,int y){
	if (!k||(l==x&&r==y)) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,mid)+ask(rs[k],mid+1,r,mid+1,y);
}
void split(int x){
	set<node>::iterator it;
	it=S.lower_bound((node){x,0,0});
	if (it!=S.end()&&it->l==x) return;
	assert(it!=S.begin()); it--;
	node tmp=*it; S.erase(it);
	S.insert((node){tmp.l,x-1,tmp.T});
	S.insert((node){x,tmp.r,tmp.T});
}
ll query(node tmp,int T){
	ll ans=0;
	if (tmp.T==-1)
		For(i,tmp.l,tmp.r)
			ans+=min(1ll*y[i],x[i]+1ll*T*z[i]);
	else{
		int dif=min(N-1,T-tmp.T);
		ans+=1ll*dif*(ask(rt1[tmp.r],0,N,dif,N)-ask(rt1[tmp.l-1],0,N,dif,N));
		ans+=ask(rt2[tmp.r],0,N,0,dif)-ask(rt2[tmp.l-1],0,N,0,dif);
	}
	//cout<<"Q "<<tmp.l<<' '<<tmp.r<<' '<<tmp.T<<' '<<T<<' '<<ans<<endl; 
	S.insert((node){n+1,n+1,-1});
	return ans;
}
ll ask(int l,int r,int T){
	set<node>::iterator it;
	it=S.lower_bound((node){l,0,0});
	ll ans=0;
	for (;it!=S.end()&&it->r<=r;S.erase(it++))
		ans+=query(*it,T);	
	S.insert((node){l,r,T});
	return ans;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		rt1[i]=rt1[i-1]; rt2[i]=rt2[i-1];
		if (!z[i]) continue;
		int clk=y[i]/z[i];
		insert(rt1[i],rt1[i],0,N,clk,z[i]);
		insert(rt2[i],rt2[i],0,N,clk+1,y[i]);
	}
	S.insert((node){n+1,n+1,-1});
	S.insert((node){1,n,-1});
	scanf("%d",&Q);
	while (Q--){
		int l,r,t;
		scanf("%d%d%d",&t,&l,&r);
		split(l); split(r+1);
		printf("%lld\n",ask(l,r,t));
	}
}