#include<bits/stdc++.h>
using namespace std;

const int maxn=2007;

int n,p[maxn],x[maxn],r[maxn];

vector<int> vec[maxn];

vector<int> dfs(int u,int p){
	vector<int> ret;
	ret.clear();
	ret.push_back(u);
	for (auto c:vec[u]){
		if (c==p) continue;
		vector<int> ans=dfs(c,u);
		for (auto c:ans){
			ret.push_back(c);
		}
	}
	if (x[u]>=ret.size()){
		puts("NO");
		exit(0);
	}
	for (int i=1;i<=x[u];++i){
		swap(ret[i-1],ret[i]);
	}
	return ret;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;++i) cin>>p[i]>>x[i], vec[p[i]].push_back(i), vec[i].push_back(p[i]);
	vector<int> ans=dfs(0,-1);
	for (int i=0;i<ans.size();++i){
		r[ans[i]]=i;
	}
	cout<<"YES\n";
	for (int i=1;i<=n;++i){
		cout<<r[i]<<" ";
	}
	return 0;
}