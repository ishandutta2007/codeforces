#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

const int INF = 1000000000;
const int MAX = 100000;
const int LOG = 20;

inline bool ith(int n, int i){
	return n & (1 << i);
}
inline void set(int &n, int i){
	n = n | (1 << i);
}

struct Node{
	int min;
	Node *zero, *one;
	Node() : zero(nullptr), one(nullptr), min(INF) {}
	Node(int m) : min(m) {}
	Node(Node *z, Node *o) : zero(z), one(o) {}
};

Node tries[MAX+5];
std::vector<std::vector<int> > divisors;

void add(int t, int a){
	Node *cur = &tries[t];
	cur->min = std::min(a, cur->min);
	for(int level = LOG; level >= 0; --level){
		if(!ith(a, level)){
			if(cur->zero == nullptr)
				cur->zero = new Node();
			cur = cur->zero;
		}else{
			if(cur->one == nullptr)
				cur->one = new Node();
			cur = cur->one;
		}
		cur->min = std::min(a, cur->min);
	}
}

int query(int x, int k, int s){
	if(x % k != 0) return -1;
	// v <= s - x
	int max_val = s - x;
	Node *cur = &tries[k];
	int have = 0;
	for(int level = LOG; level >= 0; --level){
		if(cur->zero == nullptr && cur->one == nullptr) return -1;
		bool go_right = false;
		if(cur->zero != nullptr){
			if(cur->zero->min > max_val && cur->one == nullptr) return -1;
			if(!ith(x, level) && (cur->one != nullptr && cur->one->min <= max_val)) go_right = true;
			else go_right = false;
			if(cur->zero->min > max_val){
				if(cur->one->min > max_val) return -1;
				go_right = true;
			}
		}else{
			if(cur->one->min > max_val) return -1;
			go_right = true;
		}
		if(go_right){
			set(have, level);
			cur = cur->one;
		}else cur = cur->zero;
	}
	return have;
}

void answer(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int q;
	std::cin >> q;
	while(q--){
		int type;
		std::cin >> type;
		if(type == 1){
			int a;
			std::cin >> a;
			for(auto &t : divisors[a]){
				add(t, a);
			}
		}else{
			int x, k, s;
			std::cin >> x >> k >> s;
			std::cout << query(x, k, s) << "\n";
		}
	}
}

void calc_divisors(){
	divisors.resize(MAX+5);
	for(int i = 1; i <= MAX; ++i){
		for(int j = i; j <= MAX; j+=i){
			divisors[j].push_back(i);
		}
	}
}

int main(){
	calc_divisors();
	answer();
	return 0;
}