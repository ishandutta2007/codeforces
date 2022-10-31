#include <bits/stdc++.h>

typedef std::pair<double, int> pr;
#define mp std::make_pair

const int N = 200000;

std::set<pr>st1, st2;

int n, t, q, s; double ans;
int c[N + 5], l[N + 5], p[N + 5];
double pro(int x, int k) {return 1.0 * k / (l[x] + k);}
pr calc(int x, int k) {return mp((pro(x, k) - pro(x, k - 1)) * p[x], x);}
void add(int x, int d) {
	if( d == 1 ) {
		pr k = calc(x, c[x] + 1); st2.insert(k), st1.erase(k);
		ans += k.first, s++;
		if( c[x] != 0 ) st2.erase(calc(x, c[x])); 
		c[x]++; if( c[x] != l[x] ) st1.insert(calc(x, c[x] + 1));
	} else {
		pr k = calc(x, c[x]); st1.insert(k), st2.erase(k);
		ans -= k.first, s--;
		if( c[x] != l[x] ) st1.erase(calc(x, c[x] + 1)); 
		c[x]--; if( c[x] != 0 ) st2.insert(calc(x, c[x]));
	}
}
void maintain() {
	while( s < t && !st1.empty() ) add(st1.rbegin()->second, 1);
	while( !st1.empty() && !st2.empty() && st1.rbegin()->first > st2.begin()->first ) {
		int x = st1.rbegin()->second, y = st2.begin()->second;
		add(x, 1), add(y, -1);
	}
}
void update(int x, int d) {
	if( d == 1 ) {
		if( c[x] != l[x] ) st1.erase(calc(x, c[x] + 1));		
		if( c[x] != 0 ) st2.erase(calc(x, c[x]));
		
		ans -= pro(x, c[x]) * p[x];
		l[x]++;
		ans += pro(x, c[x]) * p[x];
		
		if( c[x] != l[x] ) st1.insert(calc(x, c[x] + 1));
		if( c[x] != 0 ) st2.insert(calc(x, c[x]));
	} else {
		if( c[x] == l[x] ) add(x, -1);
		
		if( c[x] != l[x] ) st1.erase(calc(x, c[x] + 1));		
		if( c[x] != 0 ) st2.erase(calc(x, c[x]));
		
		ans -= pro(x, c[x]) * p[x];
		l[x]--;
		ans += pro(x, c[x]) * p[x];
		
		if( c[x] != l[x] ) st1.insert(calc(x, c[x] + 1));
		if( c[x] != 0 ) st2.insert(calc(x, c[x]));
	}
}
int main() {
	scanf("%d%d%d", &n, &t, &q);
	for(int i=1;i<=n;i++) scanf("%d", &p[i]);
	for(int i=1;i<=n;i++) scanf("%d", &l[i]);
	for(int i=1;i<=n;i++) st1.insert(calc(i, 1));
	maintain();
	
	for(int i=1,op,r;i<=q;i++) {
		scanf("%d%d", &op, &r);
		if( op == 1 ) update(r, 1); else update(r, -1);
		maintain(), printf("%.9f\n", ans);
	}
}