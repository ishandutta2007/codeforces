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
const int maxn = 1e5 + 5;

int n;
int x[maxn], y[maxn];
vector<pii> vec;

int main(){
	scanf("%d", &n);
	FOR(i, 0, n)
		scanf("%d%d", x + i, y + i);
	FOR(i, 0, n){
		vec.PB(MP(x[(i + 1) % n] - x[i], y[(i + 1) % n] - y[i]));
	}
	if(n & 1)
		puts("NO");
	else{
		FOR(i, 0, n / 2) if(MP(-vec[i].fst, -vec[i].snd) != vec[i + n / 2]){
			puts("NO");
			return 0;
		}
		puts("YES");
	}
	return 0;
}