#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=5005;
const int mo=998244353;
vector<int> e[N];
int f[N][N],sz[N],n,k;
int s1[N],s2[N],tmp[N];
void merge(int x,int y){
	Rep(i,sz[y]+1,1)
		f[y][i]=f[y][i-1];
	f[y][0]=0;
	For(i,1,sz[y]+1)
		f[y][0]=(f[y][0]+f[y][i])%mo;
	sz[y]=min(sz[y]+1,k);
	
	s1[0]=f[x][0]; s2[0]=f[y][0];
	For(i,1,sz[x]) s1[i]=(s1[i-1]+f[x][i])%mo;
	For(i,1,sz[y]) s2[i]=(s2[i-1]+f[y][i])%mo;
	For(i,0,sz[x]){
		int r=min(sz[y],min(k-i,i));
		tmp[i]=(tmp[i]+1ll*f[x][i]*s2[r])%mo;
	}
	For(i,0,sz[y]){
		int r=min(sz[x],min(k-i,i-1));
		if (r>=0) tmp[i]=(tmp[i]+1ll*f[y][i]*s1[r])%mo;
	}
	sz[x]=max(sz[x],sz[y]);
	For(i,0,sz[x]) f[x][i]=tmp[i],tmp[i]=0;///cout<<x<<' '<<y<<' '<<i<<' '<<tmp[i]<<endl;
}
void dfs(int x,int fa){
	sz[x]=0; f[x][0]=1;
	for (auto i:e[x]) if (i!=fa)
		dfs(i,x),merge(x,i);
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x); 
	}
	dfs(1,0);
	int ans=0;
	For(i,0,k) ans=(ans+f[1][i])%mo;
	cout<<ans<<endl;
}