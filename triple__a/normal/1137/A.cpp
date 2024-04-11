#include<bits/stdc++.h>
using namespace std;

int n,m,a[1007][1007],p[1007][1007][2],np[1007][2],ans[1007][1007];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
		}
	}
	vector<int> vec;
	for (int i=1;i<=n;++i){
		vec.clear();
		for (int j=1;j<=m;++j){
			vec.push_back(a[i][j]);
		}
		sort(vec.begin(),vec.end());
		auto new_end=unique(vec.begin(),vec.end());
		vec.erase(new_end,vec.end());
		np[i][0]=vec.size();
		for (int j=1;j<=m;++j){
			p[i][j][0]=lower_bound(vec.begin(),vec.end(),a[i][j])-vec.begin();
		}
	}
	for (int j=1;j<=m;++j){
		vec.clear();
		for (int i=1;i<=n;++i){
			vec.push_back(a[i][j]);
		}
		sort(vec.begin(),vec.end());
		auto new_end=unique(vec.begin(),vec.end());
		vec.erase(new_end,vec.end());
		np[j][1]=vec.size();
		for (int i=1;i<=n;++i){
			p[i][j][1]=lower_bound(vec.begin(),vec.end(),a[i][j])-vec.begin();
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			int l=min(0,p[i][j][0]-p[i][j][1]),r=max(np[i][0],np[j][1]+p[i][j][0]-p[i][j][1]);
			ans[i][j]=r-l;
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			printf("%d\n",ans[i][j]);
		}
	}
	return 0;
}