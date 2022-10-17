#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

int left(int v){
	return v << 1;
}
int right(int v){
	return (v<<1)+1;
}
int parent(int v){
	return v >> 1;
}

int BOTTOM = 0;
int DEPTH = 1;
struct Tree{

	std::vector<int> t;
	void build(int size){
		BOTTOM = 1;
		while(BOTTOM < size){
			BOTTOM <<= 1;
			DEPTH++;
		}
		t.resize(BOTTOM*2);
	}
	
	void update(int v, int val){
		v += BOTTOM;
		while(v >= 1){
			if(val > t[v]) t[v] = val;
			else break;
			v = parent(v);
		}
	}

	int query(int a, int b, int v=1, int low=0, int high=BOTTOM-1){
		if(a > b) return 0;
		if(a == low && b == high){
			return t[v];
		}
		int mid = (low+high)>>1;
		return std::max(query(a, std::min(b, mid), left(v), low, mid),
						query(std::max(a, mid+1), b, right(v), mid+1, high));
	}
};

const int NMAX = 5000;
const int QMAX = 1000000;

int n;
int dp[NMAX+5][NMAX+5];
std::vector<std::pair<ii, int> > update_vals;
int A[NMAX+5];
int q;
std::vector<std::pair<ii, int> > Q;
int ANS[QMAX];

void answer(){
	std::sort(Q.begin(), Q.end(), [](const std::pair<ii, int> &a, const std::pair<ii, int> &b){
				return a.first.second < b.first.second;
			});
	std::sort(update_vals.begin(), update_vals.end(), [](const std::pair<ii, int> &a, const std::pair<ii, int> &b){
				return a.first.second < b.first.second;
			});
	int r = 0;
	auto it = Q.begin();
	Tree tree;
	tree.build(n);
	auto pos = update_vals.begin();
	while(pos != update_vals.end() && pos->first.second <= r){
		tree.update(pos->first.first, pos->second);
		pos++;
	}
	while(it != Q.end()){
		if(r < it->first.second){
			r++;
			while(pos != update_vals.end() && pos->first.second <= r){
				tree.update(pos->first.first, pos->second);
				pos++;
			}
		}else{
			ANS[it->second] = tree.query(it->first.first, n-1);
			it++;
		}
	}

	for(int i = 0 ; i < q; ++i){
		std::cout << ANS[i] << "\n";
	}
}

void calc_dp(){
	for(int i = 0; i < n; ++i){
		dp[1][i] = A[i];
		update_vals.push_back(std::make_pair(std::make_pair(i, i), A[i]));
	}
	for(int s = 2; s <= n; ++s){
		for(int i = 0; i < n-s+1; ++i){
			dp[s][i] = dp[s-1][i] ^ dp[s-1][i+1];
			update_vals.push_back(std::make_pair(std::make_pair(i, i+s-1), dp[s][i]));
		}
	}
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for(int i = 0; i < n; ++i) std::cin >> A[i];
	std::cin >> q;
	for(int i = 0; i < q; ++i){
		int a, b;
		std::cin >> a >> b;
		Q.push_back(std::make_pair(std::make_pair(a-1, b-1), i));
	}
}

int main(){
	read();
	calc_dp();
	answer();
	return 0;
}