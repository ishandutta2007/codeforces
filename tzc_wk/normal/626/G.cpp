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
const int MAXN=2e5;
const double EPS=1e-10;
const double INF=1e18;
const int MAGIC=15;
int n,t,qu,p[MAXN+5],l[MAXN+5],c[MAXN+5];
double dif(int x,int c){
	if(!c) return INF;if(c>l[x]) return 0;
	return 1.0*p[x]*l[x]/(c+l[x])/(c-1+l[x]);
}
struct node{
	double val;int x,y;
	node(int _x=0,int _y=0){val=dif(_x,_y);x=_x;y=_y;}
	bool operator <(const node &rhs) const{
		return (fabs(val-rhs.val)>EPS)?(val<rhs.val):(x<rhs.x);
	}
};
double ans=0;
set<node> nw,cur;
void ins(){
	node t=*nw.rbegin();int x=t.x;//assert(fabs(t.val-dif(x,c[x]+1))<EPS);
	nw.erase(nw.find(node(x,c[x]+1)));cur.erase(cur.find(node(x,c[x])));
	ans+=t.val;c[x]++;
	nw.insert(node(x,c[x]+1));cur.insert(node(x,c[x]));
}
void del(){
	node t=*cur.begin();int x=t.x;//assert(fabs(t.val-dif(x,c[x]))<EPS);
	nw.erase(nw.find(node(x,c[x]+1)));cur.erase(cur.find(node(x,c[x])));
	ans-=t.val;c[x]--;
	nw.insert(node(x,c[x]+1));cur.insert(node(x,c[x]));
}
int main(){
	scanf("%d%d%d",&n,&t,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	for(int i=1;i<=n;i++) nw.insert(node(i,c[i]+1)),cur.insert(node(i,c[i]));
	for(int i=1;i<=t;i++) ins();
	while(qu--){
		int opt,x;scanf("%d%d",&opt,&x);
//		assert(cur.find(node(x,c[x]))!=cur.end());
		nw.erase(nw.find(node(x,c[x]+1)));cur.erase(cur.find(node(x,c[x])));
		ans-=1.0*p[x]*min(c[x],l[x])/(l[x]+min(c[x],l[x]));
		l[x]+=((opt==1)?(1):(-1));
		nw.insert(node(x,c[x]+1));cur.insert(node(x,c[x]));
		ans+=1.0*p[x]*min(c[x],l[x])/(l[x]+min(c[x],l[x]));
		for(int i=1;i<=MAGIC;i++) del(),ins();
		printf("%.15lf\n",ans);
	}
	return 0;
}