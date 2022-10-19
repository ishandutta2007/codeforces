#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[100001];
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(g[i].size()==2){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}