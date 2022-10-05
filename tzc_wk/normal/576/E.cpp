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
const int MAXN=5e5;
const int MAXK=50;
int n,m,k,qu,u[MAXN+5],v[MAXN+5],pre[MAXN+5],col[MAXN+5];
struct event{int e,t;} a[MAXN+5];
int f[MAXK+5][MAXN*2+5],dep[MAXK+5][MAXN*2+5];
int find(int x,int c){return (!f[c][x])?x:find(f[c][x],c);}
stack<pair<pii,pii> > stk;
void merge(int x,int y,int c){
	x=find(x,c);y=find(y,c);
	if(x!=y){
		if(dep[c][x]<dep[c][y]) swap(x,y);
		f[c][y]=x;stk.push(mp(mp(x,y),mp(c,(dep[c][x]==dep[c][y]))));
		dep[c][x]+=(dep[c][x]==dep[c][y]);
	}
}
void del(){
	pair<pii,pii> p=stk.top();stk.pop();
	int x=p.fi.fi,y=p.fi.se,c=p.se.fi,z=p.se.se;
	f[c][y]=0;dep[c][x]-=z;
}
struct node{int l,r;vector<int> v;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void add(int k,int l,int r,int x){
	if(l>r) return;
	if(l<=s[k].l&&s[k].r<=r){s[k].v.pb(x);return;}
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) add(k<<1,l,r,x);
	else if(l>mid) add(k<<1|1,l,r,x);
	else add(k<<1,l,mid,x),add(k<<1|1,mid+1,r,x);
}
void iterate(int k){
	int tmp=stk.size();
	for(int i=0;i<s[k].v.size();i++){
		int id=s[k].v[i],ce=a[id].e,ct=a[id].t,cu=u[ce],cv=v[ce];
		if(ct) merge(cu+n,cv,ct);merge(cu,cv+n,ct);
	}
	if(s[k].l==s[k].r){
		int ce=a[s[k].l].e,ct=a[s[k].l].t,cu=u[ce],cv=v[ce];
		if(find(cu,ct)==find(cv,ct)) printf("NO\n"),a[s[k].l].t=col[ce];
		else printf("YES\n"),col[ce]=a[s[k].l].t;
	} else iterate(k<<1),iterate(k<<1|1);
	while(stk.size()>tmp) del();
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&qu);build(1,1,qu);
	for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	for(int i=1;i<=qu;i++) scanf("%d%d",&a[i].e,&a[i].t);
	for(int i=1;i<=qu;i++){
		if(!pre[a[i].e]) pre[a[i].e]=i;
		else add(1,pre[a[i].e]+1,i-1,pre[a[i].e]),pre[a[i].e]=i;
	}
	for(int i=1;i<=m;i++) if(pre[i]) add(1,pre[i]+1,qu,pre[i]);
	iterate(1);
	return 0;
}