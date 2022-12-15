#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int N, i, x;

int main(){
	for(scanf("%d",&N);i<N;i++){
		scanf("%d",&x);
		while(s.size()&&s.top()>=i-x) s.pop();
		s.push(i);
	}
	printf("%d\n",(signed)s.size());
	return 0;
}