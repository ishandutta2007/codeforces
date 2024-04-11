#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

#define PR std::pair
#define X first
#define Y second

const int INF = 2e9;

int n, k;
std::vector<std::vector<PR<int, int> > > g;

bool check(int M){
	std::stack<int> stack;
	std::vector<int> size(n, 0);
	std::vector<bool> cut(n, false);
	std::vector<int> d(n, 0);
	for(int i = 0; i < n; ++i){
		if(g[i].size() == 1) stack.push(i);
		size[i] = g[i].size();
	}
	int cuts = 0;
	while(!stack.empty()){
		int cur = stack.top();
		stack.pop();
		int parent = -1;
		int cost = 0;
		for(auto &ch : g[cur]){
			if(!cut[ch.X]){
				parent = ch.X;
				cost = ch.Y;
			}
		}
		if(d[cur] + cost > M) continue;
		if(parent != -1)
			d[parent] = std::max(d[parent], d[cur] + cost);
		cut[cur] = true;
		if(parent != -1)
			size[parent]--;
		cuts++;
		if(parent != -1 && size[parent] == 1) stack.push(parent);
	}
	int left = n - cuts;
	//std::cout << M << " " << left << std::endl;
	if(left <= 1) return true;
	if(left > k) return false;
	// simple check
	for(int i = 0; i < n; ++i){
		if(!cut[i]){
			stack.push(i);
			break;
		}
	}
	while(!stack.empty()){
		int cur = stack.top();
		stack.pop();
		if(size[cur] >= 3) return false;
		cut[cur] = true;
		for(auto &ch : g[cur]){
			if(!cut[ch.X]){
				stack.push(ch.X);
			}
		}
	}
	return true;
}

void answer(){
	int left = 0, right = 1e9+1e4;
	int good = -1;
	while(left <= right){
		int mid = (left+right)>>1;
		if(check(mid)){
			good = mid;
			right = mid-1;
		}else{
			left = mid+1;
		}
	}
	std::cout << good << "\n";
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	g.resize(n);
	for(int i = 0; i < n-1; ++i){
		int a, b, w;
		std::cin >> a >> b >> w;
		a--;b--;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
}

int main(){
	read();
	answer();
	return 0;
}