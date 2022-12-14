#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<vector>
#include<array>
#include<limits>
#include<random>
#include<cassert>
#include<unordered_map>

// 1-indexing
struct bit2d{
	bit2d(int n,int m):n(n),m(m),data(n*m){}
	void add(int a,int b,unsigned delta){
		for(int a1=a;a1<=n;a1+=a1&-a1)
		for(int b1=b;b1<=m;b1+=b1&-b1)
			g(a1,b1)+=delta;
	}
	unsigned get(int a,int b){
		unsigned ans=0;
		for(int a1=a;a1!=0;a1-=a1&-a1)
		for(int b1=b;b1!=0;b1-=b1&-b1)
			ans+=g(a1,b1);
		return ans;
	}
private:
	int n,m;
	std::vector<unsigned> data;
	unsigned& g(int a,int b){
		assert(1<=a);
		assert(1<=b&&b<=m);
		return data[(a-1)*m+b-1];
	}
};

std::mt19937 engine(123456);
unsigned urand(){
	return std::uniform_int_distribution<unsigned>(
		std::numeric_limits<unsigned>::min(),
		std::numeric_limits<unsigned>::max())(engine);
}

using barrier=std::array<int,4>;
struct barrier_hash{
	std::size_t operator()(barrier b)const{
		std::size_t ans=43;
		for(int x:b)
			ans=ans*2503+x;
		return ans;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m,nquery;std::cin>>n>>m>>nquery;
	bit2d data(n,m);
	std::unordered_map<barrier,unsigned,barrier_hash> barriers;
	while(nquery-->0){
		char type;
		int r1,c1,r2,c2;
		std::cin>>type>>r1>>c1>>r2>>c2;
		if(type=='3'){
			std::cout<<(data.get(r1,c1)==data.get(r2,c2)?"Yes\n":"No\n");
			continue;
		}
		++r2;++c2;
		barrier b{{r1,c1,r2,c2}};
		unsigned val;
		if(type=='2'){
			auto iter=barriers.find(b);
			val=-iter->second;
			barriers.erase(iter);
		}else{
			val=urand();
			barriers.emplace(b,val);
		}
		data.add(r1,c1,val);
		data.add(r1,c2,-val);
		data.add(r2,c1,-val);
		data.add(r2,c2,val);
	}
}