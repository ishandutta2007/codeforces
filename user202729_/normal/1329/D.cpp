// might be TLE-hackable (if this solution passes the existing test cases)
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>



void up(){
	std::string string; std::cin>>string;
	for(auto & ch: string) ch=char(ch-'a');

	struct Count{
		std::array<int, 26> value;
		std::multiset<int> values;
		int total;

		Count(): value{}, values(begin(value),end(value)), total(0){}

		int operator[](int it)const{ return value[it]; }
		void change(int it, int delta){
			values.erase(values.find(value[it]));
			values.insert(value[it]+=delta);
			total+=delta;
		}

		__attribute__((pure)) int top(int index=0) const{ // index==0: get max value, index==1: get second max value, etc.
			return *std::next(values.rbegin(), index);
		}

		// only works when numOperation>=1
		__attribute__((pure)) int numOperation() const{
			return 2*top()<=total ? (total+3)/2 : top()+1;
		}
	} count;

	struct Segment{
		char first, last;
		int len;
	};

	//using Operations=std::vector<std::pair<int, int>>;
	//Operations operations;
	struct TwoStack{
		std::vector<Segment> left, right;
		int leftLen=0;

		void addLeft(Segment segment){
			check();
			left.push_back(segment);
			leftLen+=segment.len;
			check();
		}

		void moveLeft(){
			check();
			leftLen+=right.back().len;
			left.push_back(right.back());
			right.pop_back();
			check();
		}
		void moveRight(){
			check();
			leftLen-=left.back().len;
			right.push_back(left.back());
			left.pop_back();
			check();
		}

		// reverse if factor==-1
		void modifyCountIfDeleteLeft(Count& count, int factor=1)const{
			count.change(left.back().first, -1*factor);
			if(left.back().first!=left.back().last)
				count.change(left.back().last, -1*factor);
			check();
		}

		// if merge, the merged segment will be left on the left stack
		void deleteLeft(bool merge){
			check();

			assert(left.size()>=2);
			assert(merge==(left.back().first!=left.back().last));

			auto const oldLeftLen=leftLen;
			leftLen-=left.back().len;
			std::cout<<leftLen+1<<' '<<oldLeftLen<<'\n';

			assert(left.back().first==left.end()[-2].last);
			assert(left.back().last==right.back().first);
			left.pop_back();

			assert(merge==(left.back().last!=right.back().first));
			if(merge){
				left.back().len+=right.back().len;
				leftLen+=right.back().len;
				left.back().last=right.back().last;
				right.pop_back();
			}

			check();
		}
		void deleteLeft(){
			deleteLeft(left.back().first!=left.back().last);
		}

		void check() const{
			assert(leftLen==std::accumulate(begin(left),end(left), 0,[&](auto result, auto segment){
				return result+segment.len;
			}));
		}
	} stacks;

	for(int index=1, last=0; index<=(int)string.size(); ++index)
		if(index==(int)string.size() or string[index]==string[index-1]){
			if(index!=(int)string.size()) count.change(string[index], 1);
			stacks.addLeft({string[last], string[index-1], index-last});
			last=index;
		}

	std::cout<<count.numOperation()<<'\n';
	for(int numOperationLeft=count.numOperation(); numOperationLeft-->0;){
		assert(count.numOperation()==numOperationLeft+1);
		if(count.numOperation()>=int(stacks.left.size()+stacks.right.size())) break;

		while(stacks.left.size()<2) stacks.moveLeft();
		if(stacks.right.empty()) stacks.moveRight();

		// complexity unproven
		while(stacks.left.size()>=2){
			stacks.modifyCountIfDeleteLeft(count);
			if(count.numOperation()==numOperationLeft){
				stacks.deleteLeft();
				goto nextOperation;
			}
			stacks.modifyCountIfDeleteLeft(count, -1);
			stacks.moveRight();
		}

		while(true){
			stacks.moveLeft();
			stacks.modifyCountIfDeleteLeft(count);
			if(count.numOperation()==numOperationLeft){
				stacks.deleteLeft();
				goto nextOperation;
			}
			stacks.modifyCountIfDeleteLeft(count, -1);
		}

nextOperation:
		assert(count.numOperation()==numOperationLeft);
	}

	while(not stacks.right.empty()) stacks.moveLeft();
	assert(count.numOperation()==(int)stacks.left.size());
	for(auto it: stacks.left) std::cout<<"1 "<<it.len<<'\n';
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}