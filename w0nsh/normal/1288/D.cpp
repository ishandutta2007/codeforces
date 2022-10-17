#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void transform(VI &a, bool inv=false){
	int n = SZ(a);
	for(int sz = 1; sz < n; sz *= 2){
		for(int i = 0; i < n; i += sz*2){
			for(int j = i; j < i+sz; ++j){
				int u = a[j], v = a[j+sz];
				if(!inv) a[j] = u+v, a[j+sz] = u;
				else a[j] = v, a[j+sz] = u-v;
			}
		}
	}
}

int n, m;
std::vector<VI> A;
PII check(int k){
	std::vector<int> mam(1<<m, -1);
	std::vector<int> hehe(1<<m, -1);
	FOR(i, n){
		int xd = 0;
		FOR(j, m){
			if(A[i][j] >= k) xd += (1<<j);
		}
		mam[xd] = i;
	}
	
	VI lol = mam;
	FOR(i, 1<<m) lol[i] = (lol[i] == -1 ? 0 : 1);
	transform(lol);
	FOR(i, 1<<m) lol[i] *= lol[i];
	transform(lol, true);

	for(int i = (1<<m)-1; i >= 0; --i){
		hehe[i] = mam[i];
		FOR(j, m) if(hehe[i] == -1 && (i & (1<<j)) == 0){
			hehe[i] = hehe[i|(1<<j)];
		}
	}
	FOR(i, 1<<m) if(mam[i] != -1){
		int od = ((1<<m)-1)^i;
		if(hehe[od] != -1){
			assert(lol[(1<<m)-1]);
			return MP(mam[i], hehe[od]);
		}
	}
	assert(lol[(1<<m)-1] == 0);
	return MP(-1, -1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, n){
		A.push_back(VI(m));
		FOR(j, m) std::cin >> A[i][j];
	}
	int left = 0;
	int right = 1000000001;
	while(left < right){
		int mid = (left+right)/2;
		if(check(mid).X != -1) left = mid+1;
		else right = mid;
	}
	std::cout << check(left-1).X +1 << " " << check(left-1).Y +1<< "\n";
	return 0;
}