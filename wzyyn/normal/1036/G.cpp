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
vector<int> e[N];
int n,m,fl[N],vis[N],ee[25];
int cnt[1<<20],S[25],T[25];
void dfs(int x) {
	vis[x]=1;
	for (auto i:e[x])
		if (!vis[i]) dfs(i);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		fl[x]|=2; fl[y]|=1;
		e[x].PB(y);
	}
	For(i,1,n){
		if (!(fl[i]&1)) S[++*S]=i;
		if (!(fl[i]&2)) T[++*T]=i;
	}
	For(i,1,*S){
		memset(vis,0,sizeof(vis));
		dfs(S[i]);
		For(j,1,*T)
			if (vis[T[j]])
				ee[i-1]|=1<<(j-1);
		//cout<<ee[i-1]<<endl;
	}
	For(i,0,(1<<20)-1)
		cnt[i]=cnt[i/2]+(i&1);
	For(i,1,(1<<*S)-2){
		int v=0;
		For(j,0,*S-1)
			if (i&(1<<j)) v|=ee[j];
		if (cnt[v]==cnt[i])
			return puts("NO"),0;
	}
	puts("YES");
}