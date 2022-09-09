#include <bits/stdc++.h>
using namespace std;
#define pb push_back
void Solve(){
	int n;
	scanf("%i",&n);
	vector<vector<int>> sets(n,vector<int>());
	vector<int> all;
	int m=0;
	for(int i=0;i<n;i++){
		int k;
		scanf("%i",&k);
		sets[i].resize(k);
		for(int j=0;j<k;j++){
			scanf("%i",&sets[i][j]);
			all.pb(sets[i][j]);
		}
		m+=k;
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=0;i<n;i++){
		for(int&j:sets[i]){
			j=lower_bound(all.begin(),all.end(),j)-all.begin();
		}
	}
	vector<vector<int>> has(all.size(),vector<int>());
	int S=sqrt(m);
	vector<int> mark(all.size(),0);
	for(int i=0;i<n;i++){
		if(sets[i].size()>S){
			for(int j:sets[i])mark[j]=1;
			for(int j=0;j<n;j++)if(j!=i){
				int cnt=0;
				for(int z:sets[j])cnt+=mark[z];
				if(cnt>=2){
					printf("%i %i\n",i+1,j+1);
					return;
				}
			}
			for(int j:sets[i])mark[j]=0;
		}else{
			for(int j:sets[i])has[j].pb(i);
		}
	}
	for(int e=0;e<all.size();e++){
		for(int i:has[e]){
			for(int j:sets[i])if(j!=e){
				if(mark[j]){
					printf("%i %i\n",mark[j],i+1);
					return;
				}
				mark[j]=i+1;
			}
		}
		for(int i:has[e]){
			for(int j:sets[i])if(j!=e){
				mark[j]=0;
			}
		}
	}
	printf("-1\n");
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		Solve();
	}
	return 0;
}