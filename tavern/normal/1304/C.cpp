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

int n, m;
int t[maxn], l[maxn], r[maxn], ord[maxn];

inline bool cmp(const int &i, const int &j){
	return t[i] < t[j];
}

inline void update(int &l1, int &r1, int l2, int r2){
	l1 = max(l1, l2);
	r1 = min(r1, r2);
	return;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		FOR(i, 0, n){
			scanf("%d%d%d", t + i, l + i, r + i);
			ord[i] = i;
		}
		sort(ord, ord + n, cmp);
		int cl = m, cr = m;
		bool f = true;
		FOR(it, 0, n){
			int i = ord[it];
			cl -= (t[i] - (it ? t[ord[it - 1]] : 0));
			cr += (t[i] - (it ? t[ord[it - 1]] : 0));
			update(cl, cr, l[i], r[i]);
			if(cl > cr){
				puts("NO");
				f = false;
				break;
			}
		}
		if(f)
			puts("YES");
	}
	return 0;
}