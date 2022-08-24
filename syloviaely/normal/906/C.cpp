#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
int now[22];
int ans,way,n,m;
void dfs(int k1,int k2,int k3){
	if (k1>=n){
		for (int i=0;i<n;i++) if (now[i]!=(1<<n)-1) return;
		if (k2<ans){
			ans=k2; way=k3;
		}
		return;
	}
	dfs(k1+1,k2,k3);
	int A[22]; memcpy(A,now,sizeof now);
	for (int i=0;i<n;i++)
		if (now[k1]&(1<<i)) now[i]|=now[k1];
	dfs(k1+1,k2+1,k3|(1<<k1));
	memcpy(now,A,sizeof now);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); 
		now[k1-1]|=(1<<k2-1);
		now[k2-1]|=(1<<k1-1);
	}
	for (int i=0;i<n;i++) now[i]|=(1<<i);
	ans=n+10; dfs(0,0,0);
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) if (way&(1<<i-1)) printf("%d ",i);
}