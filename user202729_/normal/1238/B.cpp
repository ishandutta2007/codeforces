#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	std::vector<int> vals;
	while(ntest--){
		vals.clear();
		int n,rad;std::cin>>n>>rad;
		vals.resize(n);for(int& x:vals)std::cin>>x;
		std::sort(begin(vals),end(vals));
		vals.erase(std::unique(begin(vals),end(vals)),end(vals));

		int split=0; // <= split : crushed
		int ans=0;
		size_t iter=0; // < iter: crushed
		while(true){
			++ans;
			split+=rad;
			vals.pop_back();
			while(iter<vals.size()&&vals[iter]<=split)
				++iter;
			if(iter>=vals.size())
				break;
		}
		std::cout<<ans<<'\n';
	}
}