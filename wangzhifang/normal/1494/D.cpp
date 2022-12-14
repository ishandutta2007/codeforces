#include<bits/stdc++.h>
using namespace std;
#define max_n 1000
int val[max_n+1],a[max_n+1][max_n+1];
int cnt;
vector<int> g[max_n+1];
void solve(int x,vector<int> v){
	if(v.size()==1){
		val[x]=a[x][x];
		return;
	}
	int mx=0;
	for(vector<int>::iterator it=v.begin(),ed=v.end(); it!=ed; ++it)
		for(vector<int>::iterator j=v.begin(); j!=ed; ++j)
			mx=max(mx,a[*it][*j]);
	val[x]=mx;
	while(v.size()){
		int u=v[0];
		vector<int> v1,v2;
		for(vector<int>::iterator it=v.begin(),ed=v.end(); it!=ed; ++it)
			if(a[u][*it]!=mx)
				v1.push_back(*it);
			else
				v2.push_back(*it);
		int vv=v1.size()==1?u:++cnt;
		g[x].push_back(vv);
		solve(vv,v1);
		v=v2;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%d",a[i]+j);
	vector<int> v;
	for(int i=1; i<=n; ++i)
		v.push_back(i);
	cnt=n;
	solve(++cnt,v);
	printf("%d\n",cnt);
	for(int i=1; i<=cnt; ++i)
		printf("%d ",val[i]);
	printf("\n%d\n",n+1);
	for(int i=1; i<=cnt; ++i)
		for(vector<int>::iterator it=g[i].begin(),ed=g[i].end(); it!=ed; ++it)
			printf("%d %d\n",*it,i);
	return 0;
}