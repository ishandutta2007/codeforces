// time-limit: 1000
// problem-url: https://codeforces.com/contest/1572/problem/B
#if not LOCAL
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
	int number; std::cin>>number;
	std::vector<int> data(number);
	for(auto& it: data) {
		std::cin>>it;
	}
	
	{
		int numOne=std::accumulate(begin(data), end(data), 0);
		if(numOne%2!=0){
			std::cout<<"NO\n"; return;
		}
		if(numOne==0){
			std::cout<<"YES\n0\n";
			return;
		}
	}

	std::vector<int> ops;
	auto const op=[&](int i){
		ops.push_back(i);
		data[i]=data[i+1]=data[i+2]=
		data[i]^data[i+1]^data[i+2];
	};

	auto const processSegment=[&](int left, int right){
		assert(data[left]); assert(data[right]);
		assert(left<right);
		if((right-left)%2==0){
			for(int j=left; j<right; j+=2) op(j);
			for(int j=right-4; j>=left; j-=2) op(j);
		}
		else if(left>0 and data[left-1]==0){
			for(int j=left; j<right-1; j+=2) op(j);
			for(int j=left-1; j<right-1; j+=2) op(j);
		}
		else if(right+1<number and data[right+1]==0){
			for(int j=left; j<right-1; j+=2) op(j);
			for(int j=right-1; j>=left; j-=2) op(j);
		}else{
			return;
		}

		for(int j=left; j<=right; ++j) assert(data[j]==0);
	};

	int last=-1;
	for(int i=0; i<number; ++i){
		if(data[i]){
			if(last==-1){
				last=i;
			}else{
				processSegment(last, i);
				last=-1;
			}
		}
	}
	assert(last==-1);
	for(int i=number; i--;){
		if(data[i]){
			if(last==-1){
				last=i;
			}else{
				processSegment(i, last);
				last=-1;
			}
		}
	}
	assert(last==-1);
	if(ops.empty()){
		std::cout<<"NO\n"; return;
	}

	std::cout<<"YES\n";

	for(auto x: data) assert(x==0);
	assert((int)ops.size()<=number);
	std::cout<<ops.size()<<'\n';
	for(auto x: ops) std::cout<<x+1<<' ';
	std::cout<<'\n';
		
}