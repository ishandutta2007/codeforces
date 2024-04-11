#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<vector>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<bitset>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int n,base;std::cin>>n>>base;
	std::vector<int> a(n);for(int& x:a)std::cin>>x;
	std::vector<std::bitset<2001>> ok(1<<n);

	ok[0]=true;
	for(unsigned mask=0;mask<ok.size();++mask){
		for(int sum=ok[mask].size();sum--;)if(ok[mask][sum]){
			if(sum%base==0)
				ok[mask][sum/base]=true;

			for(unsigned m1=(1<<n)-1-mask;m1;m1-=m1&-m1){ // no-op when mask==(1<<n)-1
				int nextbit=__builtin_ctz(m1);
				assert((mask|1<<nextbit)>mask);
				ok[mask|1<<nextbit][sum+a[nextbit]]=true;
			}
		}
	}

	if(ok.back()[1]){
		std::cout<<"YES\n";

		unsigned mask=(1<<n)-1;
		unsigned sum=1;
		std::vector<int> mult(n);
		int cur_expo=0;
		while(mask){
			assert(ok[mask][sum]);

			for(unsigned m1=mask;m1;m1-=m1&-m1){
				int nextbit=__builtin_ctz(m1);
				if(sum>=(unsigned)a[nextbit]&&ok[mask^(1<<nextbit)][sum-a[nextbit]]){
					mult[nextbit]=cur_expo;
					mask^=1<<nextbit;
					sum-=a[nextbit];
					goto continue_outer;
				}
			}

			sum*=base;
			++cur_expo;

continue_outer:;

		}

		std::vector<std::pair<int,int>> data(n);
		std::transform(begin(a),end(a),begin(mult),begin(data),[](int a,int b){return std::make_pair(a,b);});
		while(data.size()>1){
			for(unsigned i=0;i<data.size();++i)
			for(unsigned j=0;j<i;++j)
				if(data[i].second==data[j].second){
					std::cout<<data[i].first<<' '<<data[j].first<<'\n';

					std::pair<int,int> newitem{data[i].first+data[j].first,data[i].second};
					while(newitem.first%base==0){
						newitem.first/=base;
						--newitem.second;
					}

					data.erase(begin(data)+i);
					data.erase(begin(data)+j);
					data.push_back(newitem);
					goto continue_outer_2;
				}

			assert(false);
continue_outer_2:;
		}
	}else
		std::cout<<"NO\n";
}