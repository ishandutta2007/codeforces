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
const int maxn = 1005;

int n;
char s[maxn];

int main(){
	scanf("%s", s);
	n = strlen(s);
	int l = 0, r = 0;
	FOR(i, 0, n)
		r += (s[i] == ')');
	if(!r || r == n){
		puts("0");
		return 0;
	}
	FOR(i, 0, n){
		l += (s[i] == '(');
		r -= (s[i] == ')');
		if(l == r){
			if(!l){
				puts("0");
				return 0;
			}
			puts("1");
			printf("%d\n", l + r);
			REP(j, 0, i) if(s[j] == '(')
				printf("%d ", j + 1);
			FOR(j, i + 1, n) if(s[j] == ')')
				printf("%d ", j + 1);
			return 0;
		}
	}
	return 0;
}