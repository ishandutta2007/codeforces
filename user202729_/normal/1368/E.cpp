// proven (computer-assisted)
// I guess this is the intended solution. The 4/7 factor definitely doesn't come out from nowhere.
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int number, numEdge; std::cin>>number>>numEdge;
	std::vector<std::vector<int>> add(number);
	for(int _=0; _<numEdge; ++_){
		int first, sec; std::cin>>first>>sec;
		add[--first].push_back(--sec);
		assert(first<sec);
	}

	for(auto const& it: add) assert(it.size()<=2);
	
	using Mask=std::bitset<7>;
	std::vector<Mask> universes(number);
	std::array<int, 7> size{};
	for(auto node=number; node--;){
		Mask first, firstBad, sec, secBad;
		auto const process=[&](Mask& have, Mask& bad, int node){
			have=universes[node];
			for(auto other: add[node]) bad|=have&universes[other];
		};
		if(add[node].size()>=1) process(first, firstBad, add[node][0]);
		if(add[node].size()>=2) process(sec, secBad, add[node][1]);

		Mask& result=universes[node]=~(first|sec);
		auto const b=first&~firstBad&~sec;
		auto const d=sec&~secBad&~first;
		auto const e=(first&~firstBad)&(sec&~secBad);
		if((Mask{}!=b)+(Mask{}!=d)>(Mask{}!=e)){
			if(Mask{}!=b) result[b._Find_first()]=true;
			if(Mask{}!=d) result[d._Find_first()]=true;
		}else{
			if(Mask{}!=e) result[e._Find_first()]=true;
		}

		assert(result.count()>=3);
		for(int i=0; result.count()>3;++i) result[i]=false;
		for(int i=0; i<(int)size.size(); ++i)
			size[i]+=result[i];
	}

	auto const slot=int(std::max_element(begin(size), end(size))-size.begin());
	assert(size[slot]*7>=number*3);
	std::cout<<number-size[slot]<<'\n';
	for(int node=0; node<number; ++node)
		if(not universes[node][slot])
			std::cout<<node+1<<' ';
	std::cout<<'\n';


		

}