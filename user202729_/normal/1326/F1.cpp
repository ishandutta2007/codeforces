// "undefined behavior is accepted"
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<int> add;

std::array<std::vector<int>, 2> countBinary;

unsigned constexpr revbit(unsigned x){
	x=(x&0x55555555)<<1|((x>>1)&0x55555555);
	x=(x&0x33333333)<<2|((x>>2)&0x33333333);
	x=(x&0x0f0f0f0f)<<4|((x>>4)&0x0f0f0f0f);
	x=(x&0x00ff00ff)<<8|((x>>8)&0x00ff00ff);
	return x>>16|x<<16;
}

template<int index>
void workBacktrack(int node, int left, int result){
	if(not left){
		++countBinary[index][result];
		return;
	}
	for(auto tmp=left; tmp; tmp-=tmp&-tmp){
		auto const nextNode=__builtin_ctz(tmp);
		auto const cur=(add[node]>>nextNode&1);
		workBacktrack<index>(nextNode, left-(1<<nextNode), result<<1|cur);
	}
}

template<int index>
void work(int node, int left){
	countBinary[index].assign(1<<__builtin_popcount(left), 0);
	workBacktrack<index>(node, left, 0);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	add.resize(number);
	for(auto& cur: add){
		for(int x=0;x<number;++x) {
			char ch; std::cin>>ch; ch-='0';
			cur|=ch<<x;
		}
	}

	std::vector<int64_t> count;
	count.resize(1<<(number-1));
	for(int firstHalf=0;firstHalf<(1<<number);++firstHalf)
		if(__builtin_popcount(firstHalf)==(number-1)/2){
			for(int mid=0;mid<number;++mid) if(not(firstHalf>>mid&1)){
				work<0>(mid, firstHalf);
				auto const secHalf=(1<<number)-1-(1<<mid)-firstHalf;
				work<1>(mid, secHalf);

				auto const mask1len=(number-1)/2;
				assert((1<<mask1len)==(int)countBinary[0].size());

				auto const mask2len=(number)/2;
				assert((1<<mask2len)==(int)countBinary[1].size());

				for(int mask1=0;mask1<(int)countBinary[0].size();++mask1)
				if(auto const countMask1=countBinary[0][mask1]; countMask1!=0)
				for(int mask2=0;mask2<(int)countBinary[1].size();++mask2)
				{
					auto const mask1part=revbit(mask1)>>((32-mask1len)&31)<<mask2len;
					auto const mask2part=mask2;
					assert(0==(mask1part&mask2part));
					auto const addedValue=countMask1*(int64_t)countBinary[1][mask2];
					auto const allMask=mask1part|mask2part;
					count[allMask]+=addedValue;
				}
			}
		}

	for(auto x: count) std::cout<<x<<' ';
	std::cout<<'\n';
}