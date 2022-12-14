//http://codeforces.com/contest/1023/problem/D
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#ifdef _GLIBCXX_DEBUG
#define cin cin_
#include<sstream>
namespace std{std::stringstream cin(R"(
3 5
0 0 0

)");}
#endif

struct rmq{
	std::vector<std::vector<int>>data;
	rmq(std::vector<int>x):data{{std::move(x)}}{
		for(int l=1;;l<<=1){
			auto const& lBlocksMin(data.back());
			if(int(lBlocksMin.size())-l<0)break;
			std::vector<int> l2BlocksMin(lBlocksMin.size()-l);
			for(unsigned i=l2BlocksMin.size();i--;)
				l2BlocksMin[i]=std::min(lBlocksMin[i],lBlocksMin[i+l]);
			data.push_back(std::move(l2BlocksMin));
		}
	}
	int get(int l,int r){ // [l..r[
		int layer=31^__builtin_clz(r-l);
		return std::min(data[layer][l],data[layer][r-(1<<layer)]);
	}
};

int constexpr INF=1e9;
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,q;std::cin>>n>>q;
	std::set<int>undef_pos;
	std::vector<int>a(n);
	for(int i=0;i<n;++i){
		std::cin>>a[i];
		if(a[i]==0){
			a[i]=INF;
			undef_pos.insert(i);
		}
	}

	rmq rmq_a(a);
	int an_undef_pos=undef_pos.empty()?-1:*undef_pos.begin();

	// fill first_ocr and last_ocr table
	std::vector<int>first_ocr(q+1,-1),last_ocr(q+1);
	for(int i=0;i<n;++i){
		int const x=a[i];if(x==INF)continue;
		if(first_ocr[x]<0)first_ocr[x]=i;
		last_ocr[x]=i;
	}

	// fill a[undef_pos]
	for(int i=q;i;--i){
		if(first_ocr[i]<0||first_ocr[i]==last_ocr[i])continue;
		if(rmq_a.get(first_ocr[i],last_ocr[i])<i){
			std::cout<<"NO\n";
			return 0;
		}
		auto first_it=undef_pos.lower_bound(first_ocr[i]);
		auto last_it=undef_pos.lower_bound(last_ocr[i]);
		for(auto it=first_it;it!=last_it;++it)
			a[*it]=i;
		undef_pos.erase(first_it,last_it);
	}
	for(int i:undef_pos)a[i]=1;

	if(std::find(a.begin(),a.end(),q)==a.end()){ // if not found
		if(an_undef_pos<0){
			std::cout<<"NO\n";
			return 0;
		}else{
			a[an_undef_pos]=q;
		}
		
	}

	// output
	std::cout<<"YES\n";
	for(int x:a)std::cout<<x<<' ';
	std::cout<<'\n';
}