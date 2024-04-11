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
int e[25][25],to[25],vis[25];
int n,f[1<<20|5];
char s[N],t[N];
void dfs(int x){
	vis[x]=1;
	For(i,0,19)
		if (!vis[i]&&e[x][i])
			dfs(i);
}
void solve(){
	memset(e,0,sizeof(e));
	memset(to,0,sizeof(to));
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	For(i,1,n)
		if (s[i]!=t[i]){
			s[i]-='a'; t[i]-='a';
			e[s[i]][t[i]]=e[t[i]][s[i]]=1;
			to[s[i]]|=1<<t[i];
		}
	int ans=40;
	For(i,0,19)
		if (!vis[i]){
			dfs(i); --ans;
		}
	//cout<<ans<<endl;
	memset(f,233,sizeof(f));
	f[0]=0;
	int mx=0;
	For(i,0,(1<<20)-1){
		mx=max(mx,f[i]);
		For(j,0,19) if (!(i&(1<<j)))
			if (!(to[j]&i)) f[i|(1<<j)]=max(f[i|(1<<j)],f[i]+1);
	}
	cout<<ans-mx<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}