// I think this problem is easy enough. Why are there so few people who solved it?
// Because the implementation is tedious?
//
// [UPD: Indeed. Took me in total more than 2 hours to implement, including time to implement wrong solution and realize that it's wrong (originally I thought that the 2x3 puzzle is solvable), excluding time to implement test generator or brute force programs]
// The solution is similar to the solution of the 15-puzzle.
// [I didn't read the editorial or see any failed test cases]
#ifndef LOCAL
#define NDEBUG
#endif
#include<tuple>
#include<queue>
#include<cassert>
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<unordered_map>

int nrow,ncol;
std::vector<std::vector<int>> a; // table

std::pair<int,int> find(int val){
	for(int r=0;;++r){
		auto const& row=a[r];
		auto iter=std::find(begin(row),end(row),val);
		if(iter!=end(row))
			return {r,iter-begin(row)};
	}
}

int val(int x,int y){ // if a[x][y]==val(x,y): correct
	return x*ncol+y+1;
}

int nops;
std::string ops;

enum orientation{ cw,ccw };
template<bool append>
void rot(int x,int y,orientation ori){ // xy: top left
	if(ori==cw)
		std::tie(a[x][y], a[x][y+1], a[x+1][y+1], a[x+1][y]) =
			std::make_tuple(a[x+1][y], a[x][y], a[x][y+1], a[x+1][y+1]);
	else
		std::tie(a[x+1][y], a[x][y], a[x][y+1], a[x+1][y+1]) =
			std::make_tuple(a[x][y], a[x][y+1], a[x+1][y+1], a[x+1][y]);

	if(append){ // to 'ops'
		std::stringstream ss;
		if(ori==cw)
			ss<<"4 "<<a[x+1][y]<<' '<<a[x][y]<<' '<<a[x][y+1]<<' '<<a[x+1][y+1]<<'\n';
		else
			ss<<"4 "<<a[x+1][y]<<' '<<a[x+1][y+1]<<' '<<a[x][y+1]<<' '<<a[x][y]<<'\n';
		ops+=ss.str();
		++nops;
	}
}

using i9=std::array<int,9>;
struct hash_i9{
	std::size_t operator()(i9 const& s)const{
		std::size_t out{43};
		for(int x:s)out=out*17+x;
		return out;
	}
};

i9 bkp_lower(){
	i9 out;
	auto iter=begin(out);
	for(int r=nrow-3;r<nrow;++r)
	for(int c=ncol-3;c<ncol;++c)
		*iter++=a[r][c];
	return out;
}

void res_lower(i9 st){
	auto iter=begin(st);
	for(int r=nrow-3;r<nrow;++r)
	for(int c=ncol-3;c<ncol;++c)
		a[r][c]=*iter++;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>nrow>>ncol;
	a.resize(nrow);
	for(auto& row:a){
		row.resize(ncol);
		for(int& x:row)std::cin>>x;
	}

	for(int r=0;r<nrow-3;++r){
		for(int c=0;c<ncol;++c){
			if(val(r,c)==a[r][c])
				continue;
			auto [x,y]=find(val(r,c));
			while(x>r){
				if(y<ncol-1){
					while(x==r+1 and y<c){
						rot<true>(x,y,cw);
						++y;
					}
					if(y<ncol-1){
						rot<true>(x-1,y,cw);
						--x;
					}else continue;
				}else if(c<ncol-1 or x>r+1){
					rot<true>(x-1,y-1,ccw);
					--x;
				}else{
					rot<true>(r+1,ncol-2,cw);
					rot<true>(r,ncol-2,cw);
					rot<true>(r+1,ncol-2,ccw);
					rot<true>(r,ncol-2,ccw);
					x=r;
					break;
				}
			}
			while(y>c){
				rot<true>(r,y-1,ccw);
				--y;
			}

			assert(val(r,c)==a[r][c]);
		}
	}

	for(int c=0;c<ncol-3;++c){
		for(int r=nrow-3;r<nrow;++r){
			if(val(r,c)==a[r][c])
				continue;
			auto [x,y]=find(val(r,c));
			while(y>c){
				if(x<nrow-1){
					while(y==c+1 and x<r){
						rot<true>(x,y,ccw);
						++x;
					}
					if(x<nrow-1){
						rot<true>(x,y-1,ccw);
						--y;
					}else continue;
				}else if(r<nrow-1 or y>c+1){
					rot<true>(x-1,y-1,cw);
					--y;
				}else{
					rot<true>(nrow-2,c+1,ccw);
					rot<true>(nrow-2,c  ,ccw);
					rot<true>(nrow-2,c+1,cw);
					rot<true>(nrow-2,c  ,cw);
					y=c;
					break;
				}
			}
			while(x>r){
				rot<true>(x-1,c,cw);
				--x;
			}

			assert(val(r,c)==a[r][c]);
		}
	}

	auto const target=bkp_lower();
	{
		std::unordered_map<i9,std::pair<int,int>,hash_i9> op; // brings state nearer to solved (with ccw)
		std::queue<i9> q;

		auto const solved=[]{
			for(int r=nrow-3;r<nrow;++r)
			for(int c=ncol-3;c<ncol;++c)
				a[r][c]=val(r,c);
			return bkp_lower();
		}();
		if(target==solved)
			goto done;

		op[solved]={-1,-1};
		q.push(solved);

		while(true){
			auto st=q.front();q.pop();
			for(int r=nrow-3;r<nrow-1;++r)
			for(int c=ncol-3;c<ncol-1;++c){
				res_lower(st);
				rot<false>(r,c,cw);
				auto s1=bkp_lower();
				if(not op.count(s1)){
					op[s1]={r,c};
					if(s1==target){
						while(true){
							auto [x,y]=op.at(s1);
							if(x<0){
								assert(s1==solved);
								goto done;
							}
							rot<true>(x,y,ccw);
							s1=bkp_lower();
						}
					}
					q.push(s1);
				}
			}
		}
	}

done:
	std::cout<<nops<<'\n'<<ops<<'\n';
}