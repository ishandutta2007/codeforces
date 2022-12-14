// Isn't 10**8 obviously fast enough?

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::array<int, 26>> next_, previous; // [slice index][character]
std::vector<std::array<char, 26>> nextG, previousG; // same as above, exclude that character and value = grundy value
std::vector<int> order; // order[i]=number of occurrences of string[i] in string[:i]

std::array<std::vector<char>, 26> valuePrefix; // xor of grundy values in the inclusive prefix
// of strings delimited by character x.

struct Tree{
	std::vector<char> data;
	char get(int pos) const{ // return xor(data[...pos]) (inclusive prefix)
		char result=0;
		while(pos>=0){
			result=char(result xor data[pos]);
			pos=(pos&(pos+1))-1;
		}
		return result;
	}
	void set(int pos, char value){ // data[pos]^=value
		while(pos<(int)data.size()){
			data[pos]^=value;
			pos|=pos+1;
		}
	}
};
std::array<Tree, 26> value; // same as above, but get is O(log n);

template<bool fast> char solve(int left, int right){
	// if fast, assumes that valueSuffix is already computed and takes O(A), otherwise takes O(A log n)
	// (A = alphabet size)
	if(left==right) return 0;

	auto const solve_=[](char& result, int left, int right){
		if(result<0) result=solve<fast>(left, right);
		return result;
	};

	int reachable=0;
	for(int ch=0;ch<26;++ch) if(next_[left][ch]<right){
		auto const x=next_[left][ch], y=previous[right][ch];
		assert(x<=y);
		reachable|=1<<(
				solve_(nextG[left][ch], left, x) xor solve_(previousG[right][ch], y+1, right) xor
				(fast ? valuePrefix[ch][order[x]] xor valuePrefix[ch][order[y]]:
				 (value[ch].get(order[x]) xor value[ch].get(order[y])))
				);
	}
	return char(__builtin_ctz(~reachable));
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	std::string string; std::cin>>string;
	for(auto & ch: string) ch=char(ch-'a');
	auto const len=(int)string.size();
	next_.resize(len); previous.resize(len+1);
	{
		std::array<int, 26> last; last.fill(-1);
		for(int index=0;index<len;++index) {
			previous[index]=last;
			last[string[index]]=index;
		}
		previous[len]=last;
	}
	{
		std::array<int, 26> curNext; curNext.fill(len);
		for(int index=len; index--;){
			curNext[string[index]]=index;
			next_[index]=curNext;
		}
	}

	order.resize(len);
	for(int ch=0;ch<26;++ch) {
		int orderCur=0, index=next_[0][ch];
		while(index<len){
			assert(string[index]==ch);
			order[index]=orderCur;
			if(index+1==len) break;
			++orderCur; index=next_[index+1][ch];
		}
	}

	nextG.resize(len);
	previousG.resize(len+1);
	std::memset(nextG.data(), -1, sizeof(nextG[0])*nextG.size());
	std::memset(previousG.data(), -1, sizeof(previousG[0])*previousG.size());

	struct T{
		int len, right;
		bool operator<(T other) const{return len<other.len;}
	};
	std::vector<T> items(len);
	for(int right=0;right<len;++right) items[right]={right-previous[right][string[right]]-1, right};
	std::sort(begin(items),end(items));

	{
		std::array<int, 26> count{};
		for(auto ch: string) ++count[ch];
		for(int ch=0;ch<26;++ch) { value[ch].data.resize(count[ch]); valuePrefix[ch].resize(count[ch]); }
	}
	for(auto [len, right]: items){
		value[string[right]].set(order[right], solve<false>(right-len, right));
	}
	for(int ch=0;ch<26;++ch) {
		for(int index=0;index<(int)valuePrefix[ch].size();++index) 
			valuePrefix[ch][index]=value[ch].get(index); // (could be done in O(n) instead...)

		value[ch].data.clear();
	}

	int numQuery; std::cin>>numQuery;
	while(numQuery--){
		int left, right; std::cin>>left>>right;
		std::cout<<(solve<true>(--left, right)==0 ? "Bob\n": "Alice\n");
	}
}