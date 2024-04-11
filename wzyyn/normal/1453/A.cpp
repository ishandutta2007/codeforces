#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;

int vis[105];
void solve(){
	int n,m,x,ans=0;
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&x),vis[x]=1;
	For(i,1,m) scanf("%d",&x),ans+=vis[x];
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}