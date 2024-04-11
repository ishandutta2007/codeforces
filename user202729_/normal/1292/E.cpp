#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	int ntest;std::cin>>ntest;
	while(ntest--){
		int n;std::cin>>n;
		std::string s(n,0);

		auto const query=[&](std::string t){
			for(char c:t) assert(c=='C' or c=='H' or c=='O');
			std::cout<<"? "<<t<<'\n';
			int k;std::cin>>k;
			while(k--){
				int pos;std::cin>>pos;
				std::copy(begin(t),end(t),pos-1+begin(s));
			}
		};

		query("CH");
		query("CO");
		if(std::all_of(begin(s),end(s),[](char c){ return c==0; })){
			// remaining: 0.9
			query("OH"); query("HO");
			// remaining: 0.4

			if(std::all_of(begin(s),end(s),[](char c){ return c==0; })){
				// HHHCCC | OOOCCC | HHHH | OOOO | CCCC
				query("HHH");
				query("OOO");
				query("CCC");
				// remaining: > 1/16

				if(s[0]==0 and s.back()==0){
					assert(n==4);
					query("HHCC");
					if(s[0]==0) s="OOCC";
				}else if(s[0]==0){
					// HHHCCC or OOOCCC
					auto t=s; for(char& c:t) if(not c) c='H';
					query(t);
					for(char& c:s) if(not c) c='O';
				}else if(s.back()==0){
					for(char& c:s) if(not c) c='C';
				}
			}else{
				query(s[s.find_last_not_of('\0')] + std::string("C"));
				// remaining: 0.15

				for(int i=0,last=-1;i<n;++i)if(s[i]!=0){
					assert(std::all_of(last+1+begin(s),i+begin(s),[](char c){ return c==0; }));
					assert(last<0 or i==last+1 or s[last]==s[i]);
					std::fill(last+1+begin(s),i+begin(s),s[i]);
					last=i;
				}
				std::fill(begin(s)+s.find_last_not_of('\0'),end(s),s[s.find_last_not_of('\0')]);
			}
		}else{
			// remaining: 0.9
			auto l=s.find_first_not_of('\0');
			auto r=s.find('\0',l);
			while(r<s.size()){
				if(s[r]!=0){ ++r; continue; }
				query(s.substr(l,r-l)+'C');
				if(s[r]!=0){ ++r; continue; }
				query(s.substr(l,r-l)+'H');
				if(s[r]!=0){ ++r; continue; }
				s[r]='O';
				++r;
			}
			while(l>0){
				--l;
				if(s[l]!=0) continue;
				query('C'+s.substr(l+1,r-l-1));
				if(s[l]!=0) continue;
				query('H'+s.substr(l+1,r-l-1));
				if(s[l]!=0) continue;
				s[l]='O';
			}
		}

		std::cout<<"! "<<s<<'\n';
		int result;
		std::cin>>result;
		assert(result==1);
	}
}