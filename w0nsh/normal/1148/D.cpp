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

void print(VI &v){
	std::cout << SZ(v) << "\n";
	TRAV(i, v) std::cout << i+1 << " ";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PR<PII, int> > A, B;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		if(a > b) A.push_back(MP(MP(a, b), i));
		else B.push_back(MP(MP(a, b), i));
	}
	std::sort(A.begin(), A.end(), [](const PR<PII, int> &a, const PR<PII, int> &b){
		return a.X.Y < b.X.Y;
	});
	std::sort(B.begin(), B.end(), [](const PR<PII, int> &a, const PR<PII, int> &b){
		return a.X.Y > b.X.Y;
	});
	std::vector<int> a1, a2;
	int last = -1;
	TRAV(i, A){
		if(i.X.X > last){
			a1.push_back(i.Y);
			last = i.X.Y;
		}else break;
	}
	last = 1000000000;
	TRAV(i, B){
		if(i.X.X < last){
			a2.push_back(i.Y);
			last = i.X.Y;
		}else break;
	}
	if(SZ(a1) > SZ(a2)) print(a1);
	else print(a2);
	return 0;
}