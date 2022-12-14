#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int, int> P;

int as[110], ds[110];

P standings[110];
int N;

vector<P> negs, poss;

int unfr(int id){
	int d = ds[id];
	int c = -1;
	for(int i = 0; i < N; ++i){
		if(standings[i].second == -id){
			c = i;
			break;
		}
	}
	standings[c].first += d;
	sort(standings, standings + N);
	int c2 = -1;
	for(int i = 0; i < N; ++i){
		if(standings[i].second == -id){
			c2 = i;
			break;
		}
	}
	return c2 - c < 0 ? c - c2 : c2 - c;
}

int solve(){
	for(int i = 0; i < N; ++i){
		standings[i] = P(as[i], -i);
		if(ds[i] < 0) negs.push_back(P(as[i], -i));
		else poss.push_back(P(as[i], -i));
	}
	sort(standings, standings + N);
	sort(negs.begin(), negs.end());
	reverse(negs.begin(), negs.end());
	sort(poss.begin(), poss.end());
	int ans = 0;
	for(int i = 0; i < negs.size(); ++i){
		int val = unfr(-negs[i].second);
		ans += val;
	}
	for(int i = 0; i < poss.size(); ++i){
		int val = unfr(-poss[i].second);
		ans += val;
	}
	return ans;
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d%d", as + i, ds + i);
	}
}

int main(){
	input();
	int ans = solve();
	printf("%d\n", ans);
	return 0;
}