#include <bits/stdc++.h>
using namespace std;

stack<int> s;
bitset<200005> seen;
int N, i, x, b;

int main(){
	for(scanf("%d",&N),i=0;i<N;i++){
		scanf("%d",&x); s.push(x);
	}
	while(!s.empty()){
		x = s.top(); s.pop();
		if(seen[x]) continue;
		seen[x] = 1; b = x;
	}
	printf("%d\n",b);
	return 0;
}