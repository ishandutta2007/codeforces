#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct Tree{
	std::vector<int> data;
	Tree(int number): data(number){}
	void add(int index){
		for(; index>=0; index=(index&(index+1))-1)
			++data[index];
	}
	int sumSuffix(int index) const{
		int result=0;
		for(; index<(int)data.size(); index|=index+1)
			result+=data[index];
		return result;
	}
};

struct Fraction{
	int numerator, denom;
	Fraction constexpr reduce() const{
		auto g=numerator==0 ? denom: std::abs(std::gcd(numerator, denom));
		if(denom<0) g=-g;
		assert(denom/g>0);
		return {numerator/g, denom/g};
	}
#define COMPARE(op) \
	bool operator op(Fraction other) const{ \
		assert(denom>0 and other.denom>0); \
		return (int64_t)numerator*other.denom op (int64_t)other.numerator*denom; \
	}
	COMPARE(<) COMPARE(==) COMPARE(!=)
#undef COMPARE

};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, w; std::cin>>number>>w;

	std::vector<std::pair<std::array<Fraction, 2>, int>> planes(number);
	for(auto & [first, sec]: planes){
		int x, v; std::cin>>x>>v;
		first[0]=Fraction{x, v+w}.reduce();
		if(w!=0) first[1]=Fraction{x, v-w}.reduce();
	}

	int64_t result=0;
	if(w==0){
		std::sort(begin(planes),end(planes),[&](auto one, auto two){
			return one.first[0]<two.first[0];
		});
		for(int last=0, pos=1;pos<=number;++pos)
			if(pos==number or planes[pos].first[0]!=planes[pos-1].first[0]){
				result+=(pos-last)*int64_t(pos-last-1);
				last=pos;
			}
		result>>=1;
	}else{
		std::sort(begin(planes),end(planes),[&](auto one, auto two){
			return
				std::tie(one.first[0], two.first[1])<
				std::tie(two.first[0], one.first[1]);
		});
		for(int index=0;index<number;++index) planes[index].second=index;
		std::sort(begin(planes),end(planes),[&](auto one, auto two){
			return
				std::tie(one.first[1], two.first[0])<
				std::tie(two.first[1], one.first[0]);
		});

		Tree tree(number);
		for(auto & [_, index]: planes){
			result+=tree.sumSuffix(index);
			tree.add(index);
		}
	}
	std::cout<<result<<'\n';
}