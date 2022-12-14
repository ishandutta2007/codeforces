#include<iostream>
#include<array>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

int const NBIT=60;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int64_t> a(n);
	std::array<int,NBIT> cnt{};
	for(auto& x:a){
		std::cin>>x;
		for(int i=0;i<NBIT;++i)
			cnt[i]+=x>>i&1;
	}
	if(std::any_of(begin(cnt),end(cnt),[](int x){return x>=3;})){
		std::cout<<"3\n";
		return 0;
	}

	std::vector<std::vector<int>> ad(n);

	for(int i=0;i<NBIT;++i){
		auto const hasbiti=[i](int64_t x){return x>>i&1;};
		auto i1=std::find_if(begin(a),end(a),hasbiti);
		if(i1!=end(a)){
			auto i2=std::find_if(std::next(i1),end(a),hasbiti);
			if(i2!=end(a)){
				auto u=i1-begin(a),v=i2-begin(a);
				ad[u].push_back(v);ad[v].push_back(u);
			}
		}
	}

	std::vector<int> d;
	int ans=INT_MAX;
	for(int i=0;i<n;++i)
	for(int j:ad[i])if(j>i){
		std::queue<int> q;
		d.assign(n,-1);
		q.push(i);d[i]=0;
		while(!q.empty()){
			int x=q.front();q.pop();
			if(x==j){
				ans=std::min(ans,d[x]+1);
				break;
			}
			for(int y:ad[x])if(d[y]<0&&!(x==i&&y==j)){
				q.push(y);
				d[y]=d[x]+1;
			}
		}
	}
	std::cout<<(ans==INT_MAX?-1:ans)<<'\n';
}