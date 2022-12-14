#include<cstdio>
#include<vector>

using namespace std;

int T;

vector<int> cand_min, cand_max;

int N;

char ask(int i, int j){
	printf("? %d %d\n", i + 1, j + 1);
	fflush(stdout);
	char ch[2];
	scanf("%s", ch);
	return ch[0];
}

void solve(){
	cand_min.clear();
	cand_max.clear();
	for(int i = 0; i * 2 + 1 < N; ++i){
		char ch = ask(i * 2, i * 2 + 1);
		if(ch == '<' || ch == '='){
			cand_min.push_back(i * 2);
			cand_max.push_back(i * 2 + 1);
		}else{
			cand_min.push_back(i * 2 + 1);
			cand_max.push_back(i * 2);
		}
	}
	if(N % 2 == 1){
		cand_min.push_back(N - 1);
		cand_max.push_back(N - 1);
	}
	int mi = cand_min[0];
	for(int i = 1; i < cand_min.size(); ++i){
		char ch = ask(mi, cand_min[i]);
		if(ch == '>') mi = cand_min[i];
	}
	int ma = cand_max[0];
	for(int i = 1; i < cand_max.size(); ++i){
		char ch = ask(ma, cand_max[i]);
		if(ch == '<') ma = cand_max[i];
	}
	printf("! %d %d\n", mi + 1, ma + 1);
	fflush(stdout);
}

int main(){
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		scanf("%d", &N);
		solve();
	}
	return 0;
}