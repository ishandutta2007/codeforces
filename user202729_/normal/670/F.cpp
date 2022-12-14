#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<array>

std::array<int,10> countdigit(std::string const& s){
	std::array<int,10> out{};
	for(char c:s)++out[c-'0'];
	return out;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s,t;std::cin>>s>>t;

	if(s =="01" or s =="10"){
		assert(t=="0");
		std::cout<<"0\n";
		return 0;
	}

	auto ns =countdigit(s);
	auto nt =countdigit(t);
	for(int old_ndigit_len=std::min<int>(6,s.size());old_ndigit_len>=0;--old_ndigit_len){
		auto old_ndigit=s.size()-old_ndigit_len;
		auto old_ndigit_str=std::to_string(old_ndigit);
		if(old_ndigit_str.size()!=old_ndigit_len)
			continue;

		auto ntag=countdigit(old_ndigit_str);
		auto ns_rem=ns;std::transform(begin(ns_rem),end(ns_rem),begin(ntag),begin(ns_rem),std::minus<int>());
		if(std::any_of(begin(ns_rem),end(ns_rem),[](int x){return x<0;})){
nextnd:
			continue;
		}

		for(int i=0;i<10;++i){
			if(ns_rem[i]<nt[i])
				goto nextnd;
			ns_rem[i]-=nt[i];
		}

		std::vector<std::string> candidates;
		candidates.reserve(2);

		if(std::any_of(1+begin(ns_rem),end(ns_rem),[](int x){return x>0;})){
			std::string a;a.reserve(s.size()-old_ndigit_len);
			auto nr1=ns_rem;
			for(int i=1;;++i){
				if(nr1[i]){
					--nr1[i];
					a+=char(i+'0');
					break;
				}
			}
			bool t_inserted=false;
			for(int i=0;i<10;++i){
				if(not t_inserted and (t+char(i+'0'))<(char(i+'0')+t)){
					t_inserted=true;
					a+=t;
				}
				a.insert(end(a), nr1[i], char(i+'0'));
			}
			if(not t_inserted)
				a+=t;
			assert(a.size()==s.size()-old_ndigit_len);
			candidates.push_back(std::move(a));
		}

		if(t[0]!='0'){
			std::string a;a.reserve(s.size()-old_ndigit_len);
			a=t;
			for(int i=0;i<10;++i){
				a.insert(end(a), ns_rem[i], char(i+'0'));
			}
			assert(a.size()==s.size()-old_ndigit_len);
			candidates.push_back(std::move(a));
		}

		if(candidates.empty()) continue;

		std::cout<<*std::min_element(begin(candidates),end(candidates))<<'\n';
		return 0;
	}

	assert(false);
}