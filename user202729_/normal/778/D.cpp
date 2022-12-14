// I've done this problem before...
#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<tuple>
#include<cassert>
#include<iostream>
#include<vector>
#include<string>

std::vector<std::pair<int,int>> ans; // 0 indexing

int nrow,ncol;
std::vector<std::string> t;

void makevert(int r,int c);

void makehorz(int r,int c){
	if(t[r][c]=='L')
		return;
	assert(t[r][c]=='U');
	assert(t[r+1][c]=='D');
	if(t[r][c+1]=='L'){
		makevert(r,c+1);
	}
	assert((std::tie(t[r][c],t[r][c+1],t[r+1][c],t[r+1][c+1])==std::make_tuple('U','U','D','D')));
	ans.push_back({r,c});
	std::tie(t[r][c],t[r][c+1],t[r+1][c],t[r+1][c+1])=std::make_tuple('L','R','L','R');
}

void makevert(int r,int c){
	if(t[r][c]=='U')
		return;
	assert(t[r][c]=='L');
	assert(t[r][c+1]=='R');
	if(t[r+1][c]=='U'){
		makehorz(r+1,c);
	}
	assert((std::tie(t[r][c],t[r][c+1],t[r+1][c],t[r+1][c+1])==std::make_tuple('L','R','L','R')));
	ans.push_back({r,c});
	std::tie(t[r][c],t[r][c+1],t[r+1][c],t[r+1][c+1])=std::make_tuple('U','U','D','D');
}

void solve1(){ // read a board and SO*FL it (purchase the moves required to solve it to vector ANS)
	t.resize(nrow);
	for(auto& x:t){
		x.reserve(ncol);
		std::cin>>x;
	}

	if(nrow%2==0){
		for(int r=0;r<nrow;++++r)
		for(int c=0;c<ncol;++c)
			makevert(r,c);
	}else{
		for(int c=0;c<ncol;++++c)
		for(int r=0;r<nrow;++r)
			makehorz(r,c);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>nrow>>ncol;

	solve1();
	auto oldz=ans.size();
	solve1();
	std::reverse(begin(ans)+oldz,end(ans));

	std::cout<<ans.size()<<'\n';
	for(auto [x,y]:ans){
		std::cout<<x+1<<' '<<y+1<<'\n';
	}
}