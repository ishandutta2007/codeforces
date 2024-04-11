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

int n, m;
int a[maxn];
vector<pii> vec;

int main(){
	scanf("%d%d", &n, &m);
	int lst = -1;
	FOR(i, 0, n){
		scanf("%d", a + i);
		if(a[i] != lst)
			vec.PB(MP(i, a[i]));
		lst = a[i];
	}
//	FOR(i, 0, vec.size())
//		printf("%d %d\n", vec[i].fst, vec[i].snd);
	FOR(i, 0, m){
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		--l; --r;
		if(a[l] != x)
			printf("%d\n", l + 1);
		else{
			int ans = upper_bound(vec.begin(), vec.end(), MP(l, INF)) - vec.begin();
			if(ans ==vec.size() || vec[ans].fst > r)
				puts("-1");
			else
				printf("%d\n", vec[ans].fst + 1);
		}
	}
	return 0;
}