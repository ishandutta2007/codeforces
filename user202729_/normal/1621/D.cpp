// time-limit: 1000
// problem-url: https://codeforces.com/contest/1621/problem/D

// did cpb recently change to name the file with the long name...?
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
	int64_t part1 {}; int part2=INT_MAX;
	for(int row=0; row<number*2; ++row)
		for(int col=0; col<number*2; ++col){
			int value; std::cin>>value;
			if(row>=number and col>=number) part1+=value;
			else if((row>=number or col>=number) and(
						(row==0 or row==number-1 or row==number or row==number*2-1) and
						(col==0 or col==number-1 or col==number or col==number*2-1)
						)) part2=std::min(part2, value);
		}
	std::cout<<part1+part2<<'\n';
}