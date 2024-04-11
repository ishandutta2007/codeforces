#include <bits/stdc++.h>

const int N = 200000;

int c[N + 5], n; bool b[N + 5];

std::vector<std::pair<int, int> >ans;
void print() {
	printf("%d\n", (int)ans.size());
	for(auto x : ans) printf("%d %d\n", x.first, x.second);
}
void add(int x, int y) {
	ans.push_back(std::make_pair(x, y));
	b[c[x]] ^= 1, b[c[y]] ^= 1;
	std::swap(c[x], c[y]);
}

void do1(int x, int y) {
	add(x, y);
	while( c[y] != x ) add(y, c[y]);
	while( c[x] != y ) add(x, c[x]);
	add(x, y);
}
void do2(int x) {
	if( c[x] == x ) return ;
	int y = c[x]; add(x, y);
	while( c[c[x]] != x ) add(x, c[x]);
	int z = c[x];
	add(y, z), add(x, z), add(x, y);
}
void do3(int x, int y, int z) {
	add(x, y), add(y, z);
	while( c[y] != x ) add(y, c[y]);
	while( c[x] != y ) add(x, c[x]);
	add(x, y);	
}

int siz[N + 5]; bool vis[N + 5]; std::vector<int>v;
int main() {
	scanf("%d", &n); for(int i=1;i<=n;i++) scanf("%d", &c[i]);
	for(int i=1;i<=n;i++) if( !vis[i] ) {
		v.push_back(i);
		for(int p=i;!vis[p];p=c[p])
			vis[p] = true;
	}
	
	if( v.size() == 1 ) do2(v[0]);
	else if( v.size() & 1 ) {
		for(unsigned i=3;i+1<v.size();i+=2) do1(v[i], v[i + 1]);
		do3(v[0], v[1], v[2]);
	} else {
		for(unsigned i=0;i+1<v.size();i+=2) do1(v[i], v[i + 1]);
	}
	
	if( (int)ans.size() > n + 1 ) {puts("WA 1"); return 0;}
	for(int i=1;i<=n;i++) {
		if( b[i] ) {puts("WA 2"); return 0;}
		if( c[i] != i ) {puts("WA 3"); return 0;}
	}
	print();
}