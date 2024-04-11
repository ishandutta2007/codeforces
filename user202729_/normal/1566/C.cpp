// time-limit: 1000
// problem-url: https://codeforces.com/contest/1566/problem/C

// ... I forgot that real contest submissions are heavily prioritized
// virtual long queue

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
	std::string a; std::cin>>a;
	std::string b; std::cin>>b;
	int last=-1;
	// magic code below
	int result {};
	for(int index=0; index<number; ++index){
		auto const tmp=a[index]+b[index]-'0'-'0';
		if(tmp==1){
			result+=2;
			last=-1;
		}else if(last<0 or last==tmp){
			last=tmp;
			result+=not tmp;
		}else{
			result+=not tmp;
			result++;
			last=-1;
		}
	}
	std::cout<<result<<'\n';
}