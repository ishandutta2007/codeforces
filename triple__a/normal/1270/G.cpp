#include<bits/stdc++.h>

using namespace std;

const int maxn=1000007;
int a[maxn],n,t;
bool vis[maxn];
vector<int> vec;
void bfs(int u){
	vec.clear();
	while (!vis[u]){
		vis[u]=1;
		u=u-a[u];
	}
	int t=u-a[u];
	vec.push_back(u);
	while (t!=u){
		vec.push_back(t);
		t=t-a[t];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;++i) cin>>a[i], vis[i]=0;
		bfs(1);
		cout<<vec.size()<<"\n";
		for (auto c:vec){
			cout<<c<<" ";
		}
		cout<<"\n";
	}
	return 0;
}