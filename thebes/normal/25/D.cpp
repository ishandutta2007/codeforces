#include <bits/stdc++.h>
using namespace std;

const int MN = 1004;
int ds[MN], n, i, j, x, y;
vector<pair<int,int>> a, b;

int ld(int x){return ds[x]=(x==ds[x])?x:ld(ds[x]);}

int main(){
	for(i=0;i<MN;i++) ds[i]=i;
	for(scanf("%d",&n),i=0;i<n-1;i++){
		scanf("%d%d",&x,&y);
		if(ld(x)!=ld(y)) ds[ld(x)]=ld(y);
		else a.push_back({x,y});
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(ld(i)!=ld(j)){
				b.push_back({i,j});
				ds[ld(i)]=ld(j);
			}
		}
	}
	printf("%d\n",a.size());
	for(i=0;i<a.size();i++)
		printf("%d %d %d %d\n",a[i].first,a[i].second,b[i].first,b[i].second);
	return 0;
}