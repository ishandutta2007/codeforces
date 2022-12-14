// ......



#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int number, value, valueSpecial;

int countSpecialMod2(auto predicate){
	unsigned count{};
	for(int i=1; i<=number; ++i)
		count+=(bool)predicate(i);

	if(count==0) return 0;

	std::cout<<"? "<<count;
	for(int i=1; i<=number; ++i)
		if(predicate(i))
			std::cout<<' '<<i;
	std::cout<<std::endl;

	int result; std::cin>>result;
	if(result<0) std::exit(0);

	int tmp=(count%2)*value;
	if(result==tmp) return 0;
	else{
		assert(result==(tmp^value^valueSpecial));
		return 1;
	}
}


int work(int fixed, int fixValue){
	assert((fixValue&fixed)==fixValue);
	auto const firstNotFixed=1<<__builtin_ctz(~fixed);
	if(fixed and firstNotFixed>=number){
		if(fixValue==0) fixValue+=firstNotFixed;
		return fixValue;
	}

	if(not countSpecialMod2([&](int it){
		return (it&(fixed|firstNotFixed))==fixValue;
	}))
		fixValue|=firstNotFixed;

	return work(fixed|firstNotFixed, fixValue);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>number>>value>>valueSpecial;

	int bit=0;
	while(countSpecialMod2([&](int it){
		return (it&(1<<bit))!=0;
	})==0)++bit;
	auto a=work(1<<bit, 0);
	auto b=work((1<<(bit+1))-1, (a&((1<<bit)-1))|(1<<bit));

	assert(a!=b);
	if(a>b) std::swap(a, b);

	std::cout<<"! "<<a<<' '<<b<<'\n';
}