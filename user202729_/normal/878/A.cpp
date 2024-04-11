// *try to <del>punish myself for being lazy</del>make up for the wasted time by doing virtual contest*
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	using T=std::array<char, 2>;
	std::array<T, 10> value;
	for(int index=0; index<(int)value.size(); ++index)
		value[index]={{0, 1}};

	int number; std::cin>>number;
	for(int _=0; _<number; ++_){
		char type; int cur; std::cin>>type>>cur;
		switch(type){
			case'&':
				for(int index=0; index<(int)value.size(); ++index)
					for(int oldValue=0; oldValue<2; ++oldValue)
						value[index][oldValue]&=cur>>index&1;
				break;
			case'|':
				for(int index=0; index<(int)value.size(); ++index)
					for(int oldValue=0; oldValue<2; ++oldValue)
						value[index][oldValue]|=cur>>index&1;
				break;
			case'^':
				for(int index=0; index<(int)value.size(); ++index)
					for(int oldValue=0; oldValue<2; ++oldValue)
						value[index][oldValue]^=cur>>index&1;
				break;
			default:
				assert(false); __builtin_unreachable();
		}
	}

	std::cout<<"3\n";
	int cur=1023;
	for(int index=0; index<(int)value.size(); ++index){
		cur^=(value[index]==T{{0, 0}})<<index;
	}
	std::cout<<"& "<<cur<<'\n';

	cur=0;
	for(int index=0; index<(int)value.size(); ++index){
		cur|=(value[index]==T{{1, 1}})<<index;
	}
	std::cout<<"| "<<cur<<'\n';

	cur=0;
	for(int index=0; index<(int)value.size(); ++index){
		cur|=(value[index]==T{{1, 0}})<<index;
	}
	std::cout<<"^ "<<cur<<'\n';

}