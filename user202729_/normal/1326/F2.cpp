#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int constexpr maxN=18;
int number;

std::vector<int> getBlocks(int mask){
	int cur=1;
	std::vector<int> blocks;
	for(int bit=0; bit<number; ++bit){
		if(mask>>bit&1){
			++cur;
		}else{
			if(cur!=1) blocks.push_back(cur);
			cur=1;
		}
	}
	assert(cur==1); // bit at position number is always off
	std::sort(begin(blocks), end(blocks));
	return blocks;
}

auto const factorial=[]{
	std::array<int64_t, 19> factorial{{1}};
	for(int i=1; i<(int)factorial.size(); ++i)
		factorial[i]=factorial[i-1]*i;
	return factorial;
}();



template<bool reverse=false>
void transform(std::vector<int64_t>& it){
	for(int bit=0; bit<number; ++bit)
		for(int mask=0; mask<(1<<(number-1)); ++mask){
			auto const up=mask>>bit<<bit;
			auto const newMask=mask^up^(up<<1);
			if(reverse)
				it[newMask|1<<bit]-=it[newMask];
			else
				it[newMask|1<<bit]+=it[newMask];
		}
} // forgot what this transformation is called. FWHT?

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>number;

	std::vector<int> add;

	assert(number<=maxN);
	add.resize(number);
	for(int& row: add){
		for(int bit=0; bit<number; ++bit){
			char ch; std::cin>>ch;
			row|=(ch-'0')<<bit;
		};
	}

	auto const chain=[&]{
		std::vector<int64_t> chain(1<<number);
		// same as below, but without last

		std::vector<std::array<int64_t, maxN>> value(1<<number);
		// [subset][last] =number of permutations such that all adjacent pairs know each-other
		// for subset!=0

		for(int bit=0; bit<number; ++bit)
			value[1<<bit][bit]=1;

		for(int subset=1; subset<(int)value.size(); ++subset){
			auto& cur=value[subset];

			for(auto tmp=subset; tmp; tmp-=tmp&-tmp){
				auto const last=__builtin_ctz(tmp);
				if(auto const cur1=cur[last]; cur1!=0){
					chain[subset]+=cur1;

					int tmp=(((1<<number)-1)^subset)&add[last];

					for(; tmp; tmp-=tmp&-tmp){
						value[subset|(tmp&-tmp)][__builtin_ctz(tmp)]+=cur1;
					}
				}
			}
		}

		return chain;
	}();

	std::vector<std::vector<int64_t>> value(number+1, std::vector<int64_t>(1<<number));
	for(int i=0; i<(int)chain.size(); ++i)
		value[__builtin_popcount(i)][i]=chain[i];

	for(auto& it: value) transform(it);

	for(int i=0; i<(1<<number); ++i)
		assert(value[1][i]==__builtin_popcount(i));


	std::map<std::vector<int>, int64_t> memory; // blocks of a mask -> result of that mask

	std::array<std::array<uint64_t, maxN+1>, maxN+1> pow;
	for(int base=0; base<(int)pow.size(); ++base){
		for(auto [exponent, last]=std::pair(0,(uint64_t) 1); exponent<(int)pow[base].size(); ++exponent, last*=base)
			pow[base][exponent]=last;
	}

	std::vector<int64_t> result(1<<(number-1));

	for(int mask=0; mask<(int)result.size(); ++mask){
		auto [iterator, inserted]=memory.insert({getBlocks(mask), -1});
		if(inserted){
			auto const& blocks=iterator->first;

			std::vector<int64_t> cur(1<<number);
			for(int numBlock1=number-std::accumulate(begin(blocks), end(blocks), 0),
					i=0; i<(1<<number); ++i)
				cur[i]=pow[__builtin_popcount(i)][numBlock1];


			std::for_each(blocks.begin(), blocks.end(),[&](auto size){
				std::transform(begin(cur), end(cur), begin(value[size]), begin(cur), std::multiplies<>());
			});

			assert((int)cur.size()==(1<<number));
			int index=(1<<number)-1;
			bool sign=true;
			int64_t result{};
			for(int tmp=1<<number; tmp--;){
				result+=cur[index]*(sign ? 1: -1);
				index^=tmp&-tmp;
				sign=not sign;
			}

			assert((transform<true>(cur), result==cur.back()));

			iterator->second=result;
		}
		result[mask]=iterator->second;
	}

	for(int dim=0; dim<number-1; ++dim)
		for(int mask=0; mask<(int)result.size(); ++mask)
			if(not(mask>>dim&1)){
				result[mask]-=result[mask|1<<dim];
				assert(result[mask]>=0);
			}

	for(auto it: result) std::cout<<it<<' ';
	std::cout<<'\n';
}