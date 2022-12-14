// :( (at least I didn't read the solution)
// proven correct

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

#ifdef LOCAL
int const MAXVALUE=2000, MAXSTEP=6;
#else
int const MAXVALUE=1000000, MAXSTEP=19;
#endif

auto const minFactor=[]{
	std::vector<int> minFactor(MAXVALUE+1);
	for(int prime=2;prime<(int)minFactor.size();++prime) if(minFactor[prime]==0){
		minFactor[prime]=prime;
		if((int64_t)prime*prime<(int64_t)minFactor.size())
			for(int multiple=prime*prime;multiple<(int)minFactor.size(); multiple+=prime) 
				if(minFactor[multiple]==0) minFactor[multiple]=prime;
	}
	return minFactor;
}();

auto const primes=[]{
	std::vector<int> primes;
	for(int prime=2;prime<200;++prime) if(minFactor[prime]==prime)
		primes.push_back(prime);
	return primes;
}();

std::vector<std::vector<char>> masks; // actually this should be called "exponent sequence"...

void generate(std::vector<char> mask, int maxExponent=99, int maxValue=MAXVALUE, int numExtra=MAXSTEP){
	masks.push_back(mask);
	auto const prime=primes[mask.size()]; mask.push_back(0);
	while(mask.back()<maxExponent){
		maxValue/=prime;
		if(maxValue==0){
			if(numExtra==0) return;
			--numExtra;
		}
		++mask.back();
		generate(mask, mask.back(), maxValue, numExtra);
	}
}


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	generate({});

	std::sort(begin(masks),end(masks));
	std::vector<std::vector<int>> add(masks.size());

	std::vector<int> numFactor(masks.size());
	for(int index=0;index<(int)masks.size();++index) {
		auto mask=masks[index];

		numFactor[index]=1;for(auto it: mask) numFactor[index]*=it+1;

		if(mask.empty()) continue;

		for(int i=0;i<(int)mask.size()-1;++i) if(mask[i]>mask[i+1]){
			--mask[i];
			auto const other=std::lower_bound(begin(masks),end(masks), mask)-begin(masks);
			add[index].push_back(other); add[other].push_back(index);
			++mask[i];
		} else assert(mask[i]==mask[i+1]);

		if(0==--mask.back()) mask.pop_back();
		auto const other=std::lower_bound(begin(masks),end(masks), mask)-begin(masks);
		add[index].push_back(other); add[other].push_back(index);
	}

	auto const getIndex=[&](int value){
		std::vector<char> mask;
		while(value!=1){
			int prime=minFactor[value]; mask.push_back(0);
			do{ value/=prime; ++mask.back(); }while(value%prime==0);
		}
		std::sort(begin(mask),end(mask), std::greater<>());
		return int(std::lower_bound(begin(masks),end(masks), mask)-begin(masks));
	};


	int numTest; std::cin>>numTest;
	std::vector<std::pair<int, int>> queries(numTest);
	std::set<int> used;
	for(auto & it: queries){
		int first, sec; std::cin>>first>>sec;
		assert(std::max(first, sec)<=MAXVALUE);
		it={first=getIndex(first), sec=getIndex(sec)};
		used.insert(first); used.insert(sec);
	}

	assert(used.size()<=289);

	std::vector<int> numFactorValues=numFactor;
	std::sort(begin(numFactorValues),end(numFactorValues));
	numFactorValues.erase(std::unique(begin(numFactorValues),end(numFactorValues)), end(numFactorValues));
	for(auto & it: numFactor)
		it=int(std::lower_bound(begin(numFactorValues),end(numFactorValues), it)-begin(numFactorValues));


	std::vector<int> usedV(begin(used),end(used)); used.clear();
	std::vector<std::vector<int>> distance(usedV.size());

	std::vector<int> curDistance;
	std::vector<int> queue;
	for(int index=0;index<(int)usedV.size();++index) {
		// BFS from usedV[index], store to distance[index]
		curDistance.assign(masks.size(), INT_MAX);
		distance[index].assign(numFactorValues.size(), INT_MAX);
		queue.clear();

		auto const update=[&](int node, int distance_){
			assert(curDistance[node]==INT_MAX);
			curDistance[node]=distance_;
			auto& it=distance[index][/*compressed*/ numFactor[node]]; it=std::min(it, distance_);
			queue.push_back(node);
		};
		update(usedV[index], 0);

		for(int i=0;i<(int)queue.size();++i) {
			auto const node=queue[i];
			for(auto other: add[node]) if(curDistance[other]==INT_MAX)
				update(other, curDistance[node]+1);
		}
	}

	for(auto [first, sec]: queries){
		first=std::lower_bound(begin(usedV),end(usedV), first)-begin(usedV);
		sec=std::lower_bound(begin(usedV),end(usedV), sec)-begin(usedV);
		int result=INT_MAX;
		for(int index=0;index<(int)numFactorValues.size();++index) {
			result=std::min(result, distance[first][index]+distance[sec][index]);
		}
		std::cout<<result<<'\n';
	}
}