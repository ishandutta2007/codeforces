#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
vector<int> G[N];
int d[N],n,x,y,a[N],ans1,ans2,flag;
void dfs(int x,int y){
	for (int i:G[x])if (i!=y){
		a[i]=a[x]+1;
		dfs(i,x);
	}
	if (d[x]==1){
		if (a[x]&1)flag|=1;
		else flag|=2;
	}
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		d[x]++;d[y]++;
	}
	ans1=1,ans2=n-1;
	for (int i=1;i<=n;i++){
		int cnt1=0;
		for (int j:G[i])
			if (d[j]==1)cnt1++;
		if (cnt1>1)ans2-=cnt1-1;
	}
	dfs(1,0);
	if (flag==3)ans1=3;
	printf("%lld %lld\n",ans1,ans2);
}