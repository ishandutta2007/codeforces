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
	int number, p, period; std::cin>>number>>p>>period;
	--p;
	std::string s; s.reserve(number); std::cin>>s;
	assert((int)s.size()==number);
	int timeAdd, timeShift; std::cin>>timeAdd>>timeShift;
	std::vector<int> value(number);
	int result=INT_MAX;
	for(auto index=number; index--;){
		value[index]=(index+period>=number ? 0: value[index+period])+(s[index]=='0')*timeAdd;
		if(index>=p)
			result=std::min(result, value[index]+timeShift*(index-p));
		else break;
	}
	std::cout<<result<<'\n';

}