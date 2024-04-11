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

int h, m, a;

int main(){
	scanf("%d:%d%d", &h, &m, &a);
	a %= 1440;
	h += a / 60;
	m += a % 60;
	h += m / 60;
	m %= 60;
	h %= 24;
	printf("%s%d:%s%d\n", (h < 10 ? "0" : ""), h, (m < 10 ? "0" : ""), m);
	return 0;
}