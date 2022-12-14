// more optimization (not benchmarked)




#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;
std::vector<int> value;
int threshold; // consider the case when only nodes >=threshold can be chosen
int numOkay; void setNumOkay(){ numOkay=(int)std::count_if(begin(value), end(value),[&](auto it){return it>=threshold;}); }
int result; // maximum number of elements that can be inspected (with result >=threshold)


void removeParentEdge(int node){
	for(int child: add[node]) {
		std::swap(add[child].back(), *std::find(begin(add[child]), end(add[child]), node));
		add[child].pop_back();
		removeParentEdge(child);
	}
}

struct WorkResult{
	int numOkayInside;
	int subsize;
	int value; // ???
};

template<bool nodeOkay=true> WorkResult work(int node){
	auto const nodeOkay_=value[node]>=threshold;
	if(nodeOkay_!=nodeOkay) return work<not nodeOkay>(node);


	WorkResult r{};
	r.numOkayInside=nodeOkay;
	r.subsize=1;
	r.value=0;

	std::array<int, 2> branchValues{}; // 0: no branch chosen

	auto const insertBranchValue=[&](int value){
		if(not nodeOkay) return;
		if(value>branchValues[0]) {
			branchValues[0]=value;
			if(value>branchValues[1]) std::swap(branchValues[0], branchValues[1]);
		}
	};

	int curWhiteValue{}; // sum of sizes of completely white subtree around this node

	for(int child: add[node]) {
		auto tmp=work(child);
		r.numOkayInside+=tmp.numOkayInside;
		r.subsize+=tmp.subsize;

		auto branchValue=tmp.value;

		if(tmp.numOkayInside==tmp.subsize){
			curWhiteValue+=tmp.subsize;
			branchValue-=tmp.subsize;
		}

		insertBranchValue(branchValue);
	}

	if(not nodeOkay){
		r.value=0;
		return r;
	}

	//if(r.numOkayInside==r.subsize){ }

	r.value=branchValues[1]+curWhiteValue+1;

	if(numOkay-r.numOkayInside==(int)add.size()-r.subsize){
		curWhiteValue+=(int)add.size()-r.subsize;
	}
	result=std::max(result, curWhiteValue+branchValues[0]+branchValues[1]+1);

	return r;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int number, numInspect; std::cin>>number>>numInspect;
	value.resize(number);for(auto & it: value) std::cin>>it;

	add.resize(number);
	for(int _=0; _<number-1; ++_){
		int first, sec; std::cin>>first>>sec;
		add[--first].push_back(--sec);
		add[sec].push_back(first);
	}

	std::vector<int> valueSorted=value;
	std::sort(begin(valueSorted), end(valueSorted));

	removeParentEdge(0);

	assert([&]{
		threshold=INT_MIN; // allow all nodes
		setNumOkay();
		result=-1;
		work(0);
		return result==number;
	}());


	std::cout<<*std::upper_bound(valueSorted.rbegin(), valueSorted.rend(), std::monostate{},[&](std::monostate, auto threshold_){
		threshold=threshold_;
		setNumOkay();
		if(numOkay<numInspect) return false;
		result=-1;
		work(0);
		return result>=numInspect;
	})<<'\n';
}