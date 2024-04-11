#include <bits/stdc++.h>
using namespace std;

set<int> s;
vector<int> id;
int n, k, i, x;

int main(){
	for(scanf("%d%d",&n,&k),i=1;i<=n;i++){
		scanf("%d",&x);
		if(!s.count(x)){
			s.insert(x);
			id.push_back(i);
		}
	}
	if(id.size()<k) printf("NO\n");
	else{
		printf("YES\n");
		for(i=0;i<k;i++) printf("%d ",id[i]);
	}
	return 0;
}