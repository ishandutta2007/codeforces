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
const int K=50;
const int N=100005;
const int M=(1<<18)+1;
int n,Q;
char s[N];
int fa[N][17],dep[N];
int ch[N][26],nd=1,pos[N];
int id[N],vl[N],vr[N];
set<pii> S;
struct TRMX{
	int t[M],nn;
	void init(){
		for (nn=1;nn<=n+1;nn<<=1);
	}
	void change(int p,int v){
		//cout<<"CHG "<<p<<' '<<v<<endl;
		p+=nn; t[p]=v;
		for (p>>=1;p;p>>=1) t[p]=max(t[p<<1],t[p<<1|1]);
	}
	int ask(int l,int r){
		l+=nn-1; r+=nn+1; int ans=0;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=max(ans,t[l^1]);
			if (r&1)    ans=max(ans,t[r^1]);
		}
		return ans;
	}
}MXL;
int nn;
struct node{
	int S,vl,vr,mx;
	node operator +(const node &a)const{
		return (node){S+a.S,vl+(vl==S?a.vl:0),a.vr+(a.vr==a.S?vr:0),max(max(mx,a.mx),vr+a.vl)};
	}
}t[K+1][M],TAK,NIE;
void init(){
	TAK=(node){1,1,1,1};
	NIE=(node){1,0,0,0};
	for (nn=1;nn<=n+1;nn<<=1);
	For(i,1,K){
		For(j,1,n) t[i][j+nn]=NIE;
		Rep(j,nn-1,1) t[i][j]=t[i][j<<1]+t[i][j<<1|1];
	}
}
void change(node *t,int p,node v){
	t[p+=nn]=v;
	for (p>>=1;p;p>>=1) t[p]=t[p<<1]+t[p<<1|1];
}
node ask(node *t,int l,int r){
	l+=nn-1; r+=nn+1;
	node a=NIE,b; a.S=0; b=a;
	for (;l^r^1;l>>=1,r>>=1){
		if (!(l&1)) a=a+t[l^1];
		if ((r&1))  b=t[r^1]+b;
	}
	//if ((a+b).mx) cout<<"info "<<(a+b).mx<<endl;
	return a+b;
}
int LCP(int x,int y){
	x=pos[x]; y=pos[y];
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,16) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,16,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return dep[x]-(x!=y);
}
void insert(int p){
	int x=LCP(p,p+1);
	//cout<<"insert "<<x<<' '<<p<<endl;
	For(i,1,min(x,K)) change(t[i],p,TAK);
	if (x>K) S.insert(pii(-x,p));
}
void erase(int p){
	int x=LCP(p,p+1);
	For(i,1,min(x,K)) change(t[i],p,NIE);
	if (x>K) S.erase(pii(-x,p));
}
void insert_string(int x){
	scanf("%s",s+1);
	int p=1,len=strlen(s+1);
	MXL.change(x,len);
	For(i,1,len){
		int c=s[i]-'a';
		if (!ch[p][c]){
			ch[p][c]=++nd;
			fa[nd][0]=p;
			dep[nd]=i;
			For(j,1,16)
				fa[nd][j]=fa[fa[nd][j-1]][j-1];
		}
		p=ch[p][c];
	}
	pos[x]=p;
}
void change(){
	int x;
	scanf("%d",&x);
	if (x!=1) erase(x-1);
	if (x!=n) erase(x);
	insert_string(x);
	if (x!=1) insert(x-1);
	if (x!=n) insert(x);
}
void solve(){
	int l,r;
	scanf("%d%d",&l,&r);
	int ans=MXL.ask(l,r);
	//cout<<"LEN "<<ans<<endl;
	if (l!=r){
		r--;
		For(i,1,K){
			int v=ask(t[i],l,r).mx;
			if (v) ans=max(ans,(v+1)*i);
		}//ans=max(ans,ask(t[i],l,r).mx*i);
		for (auto i:S){
			int x=i.se,L=x,R=x;
			if (x<l||x>r) continue;
			if (x!=l&&vl[x-1]) L=vl[x-1];
			if (x!=r&&vr[x+1]) R=vr[x+1];
			//cout<<L<<' '<<R<<' '<<x<<endl;
			ans=max(ans,-i.fi*(R-L+2));
			vr[L]=R; vl[R]=L;
		}
		for (auto i:S){
			int x=i.se;
			vl[x]=vr[x]=0; 
		} 
	}
	printf("%d\n",ans);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&Q);
	MXL.init(); init();
	For(i,1,n) insert_string(i);
	For(i,1,n-1) insert(i);
	while (Q--){
		int tp;
		scanf("%d",&tp);
		if (tp==2) change();
		else solve();
	}
}