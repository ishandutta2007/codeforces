#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<cassert>
#include<array>
#include<vector>
#include<iostream>

std::string s;
std::vector<int> pow3;
std::vector<int> cc;
std::vector<int> cnt;

auto req=[]{
	// prepare lookup table
	auto const comp=[](char name,int x,int y)->bool{
		bool flip=false;
		if(name>'Z'){
			name=name-'a'+'A';
			flip=true;
		}
		return (name=='A' ? (x&y) : name=='O' ? (x|y) : (x^y)) ^ flip;
	};

	std::array<std::array<int,2>,128> req; // [name][x] = y s.t. comp(name,x,y)==0
	std::array<char,6> names{{'A','O','X','a','o','x'}};
	for(char name:names){
		for(int x=0;x<2;++x){
			req[name][x]=0;
			for(int y=0;y<2;++y){
				if(comp(name,x,y)==0)
					req[name][x]|=1<<y;
			}
			--req[name][x];
		}
	}
	
	return req;
}();

int64_t out;
void backtrack(int pos,int x,int val){
	if(pos==(int)s.size()){
		out+=cnt[val]*(int64_t)cc[x];
		return;
	}

	for(int bit=0;bit<2;++bit){
		int dig=req[s[pos]][bit];
		if(dig<0)
			continue;
		assert(dig<=2);

		backtrack(pos+1,x+(bit<<pos),val+pow3[pos]*dig);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int w,n,m;std::cin>>w>>n>>m;

	pow3.resize(w+1);
	pow3[0]=1;
	for(int i=1;i<=w;++i)pow3[i]=pow3[i-1]*3;

	cc.resize(1<<w); // cnt but bit only
	cnt.resize(pow3[w]); // each trit: 0, 1, both
	for(int z=n;z--;){
		int ai;std::cin>>ai;
		++cc[ai];
		int a3=0;
		for(int i=w;i--;)
			a3=a3*3+(ai>>i&1);
		++cnt[a3];
	}

	for(int i=w;i--;){
		for(unsigned a=0;a<cnt.size();a+=pow3[i+1])
			for(unsigned b=a;b<a+pow3[i];++b)
				cnt[b+2*pow3[i]]+=cnt[b]+cnt[b+pow3[i]];
	}


	for(int z=m;z--;){
		std::cin>>s;
		std::reverse(begin(s),end(s));
		out=0;
		backtrack(0,0,0);
		std::cout<<out<<'\n';
	}
}