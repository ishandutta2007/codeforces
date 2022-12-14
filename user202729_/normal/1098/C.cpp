// wrong logic :(

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode; int64_t value; std::cin>>numNode>>value;
	if(value>numNode*int64_t(numNode+1)/2 or value<numNode*2-1){ std::cout<<"No\n"; return 0; }
	if(value==numNode*int64_t(numNode+1)/2){ // b==1
		std::cout<<"Yes\n";
		for(int node=1;node<numNode;++node) std::cout<<node<<' ';
		std::cout<<'\n';
		return 0;
	}

	auto const generateValues=[numNode](int b){
		std::vector<int> values{1}; // number of nodes at each depth
		for(int left=numNode-1; left;){
			auto const tmp=(int)std::min((int64_t)values.back()*b, (int64_t)left);
			values.push_back(tmp); left-=tmp;
		}
		return values;
	};

	auto const computeValue=[](std::vector<int> const& values){
		int64_t result=0;
		for(int index=0;index<(int)values.size();++index)
			result+=values[index]*int64_t(index+1);
		return result;
	};

	int b=numNode-1;
	for(int step=1<<25; step; step>>=1) if(b-step>=2){
		b-=step;
		auto const values=generateValues(b);
		if(computeValue(values)>value) b+=step;
	}

	auto values=generateValues(b);

	int64_t missingValue=value-computeValue(values);
	assert(missingValue>=0);

	values.reserve(numNode); // optional
	auto layer=(int)values.size()-1;
	while(missingValue){
		while(values[layer]==1) --layer;
		if((int)values.size()-layer<=missingValue){
			// run at most numNode times
			missingValue-=(int)values.size()-layer;
			--values[layer];
			values.push_back(1);
		}else{
			--values[layer];
			++values[layer+missingValue];
			break;
		}
	}

	assert(std::accumulate(begin(values),end(values), 0)==numNode);
	assert(computeValue(values)==value);
	assert(values[0]==1);
	/*
	for(int index=1;index<(int)values.size();++index){
		assert(values[index]!=0);
		assert((int64_t)values[index-1]*b>=values[index]);
	}
	*/

	int node=1, lastCount=1;
	std::cout<<"Yes\n";
	std::for_each(1+begin(values),end(values),[&](auto count){
		auto curPar=node;
		assert((int64_t)lastCount*b>=count);

		int curDegree=0;
		for(int _=0;_<count;++_) {
			if(curDegree==b){ curDegree=0; ++curPar; }
			std::cout<<curPar<<' ';
			++curDegree;
		}
		node+=lastCount;
		lastCount=count;
	});
	std::cout<<'\n';
}