#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N],b[N];
bool was[N];
int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	map<int,int> mp;
	for(int i=1;i<=n;i++)mp[b[i]]=i;
	map<int,int> pos;
	for(int i=1;i<=n;i++)pos[mp[a[i]]]=i;
	vector<vector<int>> ans;
	for(int i=1;i<=n;i++){
		if(was[i])continue;
		vector<int> cur;
		int id=i;
		while(!was[id]){
			was[id]=true;
			cur.push_back(id);
			id=mp[a[id]];
		}
		sort(cur.begin(),cur.end());
		ans.push_back(cur);
	}
	printf("%i\n",ans.size());
	for(auto x:ans){
		printf("%i ",x.size());
		for(int i:x)printf("%i ",i);
		printf("\n");
	}
	return 0;
}