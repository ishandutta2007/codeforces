#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m,T,flg;
int a[maxn*maxn],id[maxn*maxn],now[maxn],vis[maxn*maxn],ans[maxn][maxn];
inline int cmp(int x,int y){
	return a[x]<a[y];
}
inline int getpos(int x,int y){
	return (x-1)*m+y;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[getpos(i,j)]);
		for(int i=1;i<=n*m;i++)
			vis[i]=0,id[i]=i;
		for(int i=1;i<=n;i++)
			now[i]=1;
		sort(id+1,id+1+n*m,cmp);
		for(int i=1;i<=m;i++)
			vis[id[i]]=1;
		for(int i=1;i<=m;i++){
			int k=id[i],x=(k-1)/m+1,y=(k-1)%m+1;
			for(int j=1;j<=n;j++){
				if(j==x){
					ans[j][i]=a[k];
					continue;
				}
				while(now[j]<=m&&vis[getpos(j,now[j])])
					now[j]++;
				vis[getpos(j,now[j])]=1;
				ans[j][i]=a[getpos(j,now[j])];
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				printf("%d%c",ans[i][j],j==m? '\n':' ');
	}
	return 0;
}