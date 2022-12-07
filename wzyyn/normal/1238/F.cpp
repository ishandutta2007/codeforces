#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 fdhjksa
using namespace std;
const int N=300005;
struct edge{
	int to,next;
}e[N*2];
int head[N],n,tot;
int ans,f[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	int s=0,mx1=0,mx2=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			++s;
			dfs(e[i].to,x);
			if (f[e[i].to]>mx1)
				mx2=mx1,mx1=f[e[i].to];
			else if (f[e[i].to]>mx2)
				mx2=f[e[i].to];
		}
	if (!s) ans=max(ans,f[x]=1);
	else if (s==1) ans=max(ans,(f[x]=mx1+1)+(fa!=0));
	else{
		ans=max(ans,mx1+mx2+s-1+(fa!=0));
		f[x]=mx1+s;
	}
}
void solve(){
	scanf("%d",&n);
	ans=tot=0;
	For(i,1,n) head[i]=0;
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	printf("%d\n",ans);
}
int main(){	
	int T;
	scanf("%d",&T);
	while (T--) solve();
}