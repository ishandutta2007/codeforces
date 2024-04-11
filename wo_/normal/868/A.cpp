#include<cstdio>

using namespace std;

char pass[3];
char bark[110][3];
int N;

void input(){
	scanf("%s", pass);
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%s", bark[i]);
	}
}

bool solve(){
	for(int i = 0; i < N; ++i){
		if(bark[i][0] == pass[0] && bark[i][1] == pass[1]) return true;
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(bark[i][1] == pass[0] && bark[j][0] == pass[1]) return true;
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