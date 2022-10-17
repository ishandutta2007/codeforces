#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n, m;
VI vert, hor;

bool check(int k){
	if(k >= SZ(vert) || k >= SZ(hor)) return true;
	//if(k >= SZ(vert)) return true;
	if(vert[k] > hor[SZ(hor)-1]) return true;
	FOR(i, k){
		if(vert[i] > (SZ(hor)-1-k+i < 0 ? 0 : hor[SZ(hor)-1-k+i])) return true;
	}
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, n){
		int a;
		std::cin >> a;
		vert.push_back(a);
	}
	FOR(i, m){
		int a, b, y;
		std::cin >> a >> b >> y;
		if(a == 1) hor.push_back(b);
	}
	std::sort(vert.begin(), vert.end());
	std::sort(hor.begin(), hor.end());
	bool xd = false;
	FOR(i, SZ(hor)) if(hor[i] != 1000000000) xd = true;
	if(!xd){
		std::cout << SZ(hor) << "\n";
		return 0;
	}
	if(SZ(vert) == 0 || hor.back() < vert[0]){
		std::cout << 0 << "\n";
		return 0;
	}
	int left = 0;
	int right = std::min(SZ(vert), SZ(hor))+1;
	while(left < right){
		int mid = (left+right)/2;
		if(check(mid)) right = mid-1;
		else left = mid+1;
	}
	if(!check(left)) left++;
	std::cout << std::min((int)std::min(SZ(vert), SZ(hor)), left) << "\n";
	return 0;
}