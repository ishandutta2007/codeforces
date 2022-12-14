// time-limit: 1000
// problem-url: https://codeforces.com/contest/1621/problem/C

// hurry up

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
	auto const ask=[&](int pos){
		std::cout<<"? "<<pos+1<<std::endl;
		int result; std::cin>>result;
		return result-1;
	};

	//int queryIndex=0;
	std::vector<int> result(number, -1);
	int pos=0;

	while(true){
		while(true){
			if(pos==number) goto break_outer;
			if(result[pos]<0) break;
			pos++;
		}

		assert(result[pos]==-1);
		int initial=ask(pos);
		std::vector<int> cycle{initial};
		do cycle.push_back(ask(pos)); while(cycle.back()!=initial);

		for(int index=1; index<(int)cycle.size(); ++index)
			result[cycle[index-1]]=cycle[index];

		//queryIndex+=(int)cycle.size();
	}
break_outer:

	std::cout<<'!';
	for(auto x: result) std::cout<<' '<<x+1;
	std::cout<<std::endl; // ... this is required?
}