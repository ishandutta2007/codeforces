#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>

const int N = 2e5 + 7;

int n;
multiset <LL> S;
priority_queue <PLL> Q;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		LL a, b, t;
		scanf("%lld %lld %lld", &a, &b, &t);
		
		Q.push({-a, t});
		Q.push({-(b - t + 1), -t});
	}
	
	LL ans = 0, last = 0;
	while(!Q.empty()){
		LL x = -Q.top().st;
		LL t = Q.top().nd;
		Q.pop();
		
		if(last < x){
			if(S.size() > 0){
				LL best = *S.begin();
				LL diff = x - last;
				LL df = (diff + best - 1) / best;

				ans += df;
				last += df * best;
			}
			else
				last = x;
		}
		
		if(t < 0)
			S.erase(S.find(-t));
		else{
			last = min(last, x + t);
			S.insert(t);
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}