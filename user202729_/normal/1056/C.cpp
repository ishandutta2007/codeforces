// >.<

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<int> power;
std::vector<int> pair; // the other index, or -1

/*
bool anyLeft(){
	return std::any_of(begin(power), end(power),[&](auto it){
		return it>=0;
	});
}
*/

int numLeft;

void move(int index){
	std::cout<<index+1<<std::endl;
	assert(power[index]>=0);
	power[index]=-1;--numLeft;
}

int play();
int judgePlay(int expect=-1){
	assert(numLeft==(int)std::count_if(begin(power), end(power),[&](auto it){return it>=0;}));
	if(numLeft==0) return 0;

	int index; std::cin>>index;--index;
	if(expect>=0 and expect!=index)
		return 1;
	if(index==-1)
		return 0;

	assert(power[index]>=0);
	power[index]=-1;--numLeft;

	if(pair[index]>=0 and power[pair[index]]>=0){
		if(numLeft==0) return 0;
		move(pair[index]);
		return judgePlay();
	}else{
		return play();
	}
}
int play(){
	assert(numLeft==(int)std::count_if(begin(power), end(power),[&](auto it){return it>=0;}));
	if(numLeft==0) return 0;
	for(int index=0; index<(int)power.size(); ++index)
		if(power[index]>=0 and pair[index]>=0 and power[pair[index]]>=0 and power[index]>=power[pair[index]]){
			move(index);
			return judgePlay(pair[index]);
		}

	move(int(std::max_element(begin(power), end(power))-power.begin()));
	return judgePlay();
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numPair; std::cin>>number>>numPair;
	power.resize(number*2);
	for(auto& it: power) std::cin>>it;
	pair.assign(number*2, -1);
	for(int _=0; _<numPair; ++_){
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		assert(pair[first]==-1); assert(pair[sec]==-1);
		pair[first]=sec; pair[sec]=first;
	}
	numLeft=number*2;

	int turn; std::cin>>turn;
	if(turn==1) return play(); else return judgePlay();
}