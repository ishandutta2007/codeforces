#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int n;
std::vector<std::pair<long long, int> > events;
std::vector<long long> answers;

void answer(){
	std::sort(events.begin(), events.end());
	int have = 0;
	auto it = events.begin();
	long long last = -1;
	while(it != events.end()){
		long long now = it->first;
		answers[have] += now - last;
		last = it->first;
		while(it != events.end() && it->first == now){
			have += it->second;
			it++;
		}
		if(it == events.end()) break;
	}
	for(int i = 1; i <= n; ++i){
		std::cout << answers[i] << " ";
	}
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	answers.resize(n+1);
	for(int i = 0; i < n; ++i){
		long long a, b;
		std::cin >> a >> b;
		events.push_back(std::make_pair(a, 1));
		events.push_back(std::make_pair(b+1, -1));
	}
}

int main(){
	read();
	answer();
	return 0;
}