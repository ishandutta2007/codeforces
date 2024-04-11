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
const int maxn = 2e5 + 5;

int n;
char s[maxn];
vector<int> inc, red;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		scanf("%s", s);
		inc.clear();
		red.clear();
		int x = 1;
		FOR(i, 0, n - 1){
			if(s[i] == '<')
				++x;
			else{
				inc.PB(x);
				x = 1;
			}
		}
		inc.PB(x);
		x = 1;
		FOR(i, 0, n - 1){
			if(s[i] == '>')
				++x;
			else{
				red.PB(x);
				x = 1;
			}
		}
		red.PB(x);
		int pos = n;
		FOR(i, 0, inc.size()){
			FOR(j, 0, inc[i])
				printf("%d ", pos - (inc[i] - j) + 1);
			pos -= inc[i];
		}
		puts("");
		pos = 1;
		FOR(i, 0, red.size()){
			FOR(j, 0, red[i])
				printf("%d ", pos + red[i] - j - 1);
			pos += red[i];
		}
		puts("");
	}
	return 0;
}