#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

#define int long long

const int N = 4e5 + 5;

vector <int> a , b , c , d;

int n , m , x , y , len , k , C[N];
long long ans = 1e18;

int vis[N] , tot;

bool cmp(int x , int y) {
	return C[x] < C[y];
}

#define ALL(x) x.begin() , x.end()
#define lowbit(x) (x & (-x))

map<int,int> Map , chg;
int id[N];

struct BIT {
	int S[N];
	void init(void) {
		memset(S , 0 , sizeof(S));
	}
	void add(int x , int v) {
		for(int i = x;i < N;i += lowbit(i)) S[i] += v;
	}
	long long sum(int x) {
		long long res = 0;
		for(int i = x;i;i -= lowbit(i)) res += S[i];
		return res;
	}
}B[2];

long long getans(int x) {
	if(!x) return 0ll;
	long long res = 0;
	if(B[0].sum(tot) < x) return 1e15;
	int L = 0 , R = n , cur = - 1;
	while(L <= R) {
		int mid = (L + R) >> 1;
		if(B[0].sum(mid) >= x) {
			cur = mid; R = mid - 1;
		}
		else L = mid + 1;
	}
	long long more = 0;
	if(B[0].sum(cur) > x) {
		more = B[0].sum(cur) - x;
	}
	res = B[1].sum(cur) - more * id[cur];
	return res;
}

main(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void(void)))))))))))))))))))))))))) {
	B[0].init(); B[1].init();
	cin >> n >> m >> k;
	for(int i = 1;i <= n;++ i) cin >> C[i];
	cin >> len;
	for(int i = 1;i <= len;++ i) cin >> x , vis[x] = 1;
	cin >> len;
	for(int i = 1;i <= len;++ i) cin >> x , (vis[x]) ? (vis[x] = 2) : vis[x] = -1;
	for(int i = 1;i <= n;++ i) {
		if(vis[i] == 1) a.push_back(i);
		else if(vis[i] == -1) b.push_back(i);
		else if(vis[i] == 2) c.push_back(i);
		else d.push_back(i);
	}
	sort(ALL(a) , cmp); sort(ALL(b) , cmp); sort(ALL(c), cmp); sort(ALL(d) , cmp);
	for(int i = 1;i <= n;++ i) ++ Map[C[i]];
	for(map<int,int> ::iterator it = Map.begin(); it != Map.end();++ it) {
		id[++ tot] = it -> first; chg[it -> first] = tot;
	}
	for(int i = 0;i < (int) d.size(); ++ i) {
		int cur = chg[C[d[i]]];
		B[0].add(cur , 1);
		B[1].add(cur , C[d[i]]);
	}
	int L = max(k - (int)c.size() , 0ll) , R = min(a.size() , b.size()) , pc = (int)c.size() , pal = 0;
	if(m > n || c.size() + min(a.size() , b.size()) < k || 2 * k - (int)c.size() > m || R < L) return 0 * puts("-1");
	long long Sa = 0 , Sb = 0 , Sc = 0;
	for(int i = 0;i < (int) c.size();++ i) Sc += C[c[i]];
	for(int i = 0;i < (int) a.size();++ i) B[0].add(chg[C[a[i]]] , 1) , B[1].add(chg[C[a[i]]] , C[a[i]]);
	for(int i = 0;i < (int) b.size();++ i) B[0].add(chg[C[b[i]]] , 1) , B[1].add(chg[C[b[i]]] , C[b[i]]);
	for(int i = L;i <= R;++ i) {
		if(i > k) break;
		while(pal < i) Sa += C[a[pal]] , B[0].add(chg[C[a[pal]]] , -1) , B[1].add(chg[C[a[pal]]] , - C[a[pal]]) , Sb += C[b[pal]] , B[0].add(chg[C[b[pal]]] , -1) , B[1].add(chg[C[b[pal]]] , - C[b[pal]]), ++ pal;
		while(pc > k - i) -- pc , Sc -= C[c[pc]] , B[0].add(chg[C[c[pc]]] , 1) , B[1].add(chg[C[c[pc]]] , C[c[pc]]);
		if(i * 2 + k - i > m) continue;
		ans = min(ans , Sa + Sb + Sc + getans(m - i - k));
	}
	if(ans > 1e15) {
		puts("-1");
	}
	else cout << ans;
}