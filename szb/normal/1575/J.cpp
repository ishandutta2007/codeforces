#include<bits/stdc++.h>

using namespace std;

#define N 1200

int n,m,k,a[N][N];
set<pair<int,int> > f[N];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			scanf("%d",a[i]+j);
			if (a[i][j]!=2) f[j].insert(make_pair(i,a[i][j]));
		}
	}
	while (k--){
		int x=1,y; scanf("%d",&y);
		while (1){
			auto it=f[y].lower_bound(make_pair(x,0));
			if (it==f[y].end()){
				printf(k==0?"%d\n":"%d ",y);
				break;
			}
			int ny=y;
			if ((it->second)==3) --y;
			else ++y;
			x=it->first;
			f[ny].erase(it);
		}
	}
	
	return 0;
}