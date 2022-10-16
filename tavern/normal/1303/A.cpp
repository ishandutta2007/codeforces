#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 105;

int T;
int n;
char s[maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		int ans = 0;
		scanf("%s", s);
		n = strlen(s);
		FOR(i, 0, n)
			ans += (s[i] == '0');
		int i, j;
		for(i = 0; i < n && s[i] == '0'; ++i, --ans);
		for(j = n - 1; j > i && s[j] == '0'; --j, --ans);
		printf("%d\n", ans);
	}
	return 0;
}