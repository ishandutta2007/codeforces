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

std::mt19937 _gen;
std::uniform_int_distribution<int> _u_i_d(0, 1<<30);
inline int los(int a, int b){
	return a + _u_i_d(_gen)%(b-a+1);
}


VI nums = {4, 8, 15, 16, 23, 42};

void get(std::set<int> &vec, int a){
	FOR(i, SZ(nums)){
		REP(j, i+1, SZ(nums)){
			if(nums[i]*nums[j] == a){
				vec.insert(nums[i]);
				vec.insert(nums[j]);
				return;
			}
		}
	}
}

int same(std::set<int> a, std::set<int> b){
	TRAV(i, a){
		TRAV(j, b){
			if(i == j) return i;
		}
	}
	return -1;
}

int main(){
	_gen.seed(std::chrono::steady_clock::now().time_since_epoch().count());
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << "? 1 2" << std::endl;
	std::set<int> fs, sc;
	int ans;
	std::cin >> ans;
	get(fs, ans);
	std::cout << "? 3 4" << std::endl;
	std::cin >> ans;
	get(sc, ans);
	std::cout << "? 1 5" << std::endl;
	std::set<int> aa, bb;
	std::cin >> ans;
	get(aa, ans);
	std::cout << "? 3 5" << std::endl;
	std::cin >> ans;
	get(bb, ans);
	std::set<int> was;
	TRAV(i, fs) was.insert(i);
	TRAV(i, sc) was.insert(i);
	TRAV(i, aa) was.insert(i);
	TRAV(i, bb) was.insert(i);
	std::cout << "! " << same(fs, aa) << " ";
	fs.erase(same(fs, aa));
	std::cout << *fs.begin() << " ";
	std::cout << same(sc, bb) << " ";
	int xddd = same(sc, bb);
	bb.erase(xddd);
	sc.erase(xddd);
	std::cout << *sc.begin() << " ";
	std::cout << *bb.begin() << " ";
	TRAV(i, nums) if(was.count(i) == 0) std::cout << i << std::endl;
	return 0;
}