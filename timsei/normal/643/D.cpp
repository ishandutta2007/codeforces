#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int Q = 1e5 + 5;

#define int long long

multiset <int> All, son[N];

#define del(x, y) x.erase(x.find(y))

int val[N], n, m, x, y, ty, T[N], f[N], S[N], q;

int get(int x) {
	return T[x] / (S[x] + 2);
}

int My(int x) {
	return T[x] - get(x) * (S[x] + 1);
}

void DelAll(int i) {
	if(!son[i].size()) return;
	del(All, (*son[i].begin()) + get(i));
	del(All, (*son[i].rbegin()) + get(i));
}

void InsertAll(int i) {
	if(!son[i].size()) return;
	All.insert((*son[i].begin()) + get(i));
	All.insert((*son[i].rbegin()) + get(i));	
}


void init(void) {
	for(int i = 1; i <= n; ++ i) {
		++ S[f[i]];
	}
	for(int i = 1; i <= n; ++ i) {
		val[i] += My(i);
		val[f[i]] += get(i);
		//cerr << i <<" "<< get(i) << endl;
	}
	for(int i = 1; i <= n; ++ i) {
		son[f[i]].insert(val[i]);
	}
	for(int i = 1; i <= n; ++ i) {
		InsertAll(i);
	}
}

main(void) {
	scanf("%lld%lld", &n, &q);
	for(int i = 1; i <= n; ++ i) scanf("%lld", &T[i]);
	for(int i = 1; i <= n; ++ i) scanf("%lld", &f[i]);
	init();
	for(; q --; ) {
		scanf("%lld", &ty);
		if(ty == 1) {
			scanf("%lld%lld", &x, &y);
			
			int z = f[x];
			
			set <int> cxt, lsk;
			cxt.clear();
			lsk = cxt;
			cxt.insert(x);
			cxt.insert(y);
			cxt.insert(f[y]);
			cxt.insert(z);
			cxt.insert(f[z]);
			
			lsk.insert(y);
			for(auto V : cxt) lsk.insert(f[V]);
			
			for(auto V : lsk) DelAll(V);
			for(auto V : cxt) del(son[f[V]], val[V]);

			val[f[z]] -= get(z);
			val[z] -= My(z) + get(x);
			-- S[z];
			val[f[z]] += get(z);
			val[z] += My(z);
			
			val[y] -= My(y);
			val[f[y]] -= get(y);
			++ S[y];
			val[f[y]] += get(y);
			val[y] += My(y) + get(x);
			
			f[x] = y;
			for(auto V : cxt) son[f[V]].insert(val[V]);
			for(auto V : lsk) InsertAll(V);
		}
		else if(ty == 2) {
			scanf("%lld", &x);
			printf("%lld\n", val[x] + get(f[x]));
		}
		else printf("%lld %lld\n", *All.begin(), *All.rbegin());
	}
}