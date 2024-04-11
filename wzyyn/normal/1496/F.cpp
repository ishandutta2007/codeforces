#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define PB push_back
using namespace std;

const int N=405;
const int mo=998244353;
int n,m;
int f[N][N];
int re[N][N];
vector<int> e[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,n)
		f[i][j]=(i==j?0:1<<20);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
		f[x][y]=f[y][x]=1;
	}
	For(k,1,n) For(i,1,n) For(j,1,n)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	For(i,1,n) For(j,i,n){
		int w=1,ww=0;
		For(k,1,n)
			if (f[i][k]+f[j][k]==f[i][j]) ++ww;
			else{
				int s=0;
				for (auto l:e[k])
					if (f[i][l]+f[j][l]+2==f[i][k]+f[j][k]) ++s;
				w=1ll*w*s%mo;
			}
		if (ww!=f[i][j]+1) w=0;
		re[i][j]=re[j][i]=w;
	}
	For(i,1,n) For(j,1,n)
		printf("%d%c",re[i][j],j==n?'\n':' ');
}
/*
d[i][j]=d[i][k]+d[k][j]
*/