#include<iostream>
#include<vector>
#include<algorithm>

template<bool may_have_dupe=true>
bool nextwin(std::vector<int> sorted_a){
	int const n=sorted_a.size();
	if(may_have_dupe)
	for(int i=1;i<n;++i){
		if(sorted_a[i-1]==sorted_a[i]){
			if(sorted_a[i-1]==0)
				return false;
			--sorted_a[i-1]; // only possible move to avoid immediate losing
			for(int i=1;i<n;++i){
				if(sorted_a[i-1]==sorted_a[i]){
					return false; // still lose
				}
			}
			return !nextwin<false>(std::move(sorted_a));
		}
	}

	int64_t nmove_before_end=0;
	for(int i=0;i<n;++i){
		nmove_before_end+=sorted_a[i]-i;
	}
	return nmove_before_end%2==0?false:true;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);for(int& x:a)std::cin>>x;
	std::sort(begin(a),end(a));
	std::cout<<(nextwin(std::move(a))?"sjfnb":"cslnb")<<'\n';
}