#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;

int n;
char s[maxn];

inline void solve(){
	scanf("%s", s);
	n = strlen(s);
	int rema = 0, remb = 0;
	for(int i = n - 1; i >= 0; --i){
		if(s[i] == 'A'){
			if(remb)
				--remb;
			else
				++rema; 
		}
		else
			++remb;
	}
	printf("%d\n", remb % 2 + rema);
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}