// time-limit: 1000
// problem-url: https://codeforces.com/contest/1566/problem/E

// prepare for F being massively unbalanced compared to A-E?

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}



// something weird (not my idea however)
// **definitely** should not have implemented this in contest
// but this thing does make recursive lambda nicer (not necessarily faster however)
template<class T> struct YC{
	//T const& f;
	T f; // will figure out later...
	YC(T const& f): f(f) {}
	template<class... Args> auto operator()(Args... args)const{
		return f(*this, std::forward<Args>(args)...);
	}
};




void up(){
	int number; std::cin>>number;
	std::vector<std::vector<int>> add;
	add.clear(); add.resize(number);
	for(int _=0, u, v; _<number-1; _++){
		std::cin>>u>>v;
		--u;--v;
		add[u].push_back(v); add[v].push_back(u);
	}

	int numBud{};
	int totalLeaves {};

	int const root=0;
	
	// even recursive lambda is better than global variable (TODO figure out efficiency issues? Anyway)
	auto const work=YC{[&](auto work, int node, int par)->bool{
		// return true if current node (after removed) is a leaf, false if current node is a bud
		bool curIsLeaf=true;
		for(auto child: add[node]) if(child!=par){
			if(work(child, node)){
				// is node
				totalLeaves++;
				curIsLeaf=false;
			}else{
				// is bud
				numBud++;
			}
		}
		return curIsLeaf;
	}};

	if(work(root, -1)){
		// after removed root is a leaf
		assert(numBud>=1);
		std::cout<<totalLeaves-(numBud-1)<<'\n';
	}else{
		std::cout<<totalLeaves-numBud<<'\n';
	}
	
}