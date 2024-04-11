#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
const int Segment_Size = N * 4;

int L[Segment_Size] , R[Segment_Size] , n , m , cnt, fa[N] , T[N] , Tf[N] , S[N];

struct opt {
	int x , y;
	void back(void) {
		S[y] -= S[x]; Tf[x] = T[x] = 0; fa[x] = x;
	}
}O[N];

int getf(int x) {
	if(fa[x] == x) {
		T[x] = Tf[x] = 0; return x;
	}
	int ret = getf(fa[x]);
	T[x] = T[fa[x]] ^ Tf[x];
	return ret;
}

void ret(int where) {
	while(cnt > where) O[cnt --].back();
}

#define make(x , y) (opt){x , y}

bool merge(int x , int y) {
	int fx = getf(x) , fy = getf(y);
	if(fx == fy) {
		if(!(T[x] ^ T[y])) return 0;
		return 1;
	}
	if(S[fx] > S[fy]) {
		swap(fx , fy); swap(x , y);
	}
	Tf[fx] = T[x] ^ 1 ^ T[y]; S[fy] += S[fx]; fa[fx] = fy;
	O[++ cnt] = make(fx , fy);
	return 1;
}

struct Edge {
	int x , y;
	void input(void) {
		scanf("%d%d" , &x , &y);
	}
}it;

vector<Edge>now[Segment_Size];

#define lc no << 1
#define rc no << 1 | 1
#define getmid int mid = (L[no] + R[no]) >> 1

void build(int no , int l , int r) {
	L[no] = l; R[no] = r;
	if(l >= r) return;
	getmid;
	build(lc , l , mid);
	build(rc , mid + 1, r);
}

void push(int no , int l , int r , Edge it) {
	if(l > r) return;
	if(L[no] == l && R[no] == r) {
		now[no].push_back(it); return;
	}
	getmid;
	if(l > mid) push(rc , l , r , it);
	else if(r <= mid) push(lc , l , r , it);
	else {
		push(lc , l , mid , it); push(rc , mid + 1 , r , it);
	}
}

void init(void) {
	for(int i = 1;i <= n;++ i) fa[i] = i , S[i] = 1;
}

vector<int>ans;

void dfs(int no , bool good) {
	int door = cnt;
	for(int i = 0;i < (int) now[no].size();++ i) {
		bool who;
		good &= (who = merge(now[no][i].x , now[no][i].y));
	}
	if(L[no] == R[no]) {
		if(good) {
			ans.push_back(L[no]);
		}
		ret(door);
		return;
	}
	dfs(lc , good); dfs(rc , good);
	ret(door);
}

int main(void) {
	scanf("%d%d" , &n , &m);
	// segmant bianjie
	if(m == 0) {
		puts("0");
		return 0;
	}
	init();
	build(1 , 1 , m);
	for(int i = 1;i <= m;++ i) {
		it.input();
		push(1 , 1 , i - 1 , it); push(1 , i + 1 , m , it);
	}
	dfs(1 , 1);
	cout << (int)ans.size() << endl;
	for(int i = 0;i < (int) ans.size();++ i) cout << ans[i] <<" ";
	puts("");
}