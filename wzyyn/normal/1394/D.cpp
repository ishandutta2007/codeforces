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
const int N=200005;
int n,t[N],h[N],vis[N];
int in[N],ou[N];
vector<int> e[N];
ll f[N][2],q[N];
ll calc(int x){
	ll sum=0,res=-(1ll<<40); *q=0;
	for (auto i:e[x]) if (h[i]==h[x])
		q[++*q]=f[i][1]-f[i][0],sum+=f[i][0];
	sort(q+1,q+*q+1);
	Rep(i,*q,0){
		int IN=in[x]+*q-i,OU=ou[x]+i;
		res=max(res,sum+1ll*min(IN,OU)*t[x]);
		sum+=q[i];
	}
	//cout<<x<<' '<<res<<' '<<sum<<endl;
	return res;
}
void dfs(int x,int fa){
	vis[x]=1;
	for (auto i:e[x])
		if (i!=fa&&h[i]==h[x]) dfs(i,x);
	if (!fa) f[x][0]=calc(x);
	else{
		f[fa][0]=-(1ll<<40); f[fa][1]=0; f[x][0]=calc(x);
		f[fa][1]=-(1ll<<40); f[fa][0]=0; f[x][1]=calc(x);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&t[i]);
	For(i,1,n) scanf("%d",&h[i]);
	ll ans=0;
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
		if (h[x]!=h[y]){
			if (h[x]<h[y]) ++ou[y],++in[x];
			else ++ou[x],++in[y];
		}
		ans+=t[x]+t[y];
	}
	For(i,1,n)
		if (!vis[i])
			dfs(i,0),ans-=f[i][0];
	cout<<ans<<endl;
}