/*
Unfortunately, I could not solve this problem myself and have to read the editorial,
even though I solved the shallow-tree and the line tree case.

UPD: Wasted about 10 minutes to write a test generator while it's (probably) easier and faster
to just read the problem statement carefully, especially the constraints.
*/

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>

int main(){
	std::ios::sync_with_stdio(0);

	int n;std::cin>>n;
	struct layer{
		int mindist; // to node 0
		std::vector<int> l1; // nodes with dist to node 0 == mindist
		std::vector<int> l2; // nodes with dist to node 0 > mindist and < mindist of next layer
	};

	std::vector<layer> a;
	{
		std::vector<int> range_1_n(n-1);
		std::iota(begin(range_1_n),end(range_1_n),1);
		a.push_back({0,{0},std::move(range_1_n)});
	}

	for(int gap=1<<(31^__builtin_clz(n-1));gap>1;gap>>=1){
		// now gap between two consecutive mindist value == 2*gap
		std::vector<layer> newa(a.size()*2);

		for(unsigned layermod2=0;layermod2<2;++layermod2)if(layermod2<a.size()){

			std::vector<char> in_any_l1(n);
			for(unsigned layer=layermod2;layer<a.size();layer+=2){
				auto const& [mindist,l1,l2]=a[layer];
				for(int x:l1)in_any_l1[x]=true;
			}

			std::cout<<'?';
			for(char x:in_any_l1)std::cout<<' '<<(x?gap:0);
			std::cout<<std::endl;

			std::string in1;std::cin>>in1; // nodes with layer mod (2*gap) <= gap and > 0
			// (in l2 of first half or l1 of second half)

			std::cout<<'?';
			for(char x:in_any_l1)std::cout<<' '<<(x?gap-1:0);
			std::cout<<std::endl;

			std::string in2;std::cin>>in2; // nodes with layer mod (2*gap) < gap and > 0
			// (in l2 of first half)

			for(unsigned layer=layermod2;layer<a.size();layer+=2){
				auto& [mindist,l1,l2]=a[layer];
				auto iter=std::partition(begin(l2),end(l2),[&](int x){
					if(in2[x]=='1')
						assert(in1[x]=='1');
					return in2[x]=='1';
				});

				newa[layer*2]={mindist,std::move(l1),
						std::vector<int>{begin(l2),iter} // when will ranges/slices be available int C++...
						};

				auto iter2=std::partition(iter,end(l2),[&](int x){ return in1[x]=='1'; });
				if(iter!=iter2){
					std::vector<int> l1_second_half(iter,iter2);
					l2.erase(begin(l2),iter2);
					newa[layer*2+1]={mindist+gap,std::move(l1_second_half),std::move(l2)};
				}else{
					// empty
					assert(iter2==end(l2));
				}
			}
		}

		a=std::move(newa);
		while(a.back().l1.empty()){ assert(a.back().l2.empty()); a.pop_back(); }
	}
	// now gap between two consecutive mindist value == 2

	{
		auto olda=std::move(a);
		a.clear();
		for(auto& [mindist,l1,l2]:olda){
			a.push_back({mindist,std::move(l1),{}});
			if(not l2.empty())
				a.push_back({mindist+1,std::move(l2),{}});
		}
	}

	for(auto const& [mindist,l1,l2]:a)
		assert(not l1.empty() and l2.empty());

	std::vector<int> parind(n); // for node in a[layer].l1, par(node) = a[layer-1].l1[parind[node]]

	for(int layermod3=0;layermod3<3;++layermod3){
		for(int bit=1;bit<n;bit<<=1){
			std::vector<char> bit_ind_on(n);

			for(unsigned layer=layermod3;layer+1<a.size();layer+=3)
				for(unsigned i=0;i<a[layer].l1.size();++i)if(i&bit)
					bit_ind_on[a[layer].l1[i]]=1;

			if(std::find(begin(bit_ind_on),end(bit_ind_on),1)!=end(bit_ind_on)){
				std::cout<<'?';
				for(char x:bit_ind_on)std::cout<<' '<<(x?1:0);
				std::cout<<std::endl;

				std::string in1;std::cin>>in1;
				for(unsigned layer=1+layermod3;layer<a.size();layer+=3)
					for(int x:a[layer].l1)
						if(in1[x]=='1')
							parind[x]|=bit;
			}else
				break; // small optimization (not necessary)
		}
	}

	std::cout<<"!\n";
	assert(parind[0]==0);
	assert(a[0].l1.size()==1);
	for(unsigned layer=1;layer<a.size();++layer)
		for(int x:a[layer].l1)
			std::cout<<1+a[layer-1].l1[parind[x]]<<' '<<1+x<<'\n';
}