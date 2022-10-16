#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double Lf;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;

int n, tag;
int a[maxn], pre[maxn], nxt[maxn];
vector<int> ans;
set<int> S;
set<int>::iterator it;

inline bool findNext(){
//	printf("size = %d tag = %d\n", S.size(), tag);
	
	if(S.empty() && !~tag)
		return false;
	if(it == S.end())
		it = S.begin();
	if(~tag)
		S.insert(tag);
		
//	printf("size = %d\n", S.size());
		
	if(it == S.end())
		it = S.begin();
		
//	for(set<int>::iterator jt = S.begin(); jt != S.end(); ++jt)
//		printf("%d ", *jt); puts("");
		
	int pos = *it;
	
	ans.PB(pos + 1);
	
	int p = pre[pos], q = nxt[pos];
	
//	printf("p = %d q = %d it = %d\n", p, q, *it);
	
	S.erase(pos);
	
	if(q != pos && __gcd(a[q], a[pos]) == 1)
		S.erase(q);
	if(p != pos && __gcd(a[q], a[p]) == 1)
		tag = q;
	else
		tag = -1;
	it = S.lower_bound(pos);
	nxt[p] = q, pre[q] = p;
	return true;
}

inline void solve(){
	scanf("%d", &n);
	S.clear();
	FOR(i, 0, n){
		scanf("%d", a + i);
		nxt[i] = (i + 1) % n;
		pre[i] = (i - 1 + n) % n;
	}
	FOR(i, 0, n){
		if(__gcd(a[i], a[(i - 1 + n) % n]) == 1)
			S.insert(i);
	}
	
	ans.clear();
	it = S.lower_bound(1);
	tag = -1;
	for(; findNext(); );
	
	printf("%d ", ans.size());
	FOR(i, 0, ans.size())
		printf("%d ", ans[i]); puts("");
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}