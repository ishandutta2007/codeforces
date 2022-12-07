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
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	P operator +(const P &a)const{
		return P(x+a.x,y+a.y);
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
	ll operator ^(const P &a)const{
		return 1ll*x*a.x+1ll*y*a.y;
	}
	bool operator <(const P &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
};
ll Dis(P x,P y){
	return (x-y)^(x-y);
}
vector<P> init(vector<P> p){
	vector<P> ans;
	int pos=min_element(p.begin(),p.end())-p.begin();
	For(i,0,p.size()-1) ans.PB(p[(i+pos)%p.size()]);
	return ans;
}
vector<P> Mincowski(vector<P> a,vector<P> b){
	a=init(a); b=init(b);
	int sza=a.size(),szb=b.size();
	vector<P> ans,A(sza),B(szb);
	For(i,0,sza-1) A[i]=a[(i+1)%sza]-a[i];
	For(i,0,szb-1) B[i]=b[(i+1)%szb]-b[i];
	int i=0,j=0; ans.PB(a[0]+b[0]);
	for (;i<sza||j<szb;)
		if (j==szb) ans.PB(ans.back()+A[i++]);
		else if (i==sza) ans.PB(ans.back()+B[j++]);
		else ans.PB(ans.back()+(A[i]*B[j]>=0?A[i++]:B[j++]));
	ans.pop_back();
	return ans;
}
bool online(P p,P l,P r){
	return ((p-l)*(p-r))==0&&((p-l)^(p-r))<=0;
}
bool check(P p,ll R,vector<P> q){
	//cout<<p.x<<' '<<p.y<<' '<<R<<endl;
	for (auto i:q) if (Dis(i,p)<R*R) return 1;
	//cout<<"axiba"<<endl;
	bool flag=1;
	For(i,0,q.size()-1){
		P l=q[i],r=q[(i+1)%q.size()];
		//cout<<i<<endl;
		if (online(p,l,r)) return 1;
		//cout<<i<<endl;
		if (((p-l)^(r-l))>0&&((p-r)^(l-r))>0){
			ll x=abs((p-l)*(r-l));
			if (x*x<R*R*Dis(l,r)) return 1;
		}
		flag&=((p-l)*(r-l)<=0);
	}
	return flag;
}
const int N=405;
struct edge{
	int to,next,f;
}e[N*N];
int head[N],dis[N],q[N];
int n,m,W,S,T,tot=1;
void add(int x,int y,int v){
	//cout<<x<<' '<<y<<' '<<v<<endl;
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	For(i,1,T) dis[i]=-1;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
				q[++t]=e[i].to;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			int k=dfs(e[i].to,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d%d",&n,&W);
	vector<P> p(n),q(n);
	For(i,0,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		p[i]=P(x,y); q[i]=P(-x,-y);
	}
	int mn=p[0].x,mx=p[0].x;
	For(i,0,n-1){
		mn=min(mn,p[i].x);
		mx=max(mx,p[i].x);
	}
	p=Mincowski(p,q);
	//for (auto i:p) cout<<i.x<<' '<<i.y<<endl;
	
	scanf("%d",&m);
	vector<P> o(m+1);
	vector<int> R(m+1);
	For(i,1,m) scanf("%d%d%d",&o[i].x,&o[i].y,&R[i]);
	S=m*2+1; T=S+1;
	For(i,1,m){
		add(i*2-1,i*2,1);
		if (mx-mn>o[i].x-R[i]) add(S,2*i-1,1<<30);
		if (mx-mn>W-o[i].x-R[i]) add(2*i,T,1<<30);
	}
	For(i,1,m) For(j,i+1,m)
		if (check(o[i]-o[j],R[i]+R[j],p)){
			add(i*2,j*2-1,1<<30);
			add(j*2,i*2-1,1<<30);
		}
	int ans=0;
	for (;bfs();ans+=dfs(S,1<<30));
	printf("%d\n",ans);
}