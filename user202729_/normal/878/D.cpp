#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numCharacteristic, numCreature, numQuery;
	std::cin>>numCharacteristic>>numCreature>>numQuery;

	std::vector<std::vector<int>> characteristic(numCharacteristic, std::vector<int>(numCreature));
	for(int creature=0; creature<numCreature; ++creature)
		for(auto& it: characteristic)
			std::cin>>it[creature];

	using T=std::bitset<1<<12>;
	std::vector<T> value(numCreature); // value[creatureIndex][initial creature characteristic value mask]
	for(int index=0; index<numCreature; ++index)
		for(int mask=0; mask<(1<<numCreature); ++mask)
			value[index][mask]=mask>>index&1;

	for(int _=0; _<numQuery; ++_){
		char type; int first, sec; std::cin>>type>>first>>sec;
		--first;--sec;
		switch(type){
			case '1':
				value.push_back(value[first]|value[sec]);
				break;
			case '2':
				value.push_back(value[first]&value[sec]);
				break;
			case '3':
				{
					auto const curValue=characteristic[sec];
					auto const curResult=value[first];

					int result{};
					for(auto step=1<<30; step>>=1;){
						result+=step;
						int mask=0;
						for(int bit=0; bit<numCreature; ++bit)
							mask|=(curValue[bit]>=result)<<bit;
						if(curResult[mask]==0)
							result-=step;
					}
					std::cout<<result<<'\n';
				}

				break;
			default:
				assert(false); __builtin_unreachable();
		}
	}

}