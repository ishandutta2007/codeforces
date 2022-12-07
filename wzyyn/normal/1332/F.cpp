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
const int mo=998244353;
const int N=300005;
int f[N][3],n;
vector<int> e[N];
void dfs(int x,int fa){
	f[x][0]=f[x][1]=1;
	for (auto i:e[x]) if (i!=fa){
		dfs(i,x);
		static int tmp[3];
		tmp[0]=(2ll*f[x][0]*f[i][0]+1ll*f[x][0]*f[i][1]+2ll*f[x][0]*f[i][2])%mo;
		tmp[1]=(1ll*f[x][1]*f[i][0]+1ll*f[x][1]*f[i][2])%mo;
		tmp[2]=(2ll*f[x][2]*f[i][0]+1ll*f[x][1]*f[i][0]+1ll*f[x][2]*f[i][2])%mo;
		f[x][0]=tmp[0];
		f[x][1]=tmp[1];
		f[x][2]=tmp[2];
	}
}
int main(){
	scanf("%d",&n); 
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1,0);
	printf("%d\n",(f[1][0]+f[1][2]+1ll*mo-1)%mo);
}
/*
 
*/