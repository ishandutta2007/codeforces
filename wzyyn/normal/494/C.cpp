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
const int N=100005,M=5005;
int n,Q,a[N];
int t[N*4],nn;
int bas[M],sz[M];
double f[M][M];
vector<int> e[N];
struct node{
	int l,r;
	double p;
}q[M];
void build(){
	for (nn=1;nn<=n;nn<<=1);
	For(i,1,n) t[i+nn]=a[i];
	Rep(i,nn-1,1) t[i]=max(t[i<<1],t[i<<1|1]);
}
int ask(int l,int r){
	l+=nn-1; r+=nn+1;
	int ans=0;
	for (;l^r^1;l>>=1,r>>=1){
		if (!(l&1)) ans=max(ans,t[l^1]);
		if (r&1)	ans=max(ans,t[r^1]);
	}
	return ans;
}
void solve(int x){
	sz[x]=1;
	bas[x]=ask(q[x].l,q[x].r);
	for (auto i:e[x]) solve(i),sz[x]+=sz[i];
	For(i,0,sz[x]) f[x][i]=1;
	for (auto i:e[x]){
		int p=0; double S=0;
		For(j,0,sz[x]){
			for (;p<=sz[i]&&bas[i]+p<=bas[x]+j;) S+=f[i][p],++p;
			f[x][j]*=S;
		}
	}
	Rep(i,sz[x],1) f[x][i]-=f[x][i-1];
	Rep(i,sz[x],1){
		f[x][i]+=f[x][i-1]*q[x].p;
		f[x][i-1]*=1-q[x].p;
	}
}
bool cmp(node x,node y){
	return x.l==y.l?x.r>y.r:x.l<y.l;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	build();
	For(i,1,Q) scanf("%d%d%lf",&q[i].l,&q[i].r,&q[i].p);
	q[++Q]=(node){1,n,0};
	sort(q+1,q+Q+1,cmp);
	//For(i,1,Q) cout<<q[i].l<<' '<<q[i].r<<endl;
	For(i,1,Q) Rep(j,i-1,1)
		if (q[j].l<=q[i].l&&q[i].r<=q[j].r){
			e[j].PB(i); break;
		}
	solve(1);
	double ans=0;
	For(i,0,Q) ans+=(bas[1]+i)*f[1][i];
	printf("%.10lf\n",ans);
}