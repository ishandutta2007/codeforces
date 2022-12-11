#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<tr1/unordered_map>
#include<queue>
#include<cstdlib>
#include<list>
#include<set>
#include<map>
#define MP make_pair
#define PB push_back
#define s second
#define f first
#define PII pair<int,int>
#define VPII vector <pair<int,int> >
#define VI vector <int>
#define abs(a) max((a),-(a))
#define LL long long
#define LD long double
#define ALL(x) x.begin(),x.end()
#define PU putchar_unlocked
#define GU getchar_unlocked
#define DBG(x) cerr<<#x<<" "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=b;a<=(c);a++)
#define FORD(a,b,c) for (int a=b;a>=(c);a--)
using namespace std;
int INF=1e9+1;
const int MAXN = 100;
queue<int> kolej;
LL res = 1LL;
int n,m,x,y;
bool bylo[MAXN], t[MAXN][MAXN];

void rob(int st) {
	kolej.push(st);
	bylo[st] = true;
	while (!kolej.empty()) {
		int x = kolej.front();
		kolej.pop();
		FOR(i,1,n) if (t[x][i] && !bylo[i]) {
			res *= 2LL;
			bylo[i] = true;
			kolej.push(i);
		}
	}
}

void solve() {	
	scanf("%d%d",&n,&m);
	REP(i,m) {
		scanf("%d%d",&x,&y);
		t[x][y] = t[y][x] = true;
	}
	
	FOR(i,1,n) if (!bylo[i]) rob(i);
}

int main() {
	solve();
	printf("%I64d\n",res);
}