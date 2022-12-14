#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>

#include<iostream>
#include<array>
#include<vector>
#include<algorithm>

#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
2 5
1 3 4
2 2 3
)");}
#endif // Sublime


int constexpr NROW=3,MOD=int(1e9+7);
template<class T,size_t a>using ar=std::array<T,a>;
template<size_t M,size_t N>using mat=ar<ar<int,N>,M>;

void addi(int&x,int y){
	assert(0<=x&&x<MOD);
	assert(0<=y&&y<MOD);
	x+=y;if(x>=MOD)x-=MOD;
}
void addi(int&x,int64_t y){
	assert(y>=0);
	x=(x+y)%MOD;
}

template<size_t M,size_t N,size_t P>
auto matmul(mat<M,N>const a,mat<N,P>const b){
	mat<M,P>c{};
	for(size_t i=0;i<M;++i)for(size_t j=0;j<N;++j)\
	for(size_t k=0;k<P;++k)
		addi(c[i][k],a[i][j]*(int64_t)b[j][k]);
	return c;
}
template<size_t N>
auto matpow(mat<N,N>base,int64_t exp){
	mat<N,N>result{};for(size_t i=N;i-->0;)result[i][i]=1;
	assert(exp>=0);
	while(true){
		if(exp&1)result=matmul(result,base);
		exp>>=1;
		if(exp==0)return result;
		base=matmul(base,base);
	}
}

int main(){ // program start
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n_obstacle;int64_t ncol;std::cin>>n_obstacle>>ncol;
	struct event{int row;bool open;int64_t col;
		bool operator<(event e)const{return col<e.col;}};
	std::vector<event>events;events.reserve(2*n_obstacle+1);
	for(int _=n_obstacle;_-->0;){ // ~ 10^4 ops
		int a;int64_t l,r;std::cin>>a>>l>>r;
		--a;--l;--r;
		events.push_back({a,true,l});
		events.push_back({a,false,r});
	}
	std::sort(events.begin(),events.end()); // ~ 10^4*log
	events.push_back({0,true,ncol-1});//dummy element

	mat<NROW,NROW>base_trans{}; // O(1)
	for(int i=0;i<NROW;++i)for(int j=std::max(0,i-1);
		j<std::min(NROW,i+2);++j)
		base_trans[i][j]=1;

	mat<1,NROW>ans{};ans[0][1]=1;
	mat<NROW,NROW>trans=base_trans;

	int64_t col=0;
	ar<int,NROW>depth{};
	for(event e:events){ // O(n) ~= 2e4
		//forward (col) to (e.col)
		if(e.col!=col){ // e.col must be >col
			ans=matmul(ans,matpow(trans,e.col-col));
			col=e.col;
		}

		if(e.open){
			if(depth[e.row]++==0){
				ans[0][e.row]=0;
				for(int i=0;i<NROW;++i)
					trans[i][e.row]=0;
			}
		}else{
			if(0==--depth[e.row]){
				for(int i=0;i<NROW;++i)
					trans[i][e.row]=base_trans[i][e.row];
			}
		}
	}
	std::cout<<ans[0][1]<<'\n';
}