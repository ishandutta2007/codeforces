#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct MaxQuery{
	using P=std::pair<int, int>;
	static P f(P first, P sec){return first.first>sec.first ? first: sec;}

	std::vector<std::vector<P>> data;
	MaxQuery(){}
	MaxQuery(std::vector<int> const& input){
		data.emplace_back(input.size());
		for(int index=0; index<(int)input.size(); ++index)
			data[0][index]={input[index], index};
		for(auto step=1; step<(int)data.back().size(); step<<=1){
			auto const& a=data.back();
			std::vector<P> b(a.begin()+step, a.end());
			std::transform(begin(b), end(b), a.begin(), b.begin(), f);
			data.push_back(std::move(b));
		}
	}

	P get(int left, int right){
		int layer=31^__builtin_clz(right-left);
		return f(data[layer][left], data[layer][right-(1<<layer)]);
	}
};

MaxQuery maximum;
int64_t result;
std::vector<int> suffixMod;
std::vector<int> count;
int mod;

int add(int a, int b){
	assert(0<=a); assert(a<mod); assert(0<=b); assert(b<mod);
	a+=b; if(a>=mod) a-=mod; return a;
}
int subtract(int a, int b){
	assert(0<=a); assert(a<mod); assert(0<=b); assert(b<mod);
	a-=b; if(a<0) a+=mod; return a;
}

void process(int left, int right){
	// now count should include all endpoints in [left..=right]
	// when this function returns, count should be zero

	assert(([&]{
		for(int i=left; i<=right; ++i)
			--count[suffixMod[i]];
		for(auto it: count) assert(it==0);
		for(int i=left; i<=right; ++i)
			++count[suffixMod[i]];
		return true;
	}()));
	if(right-left<=1){
		for(int i=left; i<=right; ++i)
			--count[suffixMod[i]];
		for(auto it: count) assert(it==0);
		return;
	}

	auto [midvalue, mid]=maximum.get(left, right);
	midvalue%=mod;
	if(mid-left<right-mid-1){
		for(int i=left; i<=mid;++i)
			--count[suffixMod[i]];
		for(int i=left; i<=mid;++i)
			result+=count[subtract(suffixMod[i], midvalue)];
		assert(subtract(suffixMod[mid], midvalue)==suffixMod[mid+1]);
		assert(count[suffixMod[mid+1]]!=0);
		--result;

		process(mid+1, right);
		for(int i=left; i<=mid;++i)
			++count[suffixMod[i]];
		process(left, mid);
	}else{
		for(int i=mid+1; i<=right;++i)
			--count[suffixMod[i]];
		for(int i=mid+1; i<=right;++i)
			result+=count[add(suffixMod[i], midvalue)];
		--result;

		process(left, mid);
		for(int i=mid+1; i<=right;++i)
			++count[suffixMod[i]];
		process(mid+1, right);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number;
	std::cin>>number>>mod;
	std::vector<int> value(number);for(auto& it: value) std::cin>>it;

	suffixMod.resize(number+1);
	for(auto index=number; index--;) suffixMod[index]=(suffixMod[index+1]+value[index])%mod;

	maximum=MaxQuery(value);
	result=0;
	assert(count.empty()); count.resize(mod);
	for(auto it: suffixMod) count[it]++;
	process(0, number);

	std::cout<<result<<'\n';
}