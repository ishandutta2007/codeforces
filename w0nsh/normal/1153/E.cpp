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

int n;

int query(int x1, int y1, int x2, int y2){
	x1++;y1++;x2++;y2++;
	std::cout << "? " << x1 << " "<< y1 << " " << x2 << " " << y2 << std::endl;
	int xd;
	std::cin >> xd;
	return xd % 2;
}

void answer(int x1, int y1, int x2, int y2){
	x1++;y1++;x2++;y2++;
	std::cout << "! " << x1 << " " << y1 << " " << x2 << " "<< y2 << std::endl;
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	VI cols, rows;
	FOR(i, n){
		if(query(i, 0, i, n-1) == 1) cols.push_back(i);
	}
	FOR(i, n){
		if(query(0, i, n-1, i) == 1) rows.push_back(i);
	}
	if(SZ(rows) == 0){
		int myx = cols[0];
		int left = 0;
		int right = n-1;
		while(left < right){
			int mid = (left+right)/2;
			if(query(myx, 0, myx, mid) == 1) right = mid;
			else left = mid+1;
		}
		answer(cols[0], left, cols[1], left);
	}else if(SZ(cols) == 0){
		int myy = rows[0];
		int left = 0;
		int right = n-1;
		while(left < right){
			int mid = (left+right)/2;
			if(query(0, myy, mid, myy) == 1) right = mid;
			else left = mid+1;
		}
		answer(left, rows[0], left, rows[1]);
	}else{
		std::vector<PII> good;
		TRAV(i, rows) TRAV(j, cols){
			if(query(j, i, j, i) == 1) good.push_back(MP(j, i));
		}
		answer(good[0].X, good[0].Y, good[1].X, good[1].Y);
	}
	return 0;
}