#ifndef LOCAL
#define NDEBUG
#endif
#include<array>
#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>

std::vector<std::array<int,26>> t;

int nreduce(auto first,auto last){ // last-first <= 26
	int const n=last-first;
	if(n<=1)
		return 0;
	int ans=n-1;

	std::array<int,26> cs;
	for(int c=0;c<26;++c){
		auto out=begin(cs);
		for(auto iter=first;iter!=last;++iter){
			int x=*iter;
			if(t[x][c])
				*out++=t[x][c];
		}
		ans+=nreduce(begin(cs),out);
	}

	return ans;
}

std::vector<int> ans; // reduction per depth

void dd(int x,int depth){ // return subtreesize
	auto z=t[x];
	auto last=std::remove(begin(z),end(z),0);

	if(last==begin(z)) return;
	ans[depth]+=nreduce(begin(z),last)+1; // merge with node x

	//int sts=1;
	for(auto iter=begin(z);iter!=last;++iter){
		int y=*iter;
		dd(y,depth+1);
	}
	//return sts;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	t.resize(n);
	for(int z=n;--z;){
		int u,v;char c;std::cin>>u>>v>>c;
		--u;--v;
		t[u][c-'a']=v;
	}

	ans.resize(n);
	dd(0,0);
	auto iter=std::max_element(begin(ans),end(ans));
	std::cout<<n-*iter<<'\n'<<iter-begin(ans)+1<<'\n';
}