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
const int N=100005;
vector<pii> e[N];
int vis[N],q[N];
int k[N],b[N];
int n,m,v1,v2,ans[N],c[N];
void dfs(int x){
	vis[x]=1;
	q[++*q]=x;
	for (auto i:e[x])
		if (!vis[i.fi]){
			k[i.fi]=-k[x];
			b[i.fi]=i.se-b[x];
			dfs(i.fi);
		}
		else if (k[i.fi]+k[x]==0){
			if (b[i.fi]+b[x]!=i.se)
				v2=-1;
		}
		else{
			int res=(i.se-b[i.fi]-b[x]);
			res/=k[i.fi]+k[x];
			if (!v2) v2=1,v1=res;
			else if (v1!=res) v2=-1;
		}
}
void solve(int x){
	v1=0; v2=0; *q=0;
	k[x]=1; b[x]=0;
	dfs(x); 
	if (v2==-1){
		puts("NO");
		exit(0);
	}
	//For(i,1,n)
	//	cout<<k[i]<<' '<<b[i]<<endl;
	if (v2==0){
		For(i,1,*q)
			c[i]=b[q[i]]*k[q[i]];
		sort(c+1,c+*q+1);
		v1=-c[(*q+1)/2];
	}
	//cout<<v1<<endl;
	For(i,1,*q)
		ans[q[i]]=k[q[i]]*v1+b[q[i]];
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[x].PB(pii(y,v*2));
		e[y].PB(pii(x,v*2));
	}
	For(i,1,n)
		if (!vis[i])
			solve(i);
	puts("YES");
	For(i,1,n){
		if (ans[i]<0)
			printf("-"),ans[i]*=-1;
		printf("%d.%d ",ans[i]/2,ans[i]%2*5);
	}
}