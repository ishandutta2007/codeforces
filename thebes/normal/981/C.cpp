#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int n, i, x, y, deg[MN], wtf;
vector<pair<int,int>> wts;

int main(){
	for(scanf("%d",&n),i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		deg[x]++; deg[y]++;
	}
	for(i=1;i<=n;i++){
		if(deg[i]>2&&wtf){
			printf("No\n");
			return 0;
		}
		else if(deg[i]>2) wtf=i;
	}
	if(!wtf) wtf = 1;
	for(i=1;i<=n;i++){
		if(wtf!=i&&deg[i]==1)
			wts.push_back({wtf,i});
	}
	printf("Yes\n%d\n",wts.size());
	for(auto v : wts) printf("%d %d\n",v.first,v.second);
	return 0;
}