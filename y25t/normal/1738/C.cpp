#include<bits/stdc++.h>
#define N 105

int T;

int n,a[N];

int f[N][N][2][2];
inline int dfs(int x,int y,int z,int w){
	if(!x&&!y)
		return z;
	if(~f[x][y][z][w])
		return f[x][y][z][w];
	f[x][y][z][w]=((x?dfs(x-1,y,z,w^1)==w:0)|(y?dfs(x,y-1,!w?z^1:z,w^1)==w:0))^w^1;
	return f[x][y][z][w];
}

int main(){
	memset(f,-1,sizeof(f));
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			(a[i]&1?y:x)++;
		}
		puts(dfs(x,y,0,0)==0?"Alice":"Bob");
	}
}