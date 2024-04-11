#include<cstdio>

using namespace std;

bool exi[1 << 4];
int K;

void input(){
	int N;
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; ++i){
		int a = 0;
		for(int j = 0; j < K; ++j){
			int x;
			scanf("%d", &x);
			if(x == 1) a |= (1 << j);
		}
		exi[a] = true;
	}
}

bool solve(){
	for(int i = 0; i < (1 << K); ++i){
		for(int j = 0; j < (1 << K); ++j){
			if((i & j) != 0) continue;
			if(!exi[i]) continue;
			if(!exi[j]) continue;
			return true;
		}
	}
	return false;
}

int main(){
	input();
	bool ans = solve();
	if(ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}