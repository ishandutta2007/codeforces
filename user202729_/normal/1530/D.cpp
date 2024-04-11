// time-limit: 2000
// problem-url: https://codeforces.com/contest/1530/problem/D
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

std::vector<std::vector<int>> add;
std::vector<char> visited;

std::vector<int> order;
void work(int node){
	// append the postorder traversal from (node) to (order)
	// and set (visited) of all visited nodes
	visited[node]=true;
	for(auto x: add[node])
		work(x);
	order.push_back(node);
}

void up(){
	int n; std::cin>>n;
	add.clear(); add.resize(n);

	std::vector<int> a(n);
	for(int i=0; i<n; ++i){
		int& a_=a[i]; std::cin>>a_; --a_;
		add[a_].push_back(i);
	}

	visited.clear(); visited.resize(n);
	//std::vector<int> b(n);
	std::unique_ptr<int[]> b(new int[n]); // occasional microoptimizations
	for(int i=0; i<n; ++i) if(not visited[i]){
		int j=i;
		while(not visited[j]){
			visited[j]=true;
			j=a[j];
		}

		// now j is in some cycle
		int k=j;
		order.clear();
		do{
			add[a[k]].erase(std::find(begin(add[a[k]]), end(add[a[k]]), k));
			k=a[k];
			work(k);
			assert(order.back()==k); // by definition of work()
		}while(k!=j);

		for(int i=1; i<(int)order.size(); ++i){
			b[order[i-1]]=order[i];
		}
		b[order.back()]=order[0];
	}

	//for(auto x: b) std::cout<<x+1<<' ';
	int k=0;
	for(int i=0; i<n; ++i)
		k+=a[i]==b[i];
	std::cout<<k<<'\n';

	for(int i=0; i<n; ++i)
		std::cout<<b[i]+1<<' ';
	std::cout<<'\n';

}