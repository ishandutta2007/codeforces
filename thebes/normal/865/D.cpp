#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, i, x, ans; 
priority_queue<ll,vector<ll>,greater<ll>> s;

int main(){
	for(scanf("%I64d",&N),i=0;i<N;i++){
		scanf("%I64d",&x);
		s.push(x);
		ans += x-s.top(); s.pop();
		s.push(x);
	}
	printf("%I64d\n",ans);
	return 0;
}