#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <utility>

#define PR std::pair
#define X first
#define Y second

int MAXVAL = 1000000;
int n, m;
std::set<int> primes;
// output
long long sp, mst;
std::vector<PR<int, int> > edges;
std::vector<int> weights;

void calc_primes(){
	std::vector<int> visited(MAXVAL, false);
	for(int i = 2; i < MAXVAL; ++i){
		if(!visited[i]){
			for(int j = i; j < MAXVAL; j+=i)
				visited[j] = true;
			primes.insert(i);
		}
	}
}

void answer(){
	if(n == 2){
		std::cout << "2 2\n1 2 2";
		return;
	}
	sp = mst = 0;
	edges.push_back({1, n});
	weights.push_back(2);
	sp = 2;
	mst = 2;
	m--;
	for(int i = n; i > 2; --i){
		edges.push_back({i, i-1});
		weights.push_back(2);
		mst += 2;
		m--;
	}
	long long bigger = 2;
	while(primes.find(mst) == primes.end()){
		mst++;
		weights.back()++;
		bigger++;
	}
	bigger++;
	for(int j = 2; j < n; ++j){
		if(m == 0) break;
		edges.push_back({1, j});
		weights.push_back(bigger);
		m--;
	}
	for(int i = 2; i <= n; ++i){
		for(int j = i+2; j <= n; ++j){
			if(m == 0) break;
			edges.push_back({i, j});
			weights.push_back(bigger);
			m--;
		}
		if(m == 0) break;
	}
	std::cout << sp << " " << mst << "\n";
	for(int i = 0; i < edges.size(); ++i){
		std::cout << edges[i].X << " " << edges[i].Y << " " <<  weights[i] << "\n";
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	calc_primes();
	answer();
	return 0;
}