#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=3e5;
int n;map<pii,int> tim;
int f[MAXN*2+5],dep[MAXN*2+5],sz1[MAXN*2+5],sz2[MAXN*2+5];
int find(int x){return (!f[x])?x:find(f[x]);}
stack<pair<pii,int> > stk;
ll ans=0;
void merge(int x,int y){
//	printf("merge %d %d\n",x,y);
	x=find(x);y=find(y);
	if(x!=y){
		if(dep[x]<dep[y]) swap(x,y);
		ans-=1ll*sz1[x]*sz2[x];
		ans-=1ll*sz1[y]*sz2[y];
		stk.push(mp(mp(x,y),(dep[x]==dep[y])));
		f[y]=x;dep[x]+=(dep[x]==dep[y]);
		sz1[x]+=sz1[y];sz2[x]+=sz2[y];
		ans+=1ll*sz1[x]*sz2[x];
	}
}
void del(){
	pair<pii,int> p=stk.top();stk.pop();
	int x=p.fi.fi,y=p.fi.se,z=p.se;
//	printf("del %d %d\n",x,y);
	dep[x]-=z;ans-=1ll*sz1[x]*sz2[x];
	sz1[x]-=sz1[y];sz2[x]-=sz2[y];f[y]=0;
	ans+=1ll*sz1[x]*sz2[x];ans+=1ll*sz1[y]*sz2[y];
}
struct node{int l,r;vector<pii> v;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int l,int r,pii x){
	if(l<=s[k].l&&s[k].r<=r){s[k].v.pb(x);return;}
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
}
void iterate(int k){
	int tmp=stk.size();
	for(int i=0;i<s[k].v.size();i++){
		int x=s[k].v[i].fi,y=s[k].v[i].se;
		merge(x,y+MAXN);
	}
	if(s[k].l==s[k].r) printf("%lld ",ans);
	else iterate(k<<1),iterate(k<<1|1);
	while(stk.size()>tmp) del();
}
int main(){
	scanf("%d",&n);build(1,1,n);
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(!tim[mp(x,y)]) tim[mp(x,y)]=i;
		else modify(1,tim[mp(x,y)],i-1,mp(x,y)),tim[mp(x,y)]=0;
	}
	for(map<pii,int>::iterator it=tim.begin();it!=tim.end();it++){
		pii x=it->fi;int val=it->se;
		if(val) modify(1,val,n,x);
	} for(int i=1;i<=MAXN;i++){
		dep[i]=dep[i+MAXN]=1;
		sz1[i]=1;sz2[i+MAXN]=1;
	}
	iterate(1);
	return 0;
}
/*
4
1 1
1 1
1 1
1 1
*/