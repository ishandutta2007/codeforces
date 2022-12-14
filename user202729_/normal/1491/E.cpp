// proven
// that's why there are so many people solved it...
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;

// return subtreeSize, throw std::pair<int, int>(a, b) if found with good size
// such that subtreeSize -> a = a, subtreeSize -> b = b
int work(int node, int parNode, int a, int b){
	int subtreeSizeNode=1;
	for(auto child: add[node]) if(child!=parNode)
		subtreeSizeNode+=work(child, node, a, b);
	if(subtreeSizeNode==a) throw std::pair<int, int>(node, parNode);
	if(subtreeSizeNode==b) throw std::pair<int, int>(parNode, node);
	return subtreeSizeNode;
}

bool work2(int node, int a, int b){
	// a, b: 2 consecutive terms in the Fibonacci sequence, b==size of current component size
	if(b==1) return true;
	std::tie(a, b)=std::pair(b-a, a);
	try{
		work(node, -1, a, b);
	}catch(std::pair<int, int> value){
		auto const [x, y]=value;
		add[x].erase(std::find(begin(add[x]), end(add[x]), y));
		add[y].erase(std::find(begin(add[y]), end(add[y]), x));
		return work2(x, b-a, a) and work2(y, a, b);
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	add.resize(number);
	for(int _=0, u, v; _<number-1; _++){
		std::cin>>u>>v;
		--u;--v;
		add[u].push_back(v); add[v].push_back(u);
	}

	int a=1, b=1;
	while(b<number) std::tie(a, b)=std::pair(b, a+b);
	std::cout<<(b==number and work2(0, a, b) ? "YES\n": "NO\n");
}