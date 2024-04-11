#include <bits/stdc++.h>
using namespace std;
const int N=500050;
const int L=22;
int sz[N][L];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1,l,r;i<=n;i++)scanf("%i %i",&l,&r),sz[l][0]=max(sz[l][0],r-l);
	for(int i=1;i<N;i++)sz[i][0]=max(sz[i][0],sz[i-1][0]-1);
	for(int j=1;j<L;j++)for(int i=0;i<N;i++)sz[i][j]=sz[i][j-1]+sz[i+sz[i][j-1]][j-1];
	for(int i=1,l,r;i<=m;i++){
		scanf("%i %i",&l,&r);
		int need=r-l,ans=1;
		for(int j=L-1;~j;j--)if(need>sz[l][j]){
			need-=sz[l][j];
			l+=sz[l][j];
			ans+=1<<j;
		}
		if(ans==1<<L)printf("-1\n");
		else printf("%i\n",ans);
	}
	return 0;
}