#include<cstdio>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;

typedef pair<int, int> P;

int C;

set<P> se; //<-cost, num>

int solve(){
	for(int i = 1; i < C; ++i){
		int taken = 0;
		int prv = C + 1;
		set<P> :: iterator it = se.lower_bound(P(-i, -1));
		if((it -> first) == -i){
			P p = P(-i, (it -> second) + 1);
			se.erase(it);
			se.insert(p);
		} else {
			P p = P(-i, 1);
			se.insert(p);
		}
		while(true){
			int rem = C - taken;
			int val = max(-rem, -prv + 1);
			set<P> :: iterator it = se.lower_bound(P(val, -1));
			if(it == se.end()) break;
			int c = -(it->first);
			int n = it->second;
			int x = rem / c;
			x = min(x, n);
			taken += c * x;
			prv = c;
		}
		if(taken != C) return i;
		it = se.lower_bound(P(-i, -1));
		if((it -> second) == 1){
			se.erase(it);
		} else {
			P p = P(-i, (it -> second) - 1);
			se.erase(it);
			se.insert(p);
		}
	}
	return -1;
}

int cnt[200200];

void input(){
	scanf("%d", &C);
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for(int i = 1; i <= C; ++i){
		if(cnt[i] > 0){
			se.insert(P(-i, cnt[i]));
		}
	}
}

int main(){
	input();
	int ans = solve();
	if(ans == -1) printf("Greed is good\n");
	else printf("%d\n", ans);
	return 0;
}