#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numEdge; std::cin>>number>>numEdge;
	std::vector<std::vector<int>> add(number);
	std::vector<std::vector<int>> rad(number);
	for(int _=0;_<numEdge;++_) {
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		add[first].push_back(sec);
		rad[sec].push_back(first);
	}

	int pathLen; std::cin>>pathLen;
	std::vector<int> path(pathLen);
	for(auto & x: path){
		std::cin>>x;
		--x;
	}

	std::vector<int> distance(number, -1); // distance[x] = minimum len (x .. t)
	{
		std::vector<int> queue;
		queue.reserve(number);
		queue.push_back(path.back());
		distance[path.back()]=0;
		for(auto iterator=begin(queue); iterator!=end(queue);++iterator){
			auto const node=*iterator;
			auto const nextDistance=distance[node]+1;
			for(auto other: rad[node]) if(distance[other]<0){
				distance[other]=nextDistance;
				assert(nextDistance>=0);
				queue.push_back(other);
				assert(queue.size()<=number);
			}
		}
	}

	int minimum=0, maximum=0;
	for(int index=0;index<(int)path.size()-1;++index) {
		auto const cur=path[index], next=path[index+1];
		if(distance[next]!=distance[cur]-1){
			++minimum;++maximum;
		}else if(std::any_of(begin(add[cur]),end(add[cur]),[&](auto x){
			return x!=next and distance[x]==distance[cur]-1;
		}))
			++maximum;
	}
	std::cout<<minimum<<' '<<maximum<<'\n';
}