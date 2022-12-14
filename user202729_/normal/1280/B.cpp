#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		int nrow,ncol;std::cin>>nrow>>ncol;
		std::vector<std::string> t(nrow);
		bool anya=false,anyp=false;

		bool ok=false;
		for(auto& row:t){
			row.reserve(ncol);
			std::cin>>row;
			bool row_anya,row_anyp;
			anya=anya | (row_anya=(std::find(begin(row),end(row),'A')!=end(row)));
			anyp=anyp | (row_anyp=(std::find(begin(row),end(row),'P')!=end(row)));
			if(not row_anyp)
				ok=true;
		}
		if(not anya){ std::cout<<"MORTAL\n"; continue; }
		if(not anyp){ std::cout<<"0\n"; continue; }

		if(
				std::find(begin(t[0]),end(t[0]),'P')==end(t[0]) or
				std::find(begin(t.back()),end(t.back()),'P')==end(t.back()) or
				std::all_of(begin(t),end(t),[](std::string& row){return row[0]=='A';}) or
				std::all_of(begin(t),end(t),[](std::string& row){return row.back()=='A';})
		  ){ std::cout<<"1\n"; continue; }

		if(t[0][0]=='A' or t[0].back()=='A' or
			t.back()[0]=='A' or t.back().back()=='A' or ok){
			std::cout<<"2\n"; continue;
		}
		
		for(int c=0;c<ncol;++c)
			if(std::all_of(begin(t),end(t),[c](std::string& row){return row[c]=='A';})){
				std::cout<<"2\n";
				goto nexttest;
			}

		if(
				std::find(begin(t[0]),end(t[0]),'A')!=end(t[0]) or
				std::find(begin(t.back()),end(t.back()),'A')!=end(t.back()) or
				std::any_of(begin(t),end(t),[](std::string& row){return row[0]=='A';}) or
				std::any_of(begin(t),end(t),[](std::string& row){return row.back()=='A';})
		  ){ std::cout<<"3\n"; continue; }

		std::cout<<"4\n";

nexttest:;
	}
}