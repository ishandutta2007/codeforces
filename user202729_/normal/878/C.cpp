#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct T{
	std::array<int, 9> value;
	T min(T other) const{
		std::transform(begin(other.value), end(other.value),begin(value), other.value.begin(),
				[&](auto a, auto b){return std::min(a, b);});
		return other;
	}
	T max(T other) const{
		std::transform(begin(other.value), end(other.value),begin(value), other.value.begin(),
				[&](auto a, auto b){return std::max(a, b);});
		return other;
	}
	bool any(T other, auto fun)const{
		for(int index=0; index<(int)value.size(); ++index)
			if(fun(value[index], other.value[index])) return true;
		return false;
	}
	bool all(T other, auto fun)const{
		return not any(other,[&](int first, int sec){return not fun(first, sec);});
	}
};

template<class T, bool min, bool reverse> struct BIT{
	// if T is ::T then `min` determines if `min` or `max` function in T should be called as `f`
	// else if T is `int` then sum is always used

	std::vector<T> data;

	static T identity(){
		if constexpr(std::is_same_v<T, int>){
			return 0;
		}else{
			T t;
			t.value.fill(min ? INT_MAX: 0);
			return t;
		}
	}

	static T f(T const first, T const sec){
		if constexpr(std::is_same_v<T, int>){
			return first+sec;
		}else{
			return min? first.min(sec): first.max(sec);
		}
	}

	BIT(int number): data(number+1, identity()){}
	T get(int index)const{ // without reverse this gets the suffix, inclusive
		index+=1;
		if(reverse) index=(int)data.size()-index;
		T result=data[index];
		while(true){
			index+=index&-index;
			if(index>=(int)data.size()) break;
			result=f(result, data[index]);
		}
		return result;
	}
	void add(int index, T value){
		index+=1;
		if(reverse) index=(int)data.size()-index;
		while(index>0){
			data[index]=f(data[index], value);
			index-=index&-index;
		}
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numDim; std::cin>>number>>numDim;
	std::vector<std::array<int, 10>> power(number);

	std::vector<int> value0;
	for(auto& it: power){
		for(int index=0; index<numDim; ++index)
			std::cin>>it[index];
		value0.push_back(it[0]);
	}
	std::sort(begin(value0), end(value0));
	assert(std::unique(begin(value0), end(value0))==value0.end());
	assert((int)value0.size()==number);

	for(auto& it: power)
		it[0]=int(std::lower_bound(begin(value0), end(value0), it[0])-value0.begin());
	value0.clear();

	BIT<T, false, true> prefix(number);
	BIT<T, true, false> suffix(number);
	std::set<int> free; // i in free -> prefix.get(i).all(suffix.get(i+1), std::less<>())
	// (if not processed)
	for(int i=0; i<number-1; ++i)
		free.insert(free.end(), i);

	BIT<int, false, false> count(number);

	int max0=-1;
	for(auto it: power){
		T t{};
		std::copy_n(it.begin()+1, numDim-1, t.value.begin());
		prefix.add(it[0], t);
		suffix.add(it[0], t);
		count.add(it[0], 1);

		max0=std::max(max0, it[0]);

		auto iterator=free.lower_bound(max0);
		while(iterator!=free.begin()){
			--iterator;
			auto const i=*iterator;
#if 0
			if(not prefix.get(i).all(suffix.get(i+1), std::less<>())){
#else
			auto const a=prefix.get(i);
			auto const b=suffix.get(i+1);
			if(a.any(b, std::greater<>())){
#endif
				iterator=free.erase(iterator);
				continue;
			}

			// real free
			std::cout<<count.get(i+1)<<'\n';
			goto continue_outer;
		}
		std::cout<<count.get(0)<<'\n';
continue_outer:;
	}
}