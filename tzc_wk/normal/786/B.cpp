#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
const int D=5e5;
int n=read(),m=read(),st=read(),dist[1000005],leaf[100005];
vector<pii> g[1000005];
struct node{
	int l,r;
} s[100005<<2];
inline void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;
	if(l==r){
		leaf[l]=k;
		return;
	}
	int mid=(l+r)>>1;
	g[k].push_back(pii(k<<1,0));
	g[k].push_back(pii(k<<1|1,0));
	g[(k<<1)+D].push_back(pii(k+D,0));
	g[(k<<1|1)+D].push_back(pii(k+D,0));
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
inline void connect(int k,int l,int r,int v,int w,int tp){
	if(l<=s[k].l&&s[k].r<=r){
		if(tp) g[k+D].push_back(pii(v,w));
		else g[v].push_back(pii(k,w));
		return;
	}
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) connect(k<<1,l,r,v,w,tp);
	else if(l>mid) connect(k<<1|1,l,r,v,w,tp);
	else connect(k<<1,l,mid,v,w,tp),connect(k<<1|1,mid+1,r,v,w,tp);
}
signed main(){
	build(1,1,n);
	fz(i,1,m){
		int opt=read();
		if(opt==1){
			int v=read(),u=read(),w=read();
			g[leaf[v]].push_back(pii(leaf[u],w));
		}
		else{
			int v=read(),l=read(),r=read(),w=read();
			connect(1,l,r,leaf[v],w,opt%2);
		}
	}
	fz(i,1,n) g[leaf[i]].push_back(pii(leaf[i]+D,0)),g[leaf[i]+D].push_back(pii(leaf[i],0));
	priority_queue<pii,vector<pii>,greater<pii> > q;
	fillbig(dist);dist[leaf[st]+D]=0;q.push(pii(0,leaf[st]+D));
	while(!q.empty()){
		pii p=q.top();q.pop();
		int x=p.se,sum=p.fi;
//		cout<<x<<endl;
		if(dist[x]<sum) continue;
		foreach(it,g[x]){
			int y=it->fi,z=it->se;
			if(dist[y]>sum+z){
				dist[y]=sum+z;
				q.push(pii(dist[y],y));
			}
		}
	}
	fz(i,1,n){
		if(dist[leaf[i]]==0x3f3f3f3f3f3f3f3fll) printf("-1 ");
		else printf("%lld ",dist[leaf[i]]);
	}
	return 0;
}