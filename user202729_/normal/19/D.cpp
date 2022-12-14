#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct Tree{
	std::vector<int> data;
	Tree(int size, int value): data(size*2, value){
	}
	int size()const{
		return int(data.size()/2);
	}
	void set(int pos, int value){
		pos+=size();
		data[pos]=value;
		for(pos>>=1; pos; pos>>=1)
			data[pos]=std::max(data[pos*2], data[pos*2+1]);
	}
	int firstGreater(int pos, int value)const{
		std::vector<int> rights;

		auto const process=[&](int node)->std::pair<bool, int>{
			if(data[node]<=value) return {false, 0};
			while(node<size()){
				node*=2;
				if(data[node]<=value)++node;
			}
			assert(data[node]>value);
			return {true, node-size()};
		};

#define P(x) { auto _y=process(x); if(_y.first) return _y.second; }

		for(int left=pos+size(), right=(int)data.size(); left<right; left>>=1, right>>=1){
			if(left&1){
				P(left);
				++left;
			}
			if(right&1){
				rights.push_back(--right);
			}
		}
		for(auto index=rights.size(); index--;)
			P(rights[index]);
		return -1;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numQuery; std::cin>>numQuery;
	struct Query{
		char type; int x, y;
	};
	std::vector<Query> queries(numQuery);
	std::vector<int> xvalues; xvalues.reserve(numQuery);
	for(auto& [type, x, y]: queries){
		std::cin>>type;

		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(),' ');
		while(std::cin.get()!=' '){}

		assert(std::cin);
		std::cin>>x>>y;
		assert(y>=0);
		if(type=='a')
			xvalues.push_back(x);
	}
	std::sort(begin(xvalues), end(xvalues));
	xvalues.erase(std::unique(begin(xvalues), end(xvalues)), end(xvalues));
	std::vector<std::multiset<int>> yat(xvalues.size());

	Tree maximum((int)xvalues.size(), -1);
	auto const setMaximum=[&](int x){
		maximum.set(x, yat[x].empty() ? -1: *yat[x].rbegin());
	};

	for(auto [type, x, y]: queries){
		switch(type){
			case 'a':
				x=int(std::lower_bound(begin(xvalues), end(xvalues), x)-begin(xvalues));
				yat[x].insert(y);
				setMaximum(x);
				break;
			case 'r':
				x=int(std::lower_bound(begin(xvalues), end(xvalues), x)-begin(xvalues));
				yat[x].erase(yat[x].find(y));
				setMaximum(x);
				break;
			case 'f':
				x=int(std::upper_bound(begin(xvalues), end(xvalues), x)-begin(xvalues));
				if(auto const x1=maximum.firstGreater(x, y); x1<0){
					std::cout<<"-1\n";
				}else{
					std::cout<<xvalues[x1]<<' '<<*yat[x1].upper_bound(y)<<'\n';
				}
				break;
			default:
				assert(false); __builtin_unreachable();
		}
	}
}