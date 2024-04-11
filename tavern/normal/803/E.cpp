//orz dxm
#include<bits/stdc++.h>

using namespace std;

#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int maxn = 1e3 + 5;

inline int _(int x){return x + maxn;}

int n, m;
char s[maxn];
char ans[maxn];
char f[maxn][(maxn << 1) + 5];
bool dp[maxn][(maxn << 1) + 5];

int main(){
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	dp[0][_(0)] = 1;
	FOR(i, 0, n) REP(j, -m, m) if(dp[i][_(j)]){
		//printf("i = %d j = %d\n", i, j);
		int k = j;
		if(s[i] == 'W' || s[i] == '?'){
			k = j + 1;
			if(abs(k) < m || i == n - 1){
				dp[i + 1][_(k)] = true;
				f[i + 1][_(k)] = 'W';
			}
		}
		if(s[i] == 'L' || s[i] == '?'){
			k = j - 1;
			if(abs(k) < m || i == n - 1){
				dp[i + 1][_(k)] = true;
				f[i + 1][_(k)] = 'L';
			}
		}
		if(s[i] == 'D' || s[i] == '?'){
			k = j;
			if(abs(k) < m || i == n - 1){
				dp[i + 1][_(k)] = true;
				f[i + 1][_(k)] = 'D';
			}
		}
	}
	if(dp[n][_(m)]){
		for(int i = n, j = m; i; --i){
			ans[i - 1] = f[i][_(j)];
			if(f[i][_(j)] == 'W') --j;
			else if(f[i][_(j)] == 'L') ++j;
		}
		printf("%s\n", ans);
		return 0;
	}
	if(dp[n][_(-m)]){
		for(int i = n, j = -m; i; --i){
			ans[i - 1] = f[i][_(j)];
			if(f[i][_(j)] == 'W') --j;
			else if(f[i][_(j)] == 'L') ++j;
		}
		printf("%s\n", ans);
		return 0;
	}
	puts("NO");
	return 0;
}