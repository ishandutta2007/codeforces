#include <bits/stdc++.h>
using namespace std;

int mn=1<<30, ans=1<<30, N, i, x;
vector<int> v;

int main(){
	for(scanf("%d",&N),i=0;i<N;i++){
		scanf("%d",&x);
		if(x == mn){
			v.push_back(i);
		}
		else if(x < mn){
			mn = x;
			v.clear(); v.push_back(i);
		}
	}
	for(i=0;i<v.size()-1;i++){
		ans = min(ans,v[i+1]-v[i]);
	}
	printf("%d\n",ans);
	return 0;
}