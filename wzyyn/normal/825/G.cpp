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
const int N=1000005;
int n,Q;
vector<int> e[N];
int ans=1<<30;
int fa[N],f[N];
void dfs(int x){
	f[x]=min(f[x],x);
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			f[i]=f[x];
			dfs(i);
		}
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	int fir=-1;
	int las=0;
	memset(f,30,sizeof(f));
	For(i,1,Q){
		int tp,x;
		scanf("%d%d",&tp,&x);
		x=(x+las)%n+1;
		if (tp==1){
			if (fir==-1)	
				fir=0,dfs(x);
			ans=min(ans,f[x]);
		}
		else
			printf("%d\n",las=min(ans,f[x]));
	}
}