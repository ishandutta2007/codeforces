#include <bits/stdc++.h>
using namespace std;

set<int> wtf;
int n, i, x;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d",&x);
		if(x) wtf.insert(x);
	}
	printf("%d\n",wtf.size());
	return 0;
}