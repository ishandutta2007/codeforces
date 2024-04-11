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
const int maxn = 5005;

int n, m;
int ans[maxn];

int main(){
	scanf("%d%d", &n, &m);
	int tot = 0;
	if(!m){
		FOR(i, 0, n)
			printf("%d ", (int)1e9 - (n - i));
		return 0;
	}
	FOR(i, 0, n){
		if(tot + i / 2 >= m){
			int rem = m - tot;
//			printf("i = %d rem = %d tot = %d\n", i, rem, tot);
			ans[i] = ans[i - rem * 2] + ans[i - 1];
			FOR(j, i + 1, n)
				ans[j] = (int)1e9 - (n - j) * (ans[i] + 1);
			FOR(j, 0, n){
				printf("%d ", ans[j]);
			}
			puts("");
			return 0;
		}
		tot += i / 2;
		ans[i] = i + 1;
	}
	puts("-1");
	return 0;
}