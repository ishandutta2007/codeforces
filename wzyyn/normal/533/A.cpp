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
const int N=500005;
int n,m,h[N],b[N],q[N];
vector<int> e[N];
pii a[N];
bool cmp(pii x,pii y){
	if (h[x.fi]!=h[y.fi]) return h[x.fi]>h[y.fi];
	if (x.fi!=y.fi) return x.fi<y.fi;
	return h[x.se]>h[y.se];
}
void dfs(int x,int fa,int v1,int v2){
	if (h[x]<h[v1]) v2=v1,v1=x;
	else if (h[x]<h[v2]) v2=x;
	a[x]=pii(v1,v2);
	for (auto i:e[x])
		if (i!=fa) dfs(i,x,v1,v2);
}
void work(int l,int r,int k){
	int ans=0;
	For(i,1,r-l+1){
		int t=0;
		if (i<=*q) t=q[i];
		else if (k+i-*q-1<=m) t=b[k+i-*q-1];
		ans=max(ans,t-h[a[l+i-1].fi]);
		if (t>h[a[l+i-1].se]) return; 
	}
	printf("%d\n",ans);
	exit(0);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&h[i]);
	For(i,2,n){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	h[0]=1<<30;
	dfs(1,0,0,0);
	scanf("%d",&m);
	For(i,1,m) scanf("%d",&b[i]);
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+m+1,greater<int>());
	//For(i,1,n) cout<<a[i].fi<<' '<<a[i].se<<endl;
	int le=0;
	For(i,1,m) if (b[i]>h[a[i].fi]) le=i;
	for (int i=1,j=1,k=1;i<=n;i=j+1){
		for (j=i;j<n&&a[j+1].fi==a[i].fi;++j);
		if (*q<=j-i+1&&j>=le) work(i,j,k);
		For(t,i,j){
			for (;k<=m&&b[k]>h[a[t].fi];++k) q[++*q]=b[k];
			++k;
		}
	}
	puts("-1");
}