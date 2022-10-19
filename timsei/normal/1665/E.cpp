#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int Segment_Size = N * 4;

int t, n, x, y, vis[N], A[N], L[Segment_Size], R[Segment_Size], l, r;
vector <int> G[Segment_Size];

#define lc (no << 1)
#define rc (no << 1 | 1)
#define getmid int mid  = (L[no] + R[no]) >> 1

int calcans(vector <int> &who, vector <int> &ans) {
	ans.clear();
	int cur = 0;
	for(int i = 29; i >= 0; -- i) {
		cur += (1 << i);
		int tot = 0, w = 0;
		for(auto x : who) {
			if((x & cur) == cur) ++ tot, w = x;
		}
		if(tot <= 1) {
			ans.push_back(w);
			cur -= (1 << i);
		}
	}
	int tot = 2;
	for(auto x : who) {
		if(!tot) break;
		if((x & cur) == cur) {
			-- tot;
			ans.push_back(x);
		}
	}
	tot = 0;
	for(auto x : who){
		if((x == cur)) ++ tot;
	}
	if(tot)  {
		ans.push_back(cur);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	if(tot >= 2) {
		ans.push_back(cur);
	} 
	return cur;
}

void up(int no) {
	for(int y : G[lc])
	G[no].push_back(y);
	for(int y : G[rc])
	G[no].push_back(y);	
	
	vector <int> tmp;
	calcans(G[no], tmp);
	swap(G[no], tmp);
}

void build(int no, int l, int r) {
	G[no].clear();
	L[no] = l, R[no] = r;
	if(l == r) {
		scanf("%d", &x);
		G[no].push_back((1 << 30) - 1 - x);
		return;
	}
	getmid;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	up(no);
}

vector <int> All;

void Q(int no, int l, int r) {
	if(l == L[no] && r == R[no]) {
		for(auto x : G[no]) All.push_back(x);
		return;
	}
	getmid;
	if(l > mid) Q(rc, l, r);
	else if(r <= mid) Q(lc, l, r);
	else Q(lc, l, mid), Q(rc, mid + 1, r);
	return;
}

int Q(int l, int r) {
	All.clear();
	Q(1, l, r);
	vector <int> tmp;
	return (1 << 30) - 1 - calcans(All, tmp);
}

void rmain() {
	scanf("%d", &n);
	build(1, 1, n);
	int q;
	for(cin >> q; q --;) {
		scanf("%d%d", &l, &r);
		printf("%d\n", Q(l, r));
	}
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}