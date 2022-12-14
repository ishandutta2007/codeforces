// time-limit: 2000
// problem-url: https://codeforces.com/contest/1615/problem/C
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
	std::string a, b; std::cin>>a>>b;
	assert((int)a.size()==number);
	assert((int)b.size()==number);

	auto const sumA=std::accumulate(begin(a), end(a), 0)-'0'*number;
	auto const sumB=std::accumulate(begin(b), end(b), 0)-'0'*number;
	if(a==b){
		std::cout<<"0\n"; return;
	}
	if(sumA==0 or sumB==0){
		std::cout<<"-1\n"; return;
	}
	if(not(sumA==sumB or sumA==number+1-sumB)){
		std::cout<<"-1\n"; return;
	}

	int result=INT_MAX;
	if(sumA==sumB){
		int numDiff=0;
		for(int index=0; index<number; ++index)numDiff+=a[index]!=b[index];
		result=std::min(result, numDiff);
	}
	if(sumA==number+1-sumB){
		int numEqual=0;
		for(int index=0; index<number; ++index)numEqual+=a[index]==b[index];
		result=std::min(result, numEqual);
	}
	std::cout<<result<<'\n';
		


	
}

// hopefully correct again, but this one I'm pretty confident with