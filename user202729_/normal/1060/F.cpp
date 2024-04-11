// [Turns out there isn't any editorial. TODO read other solutions?]
// Still O(n^5), but much faster.
// Can it be faster?

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> add;

#if 1
auto const factorial=[]{
	std::array<double, 100> factorial{{1}};
	for(int i=1;i<(int)factorial.size();++i) 
		factorial[i]=factorial[i-1]*i;
	return factorial;
}();

double binom(int x, int y){
	return factorial[x]/(factorial[y]*factorial[x-y]);
}
#else
auto const [factorial, inverseFactorial]=[]{
	std::array<std::array<double, 100>, 2> stuff{{{1}, {1}}};
	for(int i=1;i<(int)stuff[0].size();++i)
		stuff[1][i]=1/( stuff[0][i]=stuff[0][i-1]*i );
	return stuff;
}();

double binom(int x, int y){
	return factorial[x]*inverseFactorial[y]*inverseFactorial[x-y];
}
#endif

std::map<
	std::pair<int, int>,
	std::vector<std::vector<double>>
	> workCached;  // insertion must not invalidate references

std::vector<std::vector<double>> const& work(int node, int par){
	{
		auto const iterator=workCached.find({node, par});
		if(iterator!=workCached.end())
			return iterator->second;
	}

	std::vector<std::vector<double>> result(1);
	result[0].assign(1, 1.);
	// result[s][n] = probability n == (number of edges adjacent to root at position >= s in the order)
	// result.size() == subtree size

	for(int child: add[node]) if(child!=par){
		auto value=work(child, node);

		std::vector<std::vector<double>> value1(value.size()+1);
		// value of tree with degree(root)==1, child(root)= {subtree at child}
		for(int s=0;s<(int)value1.size();++s) {
			value1[s].resize(value1.size()-s);
			for(int n=0;n<(int)value1[s].size();++n) {
				for(int a=s;a<(int)value.size();++a) 
					if(n!=0 and n-1<(int)value[a].size())
						value1[s][n]+=value[a][n-1];
				if(s!=0)
					value1[s][n]+=value[s-1][n]*s;
				value1[s][n]/=(int)value.size();
			}
		}

		value.clear();
		std::vector<std::vector<double>> next(result.size()+value1.size()-1);
		for(int s=0;s<(int)next.size();++s) {
			next[s].resize(next.size()-s);
			for(int n=0;n<(int)next[s].size();++n) {
				for(int a=std::max(0, (int)result.size()-1-((int)next.size()-1-s));
						a<=std::min(s, (int)result.size()-1);
						++a) {
					double part{};
					for(int b=std::max(0, n-((int)value1.size()-1-(s-a))); 
							b<=std::min(n, (int)result.size()-1-a);
							++b) 
						part+=result[a][b]*value1[s-a][n-b];
					next[s][n]+=part
							*binom(s, a)*binom((int)next.size()-1-s, (int)result.size()-1-a)
							;
				}
				next[s][n]/=binom((int)next.size()-1, (int)result.size()-1);
			}
		}

		result=std::move(next);
	}
	auto [iterator, success]=workCached.insert({{node, par}, std::move(result)});
	assert(success);
	return iterator->second;
}

double finalProbability(std::vector<std::vector<double>> const& workResult){
	double result{};
	for(int n=0;n<(int)workResult[0].size();++n) 
		result+=std::pow(0.5, n)*workResult[0][n];
	return result;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	add.resize(number);
	for(int _=0;_<number-1;++_) {
		int first, sec; std::cin>>first>>sec;--first;--sec;
		add[first].push_back(sec);
		add[sec].push_back(first);
	}

	std::cout<<std::fixed<<std::setprecision(10);
	for(int node=0;node<number;++node)
		std::cout<<finalProbability(work(node, -1))<<'\n';
}