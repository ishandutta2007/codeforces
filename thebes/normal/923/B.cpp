#include <bits/stdc++.h>
using namespace std;

long long ans, _;
int N, i, arr[100005], x;
multiset<long long> s;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=N;i++){
		scanf("%d",&x);
		s.insert(_+arr[i]);
		ans = 1LL*s.size()*x;
		_ += x;
		while(s.size()&&*s.begin()<=_){
			ans -= (_-*s.begin());
			s.erase(s.begin());
		}
		printf("%lld ",ans);
	}
	return 0;
}