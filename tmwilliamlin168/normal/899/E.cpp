#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

struct data{
	int l;
	int r;
	int len;

	data(int x, int y, int z){
		l = x;
		r = y;
		len = z;
	}

	bool operator <(const data &other) const{
		return l < other.l;
	}
};

int n;
int a[N];
set < data > now;
set < pair < int, int > > res;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	for(int i = 1; i <= n; ++i){
		int pter = i;
		while(a[pter] == a[i]) ++pter;
		now.emplace(i, pter - 1, pter - i);
		res.emplace(pter - i, n - i);
		i = pter - 1;
	}

	int ans = 0;

	while(!res.empty()){
		++ans;
		auto p = *res.rbegin();
		res.erase(p);

		int x = n - p.second;

		auto it = now.upper_bound({x - 1, 0, 0});
		auto nxt = it;
		++nxt;

		auto g = *it;

		if(it != now.begin() && nxt != now.end()){
			auto pre = it;
			--pre;

			if(a[pre -> l] == a[nxt -> r]){
				data add(pre -> l, nxt -> r, pre -> len + nxt -> len);
				auto d = *pre, s = *nxt;
				res.erase(make_pair(pre -> len, n - pre -> l));
				res.erase(make_pair(nxt -> len, n - nxt -> l));
				now.erase(d);
				now.erase(s);
				now.insert(add);
				res.emplace(add.len, n - add.l);
			}
		}
		now.erase(g);
	}

	cout << ans;

	return 0;
}