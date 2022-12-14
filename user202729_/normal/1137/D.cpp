#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<array>
#include<string>
#include<vector>
#include<cstdlib>

void finish(){
	std::cout<<"done"<<std::endl;
	std::exit(0);
}

unsigned read_groups(auto fn /* std::string -> void */){
	unsigned ngroup;
	if(not (std::cin>>ngroup)){
		// wrong answer???
		std::exit(0);
	}
	std::string group;
	for(int z=ngroup;z--;){
		std::cin>>group;
		fn(group);
	}
	return ngroup;
}

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(&std::cout);

	// I knew Brent's algorithm int advance, but it still takes me ridiculously long to figure out
	// all the details...
	std::array<int,9> base;
	base[0]=1;
	for(unsigned i=1;i<base.size();++i)
		base[i]=base[i-1]*2+3;
	assert(base.back()>=1000);

	std::array<int,10> pos{};
	int cycle=0;
	int foundbase=-1;

	unsigned ngroup=0;
	while(cycle==0){ // nstep = c + (min base >= t (<= 2*t+1))
		std::cout<<"next ";
		for(unsigned i=0;i<base.size();++i)
			if(pos[i]<base[i]){
				std::cout<<i<<' ';
				++pos[i];
			}
		std::cout<<'9'<<std::endl;
		++pos[9];


		ngroup=read_groups([&](auto const& group){
			if(group.find('9')!=std::string::npos){
				for(char c:group){
					if(pos[9]!=pos[c-'0']){
						assert(cycle==0);
						cycle=pos[9]-pos[c-'0'];
						assert(cycle!=0);
						foundbase=c-'0';
					}
				}
			}
		});
	}

	assert(pos[foundbase]==base[foundbase]);
	
	if(foundbase==0){ // t == 1
		// takes c-1 steps
		while(ngroup!=1){
			std::cout<<"next ";
			for(unsigned i=1;i<pos.size();++i)
				if((pos[i]-1)%cycle!=0){
					std::cout<<i<<' ';
					++pos[i];
				}
			std::cout<<std::endl;

			ngroup=read_groups([](auto const&){});
		}
		finish();
	}

	assert(pos[foundbase-1]==base[foundbase-1]);
	// move 0, ..., foundbase-1 to pos[foundbase-1] and rest to pos[foundbase-1] + something*c

	while(true){
		std::vector<int> items;
		for(int i=0;i<foundbase;++i)
			if(pos[i]<pos[foundbase-1])
				items.push_back(i);
		for(unsigned i=foundbase;i<pos.size();++i)
			if((pos[i]-pos[foundbase-1])%cycle!=0)
				items.push_back(i);

		if(items.empty())
			break;

		std::cout<<"next ";
		for(int i:items){
			std::cout<<i<<' ';
			++pos[i];
		}
		std::cout<<std::endl;

		ngroup=read_groups([](auto const&){});
		assert(ngroup!=1); // because pos[foundbase-1] is not in the cycle
	}

	while(ngroup!=1){
		std::cout<<"next ";
		for(unsigned i=0;i<pos.size();++i){
			std::cout<<i<<' ';
			++pos[i];
		}
		std::cout<<std::endl;

		ngroup=read_groups([](auto const&){});
	}
	finish();
}