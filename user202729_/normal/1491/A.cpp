// what!?
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int length, numQuery; std::cin>>length>>numQuery;
	std::vector<bool> value(length);
	for(auto&& it: value) {int value; std::cin>>value; it=value;}
	int numOne=std::accumulate(begin(value), end(value), 0);
	for(int _=0; _<numQuery; ++_){
		int type, index; std::cin>>type>>index;
		if(type==1){
			--index;
			numOne-=value[index];
			value[index]=not value[index];
			numOne+=value[index];
		}else{
			std::cout<<(index<=numOne ? '1': '0')<<'\n';
		}
	}
}