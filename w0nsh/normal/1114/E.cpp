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

bool greater(int a){
	std::cout << "> " << a  << std::endl;
	int b;
	std::cin >> b;
	return b == 1;
}

int num(int a){
	std::cout << "? " << a << std::endl;
	int b;
	std::cin >> b;
	return b;
}

std::set<int> get_divs(int n){
	std::set<int> ret;
	for(int i = 1; i*i <= n; ++i){
		if(n % i == 0){
			ret.insert(i);
			ret.insert(n/i);
		}
	}
	return ret;
}

int n;
int main(){
	_gen.seed(std::chrono::steady_clock::now().time_since_epoch().count());
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	int left = 0;
	int right = 1000000001;
	int used = 0;
	while(left < right){
		int mid = (left+right)/2;
		used++;
		if(greater(mid)) left = mid+1;
		else right = mid;
	}
	int x1 = left;
	VI nms;
	std::set<int> was;
	while(used < 60 && SZ(was) < n){
		used++;
		int ls = los(1, n);
		while(was.count(ls) > 0) ls = los(1, n);
		was.insert(ls);
		nms.push_back(num(ls));
	}
	std::vector<std::set<int> > divs;
	std::sort(nms.begin(), nms.end());
	FOR(i, SZ(nms)) REP(j, i+1, SZ(nms)){
		divs.push_back(get_divs(nms[j]-nms[i]));
	}
	REP(i, 1, SZ(divs)){
		std::set<int> nw;
		TRAV(dv, divs[i]){
			if(divs[i-1].count(dv) > 0) nw.insert(dv);
		}
		divs[i] = nw;
	}
	std::cout << "! " << x1-(n-1)*(*(--divs.back().end())) << " " << *(--divs.back().end()) << std::endl;
	return 0;
}