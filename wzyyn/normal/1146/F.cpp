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
const int N=200005;
vector<int> e[N];
int n,f[N][3],tmp[3];
void dfs(int x){
	if (e[x].size()==0){
		f[x][2]=1;
		return;
	}
	f[x][0]=1;
	for (auto i:e[x]){
		dfs(i);
		memset(tmp,0,sizeof(tmp));
		tmp[0]=(tmp[0]+1ll*f[x][0]*f[i][0])%mo;
		tmp[1]=(tmp[1]+1ll*f[x][0]*f[i][1])%mo;
		tmp[0]=(tmp[0]+1ll*f[x][0]*f[i][2])%mo;
		tmp[1]=(tmp[1]+1ll*f[x][0]*f[i][2])%mo;
		
		tmp[1]=(tmp[1]+1ll*f[x][1]*f[i][0])%mo;
		tmp[2]=(tmp[2]+1ll*f[x][1]*f[i][1])%mo;
		tmp[1]=(tmp[1]+1ll*f[x][1]*f[i][2])%mo;
		tmp[2]=(tmp[2]+1ll*f[x][1]*f[i][2])%mo;
		
		tmp[2]=(tmp[2]+1ll*f[x][2]*f[i][0])%mo;
		tmp[2]=(tmp[2]+1ll*f[x][2]*f[i][1])%mo;
		tmp[2]=(tmp[2]+1ll*f[x][2]*f[i][2])%mo;
		tmp[2]=(tmp[2]+1ll*f[x][2]*f[i][2])%mo;
		memcpy(f[x],tmp,sizeof(f[x]));
	}
}
/*
0+0->0
0+1->1
0+2->0,1
1+0->1
1+1->2
1+2->1,2
2+0->0,1
2+1->1,2
2+2->2,2
*/
int main(){
	scanf("%d",&n);
	For(i,2,n){
		int x;
		scanf("%d",&x);
		e[x].PB(i);
	}
	dfs(1);
	printf("%d\n",(f[1][0]+f[1][2])%mo);
}