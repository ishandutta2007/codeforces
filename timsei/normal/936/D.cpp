%:pragma GCC optimize(3)
#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 4e6 + 5;

map <int , int> Map , C , ban[2];
map <int , int> ::iterator it;

int dp[N][2] , tot , m1 , m2 , n , m , t , x , pos[N];
bool Ban[N][2] , pre[N][2];

typedef pair <int , int> Pii;

vector <Pii> Shot;
vector <int> turn;

void init(void) {
	scanf("%d%d%d%d" , &n , &m1 , &m2 , &t);
	for(int i = 1;i <= m1;++ i) {
		scanf("%d" , &x); ++ Map[x]; ++ Map[x + 1]; ban[0][x] = 1;
	}
	for(int i = 1;i <= m2;++ i) {
		scanf("%d" , &x); ++ Map[x]; ++ Map[x + 1];ban[1][x] = 1;
	}
	Map[0] = 1; Map[n + 1] = 1;
	for(it = Map.begin();it != Map.end();++ it) {
		pos[++ tot] = it -> first; C[it -> first] = tot;
	}
	for(it = ban[0].begin(); it != ban[0].end();++ it) Ban[C[it -> first]][0] = 1;
	for(it = ban[1].begin(); it != ban[1].end();++ it) Ban[C[it -> first]][1] = 1;
	memset(dp , -1 , sizeof(dp)); ban[0].clear(); ban[1].clear(); C.clear(); Map.clear();
	dp[1][0] = 0;
	pre[1][0] = 0;
}

void DP(void) {
	for(int i = 1;i <= tot;++ i) {
		if(dp[i][0] == dp[i][1] && dp[i][0] == -1) {
			puts("No"); exit(0);
		}
		
		if(min(dp[i][1] , t) > dp[i][0] && !Ban[i][0]) {
			dp[i][0] = min(dp[i][1] , t);
			pre[i][0] = 1;
		}
		
		if(min(dp[i][0] , t) > dp[i][1] && !Ban[i][1]) {
			dp[i][1] = min(dp[i][0] , t);
			pre[i][1] = 1;
		}
		
		for(int j = 0;j <= 1;++ j) {
			if(dp[i][j] == -1) continue;
			if(Ban[i + 1][j]) {
				if(dp[i][j] + (pos[i + 1] - pos[i]) - 1 >= t)
					dp[i + 1][j] = dp[i][j] - t + (pos[i + 1] - pos[i]) , pre[i + 1][j] =0;
				else dp[i + 1][j] = -1;
			}
			else dp[i + 1][j] = dp[i][j] + (pos[i + 1] - pos[i]) ,
			pre[i + 1][j] = 0;
		}
	}
}

vector < Pii > fire;

void print(int x) {
	puts("Yes");
	int A = tot , B = x;
	while(A != 1 || B != 0) {
		if(pre[A][B] == 1) {
			B ^= 1; turn.push_back(A);
		}
		else {
			if(Ban[A][B]) {
				fire.push_back(make_pair(A , B));
			}
			-- A;
		}
	}
	sort(turn.begin() , turn.end());
	cout << turn.size() << endl;
	for(int i = 0;i < (int) turn.size();++ i) printf("%d " , pos[turn[i]]);
	puts("");
	printf("%d\n" , fire.size());
//	fire.push_back(make_pair(-1 , -1));
	sort(fire.begin() , fire.end());
	for(int i = 0;i < (int)turn.size();++ i) turn[i] = pos[turn[i]];
	turn.push_back(0);
	sort(turn.begin() , turn.end());
	int lastfu = 0;
	for(int i = 0;i < (int) fire.size();++ i) {
		int A = fire[i].first , B = fire[i].second;
		if(i == 0) {
			int now = *(--(lower_bound(turn.begin() , turn.end() , pos[A])));
			printf("%d %d\n" , lastfu = max(now , t) , B + 1);
		}
		else {
			int now = *(--(lower_bound(turn.begin() , turn.end() , pos[A])));
			printf("%d %d\n" , lastfu = max(lastfu + t , now) , B + 1);
		}
	}
	exit(0);
}

main(void) {
	init();
	DP();
	if(dp[tot][0] != -1)
	print(0);
	else if(dp[tot][0] != -1)
	print(1);
	puts("No");
}