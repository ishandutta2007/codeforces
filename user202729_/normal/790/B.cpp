#ifndef LOCAL
#define NDEBUG
#endif
#include<array>
#include<numeric>
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

int n,k;
std::vector<std::vector<int>> ad;

std::vector<std::array<int,5>> downc; // [x][i] = number of nodes y int subtree of x s.t. dist(x,y)%k==i
std::array<int,5> dd(int x,int par){ // compute downc
	std::array<int,5> cnt{};
	++cnt[0];
	for(auto y:ad[x]){
		ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));
		auto cy=dd(y,x);
		for(int i=0;i<k-1;++i)
			cnt[i+1]+=cy[i];
		cnt[0]+=cy[k-1];
	}
	return downc[x]=cnt;
}

int64_t ans; // sum ceil(dist/k) for all (x,y) pair = 1/k * sum ( dist + (k-(dist%k))%k )
// de will compute result * k*2

void de(int x,std::array<int,5> cntall){
	// now cntall is for x
	int sts=std::accumulate(begin(downc[x]),begin(downc[x])+k,0);
	ans+=2*sts*int64_t(n-sts); // # path go through edge x .. par(x) - contribute to sum dist
	for(int mod=1;mod<k;++mod)
		ans+=cntall[mod]*(k-mod);

	std::rotate(begin(cntall),begin(cntall)+k-1,begin(cntall)+k); // each dist mod is += 1
	// prepare for cntally
	for(int y:ad[x]){
		auto cntally=cntall;
		auto const cnty=downc[y];
		for(int mod=0;mod<k;++mod){
			cntally[(mod+2)%k]-=cnty[mod];
			cntally[mod]+=cnty[mod];
		}
		de(y,cntally);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n>>k;
	ad.resize(n);
	for(int z=n,u,v;--z;){
		std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);ad[v].push_back(u);
	}

	downc.resize(n);
	dd(0,-1);
	ans=0;
	de(0,downc[0]);
	std::cout<<ans/(2*k)<<'\n';
}