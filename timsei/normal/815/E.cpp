#include <bits/stdc++.h>
using namespace std;

#define int long long

int i, j, k, n, m, t, sb, x, y, z;
map <int, int> mp, mp2;

void fuck(int x) {
	mp.clear(); mp2.clear(); mp[-x] = 1;
	while(1){
		pair <int, int> a = *mp.begin();
		mp.erase(mp.begin());
		int xx = a.first;
		int yy = a.second;
		x = -xx;
		y = yy;
		z = -(x - 1) / 2;
		if (x <= 0) return;
		mp[z] += y;
		mp2[z] += y;
		mp[-(x - 1 + z)] += y;
	}
}

main() {
	cin >> n >> m;
	if(m <= 2) {cout << ((m == 1) ? 1 : n); return 0;}
	m -= 2; fuck(n - 2);
	for(auto a : mp2){
		int i = a.first, j = a.second;
		if(j >= m) {sb = -i; break;}m -= j;
	}
	int l = 1 , r = n, md;
	while(1) {
		if((r - l - 2) / 2 == sb)
		if(!-- m) {cout << (l + r) / 2; return 0;}
		md = (l + r) / 2; fuck(md - l - 1);
		if(mp2[-sb] >= m) r = md; 
		else l = md, m -= mp2[-sb];
	}
}