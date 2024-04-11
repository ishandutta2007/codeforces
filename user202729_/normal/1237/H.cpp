// see also: BOUNDS FOR SORTING BY PREFIX REVERSAL
// In this particular problem, you have 2n moves andMneed to sort a (directed)
// permutation of n elements, not n moves (which is hard for an arbitrary
// permutation, but may be solvable with a permutation of a binary sequence)

#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

struct cnt_res{int n00,n01,n10;};
cnt_res cnt(std::string const& a){
	cnt_res ans{};
	for(unsigned i=0;i<a.size();i+=2)
		if(a[i]=='0'&&a[i+1]=='0')
			++ans.n00;
		else if(a[i]=='0'&&a[i+1]=='1')
			++ans.n01;
		else if(a[i]=='1'&&a[i+1]=='0')
			++ans.n10;
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;

	std::string a,b;
	std::vector<int> ans;

	while(ntest--){
		ans.clear();
		std::cin>>a>>b;

		int pending_b_rev=0;

		{
			auto [a00,a01,a10]=cnt(a);
			auto [b00,b01,b10]=cnt(b);
			if(a00!=b00 || a01+a10!=b01+b10){
				std::cout<<"-1\n";
				continue;
			}

			if(a01!=b10){
				int p01_10=0; // n01 - n10 of prefix
				for(int i=0;i<=a.size();i+=2){
					if(a[i]=='0'&&a[i+1]=='1')
						++p01_10;
					else if(a[i]=='1'&&a[i+1]=='0')
						--p01_10;
					if(a01-p01_10==b10){
						ans.push_back(i+2);
						std::reverse(begin(a),begin(a)+i+2);
						goto desirable_situation;
					}
				}

				p01_10=0; // n01 - n10 of prefix
				for(int i=0;i<=b.size();i+=2){
					if(b[i]=='0'&&b[i+1]=='1')
						++p01_10;
					else if(b[i]=='1'&&b[i+1]=='0')
						--p01_10;
					if(b10+p01_10==a01){
						pending_b_rev=i+2;
						std::reverse(begin(b),begin(b)+i+2);
						goto desirable_situation;
					}
				}

				assert(false);
			}
		}

desirable_situation:

		for(int i=0;i<a.size();i+=2){
			for(int j=i;;j+=2)
				if(a[j+1]==b.end()[-i-2]&&a[j]==b.end()[-i-1]){
					if(j>0){
						ans.push_back(j);
						std::reverse(begin(a),begin(a)+j);
					}
					ans.push_back(j+2);
					std::reverse(begin(a),begin(a)+j+2);
					break;
				}
		}

		assert(a==b);

		if(pending_b_rev!=0)
			ans.push_back(pending_b_rev);

		std::cout<<ans.size()<<'\n';
		for(int x:ans)std::cout<<x<<' ';
		std::cout<<'\n';
	}
}