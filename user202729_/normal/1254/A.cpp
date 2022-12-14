#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;

	std::string s; // chicken names
	for(char c='A';c<='Z';++c)s+=c;
	for(char c='a';c<='z';++c)s+=c;
	for(char c='0';c<='9';++c)s+=c;

	std::vector<std::string> t;
	while(ntest--){
		int nrow,ncol,k;std::cin>>nrow>>ncol>>k;
		t.resize(nrow);
		int total_nrice=0;
		for(auto& row:t){
			std::cin>>row;
			total_nrice+=(int)std::count(begin(row),end(row),'R');
		}
		int min_nrice=total_nrice/k,max_nrice=min_nrice+1,nmax=total_nrice%k;

		int r=0,c=0;
		auto nxt=[&]{
			if(r&1){
				if(c==0) ++r;
				else --c;
			}else{
				if(c==ncol-1) ++r;
				else ++c;
			}
		};

		// (r,c): first unassigned cell
		for(int i=0;i<k;++i){
			int nrice=i<nmax ? max_nrice : min_nrice;
			while(nrice){
				if(t[r][c]=='R')--nrice;
				t[r][c]=s[i];
				nxt();
			}
		}

		// assign rest
		while(r<nrow){
			t[r][c]=s[k-1];
			nxt();
		}

		for(auto const& row:t)std::cout<<row <<'\n';
	}
}