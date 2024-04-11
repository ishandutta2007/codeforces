#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void fail(){
	std::cout << -1;
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	VI ones;
	std::vector<bool> dead(n);
	VI match(n, -1);
	VI twos;
	VI thr;
	for(int i = n-1; i >= 0; --i){
		if(A[i] == 1) ones.push_back(i);
		else if(A[i] == 2){
			if(SZ(ones) == 0) fail();
			match[i] = ones.back();
			dead[ones.back()] = true;
			ones.pop_back();
			twos.push_back(i);
		}else if(A[i] == 3){
			if(SZ(thr)){
				match[i] = thr.back();
				dead[thr.back()] = true;
				thr.pop_back();
			}else if(SZ(twos)){
				match[i] = twos.back();
				dead[twos.back()] = true;
				twos.pop_back();
			}else if(SZ(ones)){
				match[i] = ones.back();
				dead[ones.back()] = true;
				ones.pop_back();
			}else fail();
			thr.push_back(i);
		}
	}

	int up = n-1;
	VI inside(n, -1);
	std::vector<PII> ans;
	FOR(i, n){
		if(A[i] == 0) continue;
		if(A[i] == 1){
			if(!dead[i]){
				ans.push_back(MP(up--, i));
			}
		}else if(A[i] == 2){
			if(!dead[i]){
				ans.push_back(MP(up, i));
				ans.push_back(MP(up, match[i]));
				--up;
			}else{
				assert(inside[i] != -1);
				ans.push_back(MP(inside[i], match[i]));
			}
		}else if(A[i] == 3){
			if(!dead[i]){
				assert(inside[i] == -1);
				ans.push_back(MP(up, i));
				ans.push_back(MP(up--, match[i]));
				ans.push_back(MP(up, match[i]));
				inside[match[i]] = up;
				up--;
			}else{
				assert(inside[i] != -1);
				ans.push_back(MP(inside[i], match[i]));
				ans.push_back(MP(up, match[i]));
				inside[match[i]] = up;
				up--;
			}
		}else{
			assert(false);
		}
	}

	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << n-i.X << " " << i.Y+1 << "\n";

	return 0;
}