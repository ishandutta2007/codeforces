#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

char ch[110][110];
int lns[110];
int N;

bool to_del[110];

int del_l;
char pat[110];

void gen_pat(){
	for(int i = 0; i < del_l; ++i) pat[i] = 'A';
	for(int i = 0; i < N; ++i){
		if(to_del[i]){
			for(int j = 0; j < del_l; ++j){
				if(pat[j] == 'A') pat[j] = ch[i][j];
				else if(pat[j] != ch[i][j]) pat[j] = '?';
			}
		}
	}
}

bool is_valid(){
	for(int i = 0; i < N; ++i){
		if(!to_del[i]){
			bool ma = true;
			if(lns[i] != del_l) continue;
			for(int j = 0; j < del_l; ++j){
				if(pat[j] == '?') continue;
				if(pat[j] == ch[i][j]) continue;
				ma = false;
			}
			if(ma) return false;
		}
	}
	return true;
}

void solve(){
	for(int i = 0; i < N; ++i) lns[i] = strlen(ch[i]);
	del_l = -1;
	for(int i = 0; i < N; ++i){
		if(to_del[i]){
			if(del_l != -1 && del_l != lns[i]){
				printf("No\n");
				exit(0);
			}
			del_l = lns[i];
		}
	}
	gen_pat();
	bool flg = is_valid();
	if(!flg){
		printf("No\n");
	}else{
		printf("Yes\n");
		pat[del_l] = '\0';
		printf("%s\n", pat);
	}
}

void input(){
	int M;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%s", ch[i]);
	}
	for(int i = 0; i < N; ++i) to_del[i] = false;
	for(int i = 0; i < M; ++i){
		int id;
		scanf("%d", &id);
		id--;
		to_del[id] = true;
	}
}

int main(){
	input();
	solve();
	return 0;
}