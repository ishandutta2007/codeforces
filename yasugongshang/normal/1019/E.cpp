#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=200005;
int n,m,Quan,sz[N],vis[N],rt,frt;
struct P{
	ll x,y;
	P operator +(const P &a){
		return (P){x+a.x,y+a.y};
	}
	P operator -(const P &a){
		return (P){x-a.x,y-a.y};
	}
	ll operator *(const P &a){
		return x*a.y-y*a.x;
	}
	ll get(int k){
		return x*k+y;
	}
};
vector<P> l,r,all;
vector<pair<int,P> > e[N],v[N];
void rebuild(int p,int fa){
	for(auto i:e[p])if(i.first!=fa)rebuild(i.first,p);
	int t=p,flag=0;
	for(auto i:e[p])if(i.first!=fa){
		if(flag){
			v[++n].push_back(mp(t,(P){0,0}));
			v[t].push_back(mp(n,(P){0,0}));
			t=n;
		}
		flag=1;
		v[t].push_back(i);
		v[i.first].push_back(mp(t,i.second));
	}
}
void dfs(int p,int fa,P dq,bool flag){
	if(flag)r.push_back(dq); else l.push_back(dq);
	for(auto i:v[p])if(i.first!=fa&&!vis[i.first]){
		dfs(i.first,p,dq+i.second,flag||(i.first==rt));
	}
}
bool cmp(const P &a,const P &b){
	return a.x==b.x?a.y>b.y:a.x<b.x;
}
void convex(vector<P> &v){
	vector<P> ans; ans.clear();
	sort(v.begin(),v.end(),cmp);
	int m=0;
	for (int i=0;i<v.size();i++){
		if (i&&v[i].x==v[i-1].x) continue;
		for (;m&&ans[m-1].y<=v[i].y;ans.pop_back(),m--);
		for (;m>1&&(v[i]-ans[m-2])*(ans[m-1]-ans[m-2])<=0;ans.pop_back(),m--);
		ans.push_back(v[i]),m++;
	}
	swap(ans,v);
}
void Alb(vector<P> a,vector<P> b){
	all.push_back(a[0]+b[0]); 
	for (int i=0,j=0;i+1<a.size()||j+1<b.size();)
		if (j+1==b.size()||(i+1<a.size()&&(a[i+1]-a[i])*(b[j+1]-b[j])<0))
			all.push_back(a[++i]+b[j]);
		else all.push_back(a[i]+b[++j]);
}
void findrt(int p,int fa){
	sz[p]=1;
	for(auto i:v[p])if(i.first!=fa&&!vis[i.first]){findrt(i.first,p); sz[p]+=sz[i.first];}
	if(!rt||max(sz[p],Quan-sz[p])<max(sz[rt],Quan-sz[rt])){
		rt=p; frt=fa;
	}
	//cout<<Quan<<" wzp "<<sz[p]<<endl;
}
void divide(int p,int quan){
	if(quan==1)return;
	rt=0; Quan=quan;
	findrt(p,0);
	int u=rt,v=frt,tmp=sz[u]; 
	l.clear(); r.clear(); 
	dfs(v,0,(P){0,0},0); 
	/*cout<<p<<" cqz "<<rt<<" "<<frt<<endl;
	for(auto i:l)cout<<i.x<<" lcb "<<i.y<<endl;
	for(auto i:r)cout<<i.x<<" xsj "<<i.y<<endl; puts("");*/
	convex(l); convex(r);
	Alb(l,r);
	vis[v]=1; divide(u,tmp); vis[v]=0;
	vis[u]=1; divide(v,quan-tmp); vis[u]=0;
}
int main(){
	n=read(); m=read();
	if(n==1){
		while(m--)wri(0); return 0;
	}
	for(int i=1;i<n;i++){
		int s=read(),t=read(),x=read(),y=read();
		e[s].push_back(mp(t,(P){x,y})); e[t].push_back(mp(s,(P){x,y}));
	}
	rebuild(1,0); //for(int i=1;i<=n;i++)for(auto j:v[i])cout<<i<<" "<<j.first<<endl;
	divide(1,n);
	convex(all);
	unsigned j=0;
	for(int i=0;i<m;i++){
		while(j+1<all.size()&&all[j].get(i)<all[j+1].get(i))j++;
		wri(all[j].get(i));
	}
}