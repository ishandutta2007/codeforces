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

PII operator -(const PII &a, const PII &b){
	return MP(a.X-b.X, a.Y-b.Y);
}
bool left(PII A, PII B, PII C){
	PII fs = B-A;
	PII sc = C-A;
	return 1ll*fs.X*sc.Y - 1ll*fs.Y*sc.X > 0;
}

PII pop(std::vector<PII> &A, int p){
	std::swap(A.back(), A[p]);
	PII ret = A.back();
	A.pop_back();
	return ret;
}

std::map<PII, int> kto;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PII> A(n);
	FOR(i, n){
		std::cin >> A[i].X >> A[i].Y;
		kto[A[i]] = i+1;
	}
	std::string str;
	std::cin >> str;
	std::sort(A.begin(), A.end());
	std::vector<PII> hull;
	hull.push_back(pop(A, 0));
	int best = 0;
	REP(i, 1, SZ(A)) if(left(hull.back(), A[best], A[i])) best = i;
	hull.push_back(pop(A, best));
	while(SZ(A)){
		best = 0;
		REP(i, 1, SZ(A)) if(left(hull.back(), A[best], A[i])) best = i;
		if(left(hull.back(), A[best], hull[0])) break;
		hull.push_back(pop(A, best));
	}
	int last = 0;
	std::cout << kto[hull[0]] << " ";
	FOR(si, n-2){
		if(str[si] == 'L'){
			int nw = (last-1+SZ(hull))%SZ(hull);
			std::cout << kto[hull[nw]] << " ";
			int nxt = (last+1)%SZ(hull);
			std::vector<PII> nh;
			nh.push_back(hull[nw]);
			while(SZ(A)){
				best = -1;
				FOR(i, SZ(A)) if(left(nh.back(), (best == -1 ? hull[nxt] : A[best]), A[i])) best = i;
				if(best == -1) break;
				nh.push_back(pop(A, best));
			}
			FOR(i, SZ(hull)-2){
				nh.push_back(hull[(nxt+i)%SZ(hull)]);
			}
			hull = nh;
		}else{
			int nw = (last+1)%SZ(hull);
			std::cout << kto[hull[nw]] << " ";
			std::vector<PII> nh;
			FOR(i, SZ(hull)-1){
				nh.push_back(hull[(nw+i)%SZ(hull)]);
			}
			while(SZ(A)){
				best = -1;
				FOR(i, SZ(A)) if(left(nh.back(), (best == -1 ? hull[nw] : A[best]), A[i])) best = i;
				if(best == -1) break;
				nh.push_back(pop(A, best));
			}
			hull = nh;
		}
	}
	std::cout << kto[(last == 0 ? hull[1] : hull[0])] << "\n";
	return 0;
}