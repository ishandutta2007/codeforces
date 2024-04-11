#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[200100],res;
vector<int>v[200100],occ[200100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)for(int j=0,x;j<m;j++)scanf("%d",&x),v[j].push_back(x);
	for(int i=0;i<m;i++){
		int ans=n;
		for(int j=0;j<n;j++)occ[v[i][j]].push_back(j);
		for(int j=0,x=i+1;j<n;j++,x+=m)for(int k=0;k<occ[x].size();k++)cnt[(j-occ[x][k]+n)%n]++;
		for(int j=0;j<n;j++)ans=min(ans,(n-cnt[j])+(n-j)%n);
		res+=ans;
		for(int j=0,x=i+1;j<n;j++,x+=m)for(int k=0;k<occ[x].size();k++)cnt[(j-occ[x][k]+n)%n]--;
		for(int j=0;j<n;j++)occ[v[i][j]].pop_back();
	}
	printf("%d\n",res);
	return 0;
}