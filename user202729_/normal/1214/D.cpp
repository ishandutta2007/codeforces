#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<climits>
#include<vector>
#include<string>
#include<deque>

int const MOD=1000012157;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nrow,ncol;std::cin>>nrow>>ncol;
	std::vector<std::string> s(nrow);
	for(auto& r:s){r.reserve(ncol);std::cin>>r;}

	// number of path 0,0 to cell
	std::vector<std::vector<int>> da(nrow,std::vector<int>(ncol));

	da[0][0]=1;
	for(int r=0;r<nrow;++r)
	for(int c=0;c<ncol;++c){
		if(s[r][c]=='#')continue;
		if(r)da[r][c]+=da[r-1][c];
		if(c)da[r][c]+=da[r][c-1];
		da[r][c]%=MOD;
	}

	if(da.back().back()==0){
		std::cout<<"0\n";
		return 0;
	}

	// number of path cell to nrow-1,ncol-1
	std::vector<std::vector<int>> db(nrow,std::vector<int>(ncol));
	db.back().back()=1;
	for(int r=nrow;r--;)
	for(int c=ncol;c--;){
		if(s[r][c]=='#')continue;
		if(r+1<nrow)db[r][c]+=db[r+1][c];
		if(c+1<ncol)db[r][c]+=db[r][c+1];
		db[r][c]%=MOD;
	}

	for(int r=0;r<nrow;++r)
	for(int c=0;c<ncol;++c){
		if(
				!((r==0&&c==0)||(r==nrow-1&&c==ncol-1))&&
		  da[r][c]*(int64_t)db[r][c]%MOD==da.back().back()){
			std::cout<<"1\n";
			return 0;
		}
	}

	std::cout<<"2\n";
	return 0;
}