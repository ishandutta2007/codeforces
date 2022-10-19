#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

map <int, int> Map;
int cnt, fa[N], n, m, x, y, Tr[N], last, l, r;

int getf(int x) {
	if(fa[x] == x) return x;
	else {
		int ans = getf(fa[x]);
		Tr[x] = Tr[x] ^ Tr[fa[x]];
		return fa[x] = ans; 
	}
}

int newnode(void) {
	++ cnt;
	fa[cnt] = cnt;
	Tr[cnt] = 0;
	return cnt;
}

int get(int x) {
	if(Map.count(x)) return Map[x];
	return Map[x] = newnode();
}

int main() {
	int t, ty;
	last = 0;
	for(cin >> t; t --;) {
		scanf("%d", &ty);
		scanf("%d%d", &l, &r);
		l ^= last;
		r ^= last;
		if(l > r) swap(l, r);
		++ r;
		if(ty == 1) {
			scanf("%d", &x);
			x ^= last;
			l = get(l); r = get(r);
			if(getf(l) == getf(r)) {
				continue;
			}
			else {
				int A = Tr[l], B = Tr[r];
				l = getf(l), r = getf(r);
				Tr[l] = A ^ B ^ x;
				fa[l] = r;
				continue;
			}
		}
		else {
			l = get(l); r = get(r);
			if(getf(l) != getf(r)) {
				puts("-1");
				last = 1;
			}
			else {
				printf("%d\n", last = (Tr[l] ^ Tr[r]));
			}
		}
	}
}