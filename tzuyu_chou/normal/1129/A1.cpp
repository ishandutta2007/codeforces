#include<iostream>
#include<queue>
using namespace std;
int n,m;
vector<int>v[5001];
int mini[5001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int p,q;cin >> p >> q;v[p].push_back(q);
	}
	for(int i=1; i<=n ;i++){
		mini[i]=1e9;
		for(auto cur:v[i]) mini[i]=min(mini[i],(cur-i+n)%n);
	}
	for(int i=1; i<=n ;i++){
		int ans=0;
		for(int j=1; j<=n ;j++){
			if(v[j].empty()) continue;
			ans=max(ans,(j-i+n)%n+((int)v[j].size()-1)*n+mini[j]);
		}
		cout << ans << ' ';
	}
	cout << endl;
}