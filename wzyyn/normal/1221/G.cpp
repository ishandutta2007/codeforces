#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=42;
int n,m,e[N][N],vis[N];
void dfs(int x){
	vis[x]=1;
	For(i,1,n)
		if (e[x][i]&&!vis[i])
			dfs(i);
}
int Con(){
	For(i,1,n) vis[i]=0;
	int ans=0;
	For(i,1,n)
		if (!vis[i])
			dfs(i),++ans;
	return ans;
}
bool check(int x,int c){
	vis[x]=c;
	For(i,1,n) if (e[x][i])
		if (vis[i]==-1){
			if (!check(i,c^1)) return 0;
		}
		else if (vis[x]==vis[i])
			return 0;
	return 1;
}
ll Bipar(){
	For(i,1,n) vis[i]=-1;
	ll ans=1;
	For(i,1,n) if (vis[i]==-1)
		if (check(i,0)) ans*=2;
		else ans=0;
	return ans;
}
ll None(){
	ll ans=1;
	For(i,1,n){
		ans*=2;
		For(j,1,n)
			if (e[i][j]){
				ans/=2;
				break;
			}
	}
	return ans;
}
int S1,S2,S[1<<20];
int e00[N],e11[N],e01[N];
ll ans;
void dfs2(int x,int st,int ban){
	if (x>S2){
		//printf("%d %d\n",x,st);
		++S[st/2];
		return;
	}
	dfs2(x+1,st,ban);
	if (!(ban&(1<<x)))
		dfs2(x+1,st|(1<<x),ban|e11[x]);
}
void dfs1(int x,int st,int ban){
	if (x>S1){
		ans+=S[(1<<S2)-1-st/2];
		return;
	}
	dfs1(x+1,st,ban);
	if (!(ban&(1<<x)))
		dfs1(x+1,st|e01[x],ban|e00[x]);
}
ll Indep(){
	S1=(n+1)/2,S2=n-S1; ans=0;
	For(i,1,n) For(j,i+1,n) if (e[i][j])
		if (i<=S1&&j<=S1) e00[i]|=1<<j;
		else if (i>S1&&j>S1) e11[i-S1]|=1<<(j-S1);
		else e01[i]|=1<<(j-S1);
	dfs2(1,0,0);
	For(d,0,S2-1) For(i,0,(1<<S2)-1)
		if (i&(1<<d)) S[i]+=S[i^(1<<d)];
	dfs1(1,0,0);
	//printf("%lld\n",ans>>7);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	if (m==0) return puts("0"),0;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x][y]=e[y][x]=1;
	}
	ll ans=1ll<<n;
	//printf("%lld\n",ans);
	ans-=2ll*Indep();
	//printf("%lld\n",ans);
	ans-=1ll<<Con();
	//printf("%lld\n",ans);
	ans+=2*None();
	//printf("%lld\n",ans);
	ans+=Bipar();
	printf("%lld\n",ans);
}
/*
5 3
1 2
2 3
3 4
*/