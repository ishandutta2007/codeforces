#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
10
AND 9 4
IN 1
IN 1
XOR 6 5
AND 3 7
IN 0
NOT 10
IN 1
IN 1
AND 2 8
)");}
#endif // Sublime

#include<iostream>
#include<vector>

struct gate{char op;bool val,editroot;int a,b;};
std::vector<gate>gates;

// only use after eval'd. use `val` of children (except in I)
bool eval1(int node){
	switch(gates[node].op){
		case'A':case'O':case'X':{
			bool const a=gates[gates[node].a].val,
				b=gates[gates[node].b].val;
			switch(gates[node].op){
			case'A':return a and b;
			case'O':return a or  b;
			case'X':return a xor b;
			default:throw 0;
			}
		}
		case'N':
			return not gates[gates[node].a].val;
		case'I':
			return gates[node].val;
		default:
			std::cerr<<"Unexpected op: "<<gates[node].op<<'\n';
			throw 0;
	}
}

void eval(int node){
	// if uninitialized, default to 0
	if(gates[node].a)eval(gates[node].a);
	if(gates[node].b)eval(gates[node].b);
	gates[node].val=eval1(node);
}

void fill_editroot(int node,int parent){
	if(node==0){
		gates[node].editroot=true;
	}else if(!gates[parent].editroot){
		return; // default to false
	}else{
		gates[node].val^=1;
		gates[node].editroot=eval1(parent)!=gates[parent].val;
		gates[node].val^=1;
	}

	if(gates[node].editroot){
		if(gates[node].a)fill_editroot(gates[node].a,node);
		if(gates[node].b)fill_editroot(gates[node].b,node);
	}

}

int main(){
	std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);
	int ngate;std::cin>>ngate;
	gates.resize(ngate);
	for(int i=0;i<ngate;++i){
		std::cin>>gates[i].op;std::cin.ignore(10,' ');
		switch(gates[i].op){
		case'A':case'O':case'X':
			std::cin>>gates[i].a>>gates[i].b;
			--gates[i].a;--gates[i].b;
			break;
		case'N':
			std::cin>>gates[i].a;
			--gates[i].a;
			break;
		case'I':
			std::cin>>gates[i].val; // input bit, 0 or 1
		}
	}

	eval(0);
	fill_editroot(0,-1);

	bool root_value=gates[0].val;
	for(gate const&x:gates)if(x.op=='I'){
		std::cout<<(root_value^x.editroot);
	}
	std::cout<<'\n';

}