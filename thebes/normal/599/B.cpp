#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
vector<int> ans;
int idx[MN], cnt[MN], n, m, i, x, f1, f2;

int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
		scanf("%d",&x); cnt[x]++;
		idx[x] = i;
	}
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		if(cnt[x]>1) f1=1;
		else if(!cnt[x]) f2=1;
		ans.push_back(idx[x]);
	}
	if(f2) printf("Impossible\n");
	else if(f1) printf("Ambiguity\n");
	else{
		printf("Possible\n");
		for(auto v : ans) printf("%d ",v);
	}
	return 0;
}