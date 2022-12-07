#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n;
int h[N];
vector<int> e[N];
long long ans;
int dfs(int x,int fa){
	int mx=0;
	for (auto i:e[x])
		if (i!=fa){
			int v=dfs(i,x);
			ans+=v; mx=max(mx,v);
		}
	ans-=mx;
	return max(mx,h[x]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int p=max_element(h+1,h+n+1)-h;
	int mx1=0,mx2=0;
	for (auto i:e[p]){
		int v=dfs(i,p);
		ans+=v;
		if (v>mx2) swap(mx2,v);
		if (v>mx1) swap(mx1,v);
	}
	cout<<ans-mx1-mx2+2*h[p]<<endl;
}