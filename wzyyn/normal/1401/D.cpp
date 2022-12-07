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
const int mo=1000000007;
const int N=100005;
int n,sz[N],m;
int q[N*50],qq[N*50];
ll b[N*50];
vector<int> e[N];
void dfs(int x,int fa){
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa){
			dfs(i,x);
			sz[x]+=sz[i];
			b[++*b]=1ll*sz[i]*(n-sz[i]); 
		}
}
void solve(){
	*b=0;
	scanf("%d",&n);
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	*q=0;
	scanf("%d",&m);
	For(i,1,m){
		int x;
		scanf("%d",&x);
		for (int j=2;j*j<=x;j++)
			for (;x%j==0;x/=j,q[++*q]=j);
		if (x!=1) q[++*q]=x;
	}
	sort(q+1,q+*q+1);
	if (*q<n){
		For(i,1,n-1) qq[i]=1;
		For(i,1,*q) qq[n-1-(*q-i)]=q[i];
	}
	else{
		For(i,1,n-1) qq[i]=1;
		For(i,1,n-1) qq[i]=q[i];
		For(i,n,*q) qq[n-1]=1ll*qq[n-1]*q[i]%mo; 
	}
	dfs(1,0);
	sort(b+1,b+n);
	int ans=0;
	For(i,1,n-1) ans=(ans+b[i]%mo*qq[i])%mo;//cout<<b[i]<<' '<<qq[i]<<endl;
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}