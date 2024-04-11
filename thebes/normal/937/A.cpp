#include <bits/stdc++.h>
using namespace std;

set<int> s;
int n, i, x;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d",&x);
		if(x) s.insert(x);
	}
	printf("%d\n",s.size());
	return 0;
}