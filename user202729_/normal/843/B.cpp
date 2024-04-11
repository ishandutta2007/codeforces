#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


std::mt19937 engine(
#if LOCAL
		123456
#else
		std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count()
#endif
		);

std::pair<int, int> ask(int index){
	std::cout<<"? "<<index+1<<std::endl;
	int value, next; std::cin>>value>>next;
	next--;
	return {value, next};
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, start, target; std::cin>>number>>start>>target;
	--start;

	std::vector<int> indices(number);
	std::iota(begin(indices), end(indices), 0);
	std::shuffle(begin(indices), end(indices), engine);
	std::swap(*std::find(begin(indices), end(indices), start), indices[0]);

	std::pair<int, int> best{INT_MIN, INT_MIN};
	for(int i=0; i<std::min((int)indices.size(), 1000);++i){
		auto tmp=ask(indices[i]);
		if(tmp.first<=target or best.first==INT_MIN)
			best=std::max(best, tmp);
	}

	assert(indices[0]==start);
	assert(best.first!=INT_MIN);

	while(best.first<target and best.second>=0)
		best=ask(best.second);

	if(best.first<target and best.second<0)
		std::cout<<"! -1\n";
	else
		std::cout<<"! "<<best.first<<'\n';

}