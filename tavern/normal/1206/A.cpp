// orz dxm
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define y0 yORZDXM
#define y1 yORZDXM
#define y2 yORZDXM
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const int maxn = 105;

int n, m;
int a[maxn], b[maxn];
map<int, int> mp;

int main(){
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i), mp[a[i]] = true;
	scanf("%d", &m);
	FOR(i, 0, m) scanf("%d", b + i), mp[b[i]] = true;
	FOR(i, 0, n) FOR(j, 0, m) if(!mp[a[i] + b[j]]){
		printf("%d %d\n", a[i], b[j]);
		return 0;
	}
	return 0;
}