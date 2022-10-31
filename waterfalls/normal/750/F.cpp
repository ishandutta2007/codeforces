#include <bits/stdc++.h>
using namespace std;

int h;
map<int,vector<int> > adj;

bool respond(int x) {
	printf("! %d\n",x);
	fflush(stdout);
	return true;
}

bool query(int x) {
	if (adj.count(x)) return false;
	printf("? %d\n",x);
	fflush(stdout);
	int k;
	scanf("%d",&k);
	if (k==0) exit(0);
	for (int i=0;i<k;i++) {
		int y;
		scanf("%d",&y);
		adj[x].push_back(y);
	}
	if (k==2) return respond(x);
	return false;
}

int getMex(int x, vector<int> bad) {
	int on = 0;
	while (on<adj[x].size()) {
		bool ok = 1;
		for (int i: bad) ok&=(adj[x][on]!=i);
		if (ok) return adj[x][on];
		on+=1;
	}
	return 0;
}

deque<int> getPath(int x, int from) {
	if (query(x)) return {};
	if (adj[x].size()==1) return { x };
	deque<int> res = getPath(getMex(x,{ from }),x);
	if (!res.size()) return {};
	res.push_front(x);
	return res;
}

bool findAtDist(int x, int from, int d) {
	if (d==0) return respond(x);
	if (query(x)) return true;
	if (d==1) {
		int a = getMex(x,{ from });
		if (a && query(a)) return true;
		return respond(getMex(x,{ from, a }));
	}
	if (d==2) {
		int a = getMex(x,{ from });
		if (query(a)) return true;
		int b = getMex(a,{ x });
		if (b && query(b)) return true;
		b = getMex(a,{ x, b });
		if (b && query(b)) return true;
		a = getMex(x,{ from, a });
		if (query(a)) return true;
		b = getMex(a,{ x });
		if (b && query(b)) return true;
		return respond(getMex(a,{ x, b }));
	}
	int a = getMex(x,{ from });
	deque<int> one = getPath(a,x);
	if (!one.size()) return true;
	if (one.size()==h-1-d) return findAtDist(getMex(x,{ from, a }),x,d-1);
	int num = 0;
	for (int i=0;i<h-1-d;i++) {
		one.pop_back();
		num+=1;
	}
	one.push_front(x);
	while (one.size()>3) {
		one.pop_front();
		one.pop_back();
		num+=1;
	}
	return findAtDist(getMex(one[1],{ one[0], one[2] }),one[1],h-3-num);
}

bool solve() {
	adj.clear();
	scanf("%d",&h);
	if (h==0) exit(0);
	int start = 1;
	if (query(start)) return true;
	if (adj[start].size()==1) return findAtDist(getMex(start,{}),start,h-2);
	deque<int> one = getPath(getMex(start,{}),start);
	if (!one.size()) return true;
	deque<int> two = getPath(getMex(start,{ one[0] }),start);
	if (!two.size()) return true;
	if (one.size()==two.size()) return findAtDist(getMex(start,{ one[0], two[0] }),start,h-2-one.size());
	if (one.size()<two.size()) swap(one,two);
	int num = 0;
	while (one.size() && two.size()) {
		one.pop_back();
		two.pop_back();
		num+=1;
	}
	one.push_front(start);
	while (one.size()>3) {
		one.pop_front();
		one.pop_back();
		num+=1;
	}
	return findAtDist(getMex(one[1],{ one[0], one[2] }),one[1],h-3-num);
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		solve();
	}

	return 0;
}