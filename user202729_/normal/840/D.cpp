#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>

#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

/// Used to answer the question: Given a number (x) and a range
/// [l..r[, what is the number of occurences of (x)?
struct RangeCount{
	std::vector<int> index,head;

	RangeCount(std::vector<int> const& data, int end)
	:index(data.size()),head(end+1){
		assert(std::all_of(data.begin(),data.end(),[=](int x){
			return 0<=x&&x<end;
		}));

		head.resize(end+1);
		for(int x:data)++head[x];
		for(int i=0;i<end;++i)head[i+1]+=head[i];

		for(unsigned i=data.size();i-->0;)
			index[--head[data[i]]]=i;
	}

	int operator() (int x,int l,int r)const{
		assert(0<=l);
		assert(l<=r);
		assert(r<=(int)index.size());

		auto i1=head[x]+index.begin(),i2=head[x+1]+index.begin();
		return std::lower_bound(i1,i2,r)-std::lower_bound(i1,i2,l);
	}
};

int constexpr FREQ_RATIO=5;
struct SegmentTree{
	struct Node{
		using DataT=std::array<int,FREQ_RATIO>;
		DataT frequentElems;
		int nFrequent;
		DataT::const_iterator begin()const{return frequentElems.begin();}
		DataT::const_iterator end()  const{return nFrequent+frequentElems.begin();}
	};
	/// In layer [i], each node takes (at most) 2**i leaves
	std::vector<std::vector<Node>>layers;
	RangeCount rc;

	SegmentTree(std::vector<int> const& data,int end)
	:layers(),rc(data,end){
		std::vector<Node>firstLayer(data.size());
		for(unsigned i=data.size();i-->0;)
			firstLayer[i]={{data[i]},1};
		layers.push_back(std::move(firstLayer));

		// for frequent elements, reused between nodes
		std::vector<int>candidates;
		candidates.reserve(2*FREQ_RATIO);
		while(true){
			std::vector<Node>const& lastLayer=layers.back();
			if(lastLayer.size()==1)return;

			std::vector<Node> nextLayer(lastLayer.size()/2);

			unsigned lastLayerI=layers.size()-1;

			for(unsigned i=1;i<lastLayer.size();i+=2){
				// nextLayer[i/2] <- lastLayer[i-1] (+) lastLayer[i]
				candidates.clear();
				Node const& n1=lastLayer[i-1];
				Node const& n2=lastLayer[i];
				candidates.resize(n1.nFrequent+n2.nFrequent);
				candidates.erase(std::set_union(
					n1.begin(),n1.end(),
					n2.begin(),n2.end(),
					candidates.begin()
				),candidates.end());

				candidates.erase(
					std::remove_if(candidates.begin(),candidates.end(),
					[&](int c){
						return rc(c,(i-1)<<lastLayerI,(i+1)<<lastLayerI)
							*FREQ_RATIO<=(2<<lastLayerI);
					}),
					candidates.end()
				);

				std::copy(
					candidates.begin(),candidates.end(),
					nextLayer[i/2].frequentElems.begin()
				);
				nextLayer[i/2].nFrequent=candidates.size();
			}
			
			layers.push_back(std::move(nextLayer));
		}
	} // end of constructor

	/// Find the smallest number appearing in [l..r[ range
	/// with ratio > 1/requiredRatio, or -2 otherwise.
	int operator() (int l,int r,int requiredRatio){
		std::vector<int> candidates;
		for(unsigned layer=0,l1=l,r1=r;l1<r1;++layer,l1>>=1,r1>>=1){
			if(l1&1){
				candidates.insert(candidates.end(),layers[layer][l1].begin(),layers[layer][l1].end());
				++l1;
			}
			if(r1&1){
				--r1;
				candidates.insert(candidates.end(),layers[layer][r1].begin(),layers[layer][r1].end());
			}
		}

		std::sort(candidates.begin(),candidates.end());
		candidates.erase(
			std::unique(candidates.begin(),candidates.end()),
			candidates.end()
		);
		for(int x:candidates){
			if(rc(x,l,r)*requiredRatio>r-l)
				return x;
		}
		return -2;
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);
	int nElem,nQuery;std::cin>>nElem>>nQuery;
	std::vector<int>data(nElem);for(int& d:data)std::cin>>d,--d;
	SegmentTree data_st(data,nElem); // now all elements in (data) is < nElem
	while(nQuery-->0){
		int l,r,k;std::cin>>l>>r>>k;
		--l;
		std::cout<<data_st(l,r,k)+1<<'\n';
	}
}