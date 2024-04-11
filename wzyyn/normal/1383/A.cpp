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
int e[25][25];
int vis[25],n;
char s[N],t[N];
void dfs(int x){
	vis[x]=1;
	For(i,1,20)
		if (e[x][i]&&!vis[i])
			dfs(i);
}
void solve(){
	memset(e,0,sizeof(e));
	memset(vis,0,sizeof(vis));
	scanf("%d%s%s",&n,s+1,t+1);
	For(i,1,n)
		if (s[i]!=t[i]){
			if (s[i]>t[i]) return puts("-1"),void(0);
			e[s[i]-'a'][t[i]-'a']=1;
			e[t[i]-'a'][s[i]-'a']=1;
		}
	int ans=20;
	For(i,0,19) if (!vis[i])
		ans--,dfs(i);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}