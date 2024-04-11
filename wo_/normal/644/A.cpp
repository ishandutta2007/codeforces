#include<cstdio>
#include<cstdlib>

using namespace std;

int N, R, C;

int ans[110][110];

void putOdd(){
	int id = 1;
	for(int i = 0; i < R; ++i){
		int j = (i % 2 == 0) ? 0 : 1;
		for(; j < C; j += 2){
			ans[i][j] = id;
			id += 2;
			if(id > N) return;
		}
	}
	if(id <= N){
		printf("-1\n");
		exit(0);
	}
}

void putEven(){
	if(N == 1) return;
	int id = 2;
	for(int i = 0; i < R; ++i){
		int j = (i % 2 == 0) ? 1 : 0;
		for(; j < C; j += 2){
			ans[i][j] = id;
			id += 2;
			if(id > N) return;
		}
	}
	if(id <= N){
		printf("-1\n");
		exit(0);
	}
}

void input(){
	scanf("%d%d%d", &N, &R, &C);
}

int main(){
	input();
	putOdd();
	putEven();
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			printf("%d%c", ans[i][j], j == C - 1 ? '\n': ' ');
		}
	}
	return 0;
}