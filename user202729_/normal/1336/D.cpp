// unproven (both correctness and time complexity)
// <-  use a pattern observed from a brute force program
// stress-tested

// (the queries in the last implementation was wrong. Fortunately it doesn't take much effort to fix)

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int number;
std::vector<int> count, products;

struct DoneException{};
std::vector<int> value;

bool checkBefore(int index){
	if(index==3)
		return products[0]==value[1]*value[2] and products[3]==(value[1]+1)*(value[2]+1);
	else if(index==4)
		return products[1]==value[2]*(value[0]+1+value[3]);
	else if(index>=5)
		return products[index==5 ? 2: index-2]==
				(value[index-4]+1)*(value[index-5]+1+value[index-2])+value[index-2]*value[index-1];
	else
		return true;
}

void backtrack(int index){
	if(not checkBefore(index)) return;
	
	if(index==number-1){
		auto const a=products.end()[number==4 ? -2: -1], b=value.end()[-3]+1;
		assert(a%b==0);
		value.back()=a/b-(value.end()[-4]+1);

		assert(value.back()>=0);

		if(not checkBefore(number)) return;
		throw DoneException{};
	}

	if(count[index]!=1){
		assert(value[index]==count[index]);
		backtrack(index+1);
	}else{
		value[index]=0; backtrack(index+1);
		value[index]=1; backtrack(index+1);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>number;
	std::cout<<
		"+ 1\n"
		"+ 2\n"
		"+ 3\n"
		"+ 1\n";
	for(int x=4;x<number;++x)
		std::cout<<"+ "<<x<<'\n';

	std::cout<<std::flush;

	products.resize(number);
	count.resize(number);
	int lastTrip, lastStraight;
	std::cin>>lastTrip>>lastStraight;

	for(int index=0;index<number;++index) {
		int trip, straight; std::cin>>trip>>straight;
		int deltaTriple;
		std::tie(lastTrip, deltaTriple, lastStraight, products[index])=std::make_tuple(
				trip, trip-lastTrip, straight, straight-lastStraight);

		int countPrevious=1;
		auto const f=[&](int x){ return x*(x-1)*(x-2)/6; };
		for(int step=1<<10; step; step>>=1){
			countPrevious+=step;
			if(f(countPrevious+1)-f(countPrevious)>deltaTriple)
				countPrevious-=step;
		}
		assert(f(countPrevious+1)-f(countPrevious)==deltaTriple);
		assert(countPrevious!=0); // 0 and 1 are indistinguishable
		count[index]=countPrevious;
	}

	assert(count[0]==std::max(1, count[3]-1));
	count[0]=count[3]-1;
	count.erase(count.begin()+3);

	value.reserve(number); value=count; value.push_back(-1);
	try{
		backtrack(1); // value[0] must be correct
	}catch(DoneException){
		std::cout<<'!';
		for(auto it: value) std::cout<<' '<<it;
		std::cout<<'\n';
		return 0;
	}
	assert(false);
}