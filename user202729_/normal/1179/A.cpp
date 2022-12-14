// I should really process my huge backlog of unsolved problems...
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nquery;std::cin>>n>>nquery;

	std::vector<int> a(n);for(int& x:a)std::cin>>x;

	struct query{
		int qind; int64_t val;
		bool operator<(query q)const{
			return val>q.val;
		}
	};
	std::vector<query> qs(nquery);
	for(int qind=0;qind<nquery;++qind){
		qs[qind].qind=qind;
		std::cin>>qs[qind].val;
		--qs[qind].val;
	}

	std::sort(begin(qs),end(qs));

	std::vector<std::pair<int,int>> out(nquery);
	int n_operations_done=0;
	int const maxa=*std::max_element(begin(a),end(a));
	int start=0; // the deque is represented with the array (a) and (start): a[start] = front

	bool worked=false;
	auto const work=[&]{
		assert(not worked);
		assert(a[start]==maxa);

		for(auto& [qind,nop]:qs){
			assert(nop>=n_operations_done);
			nop=(nop-n_operations_done)%(n-1)+n_operations_done;
			assert(nop>=n_operations_done);
		}
		std::sort(begin(qs),end(qs));

		worked=true;
	};

	while(not qs.empty()){
		auto const [qind,nop]=qs.back();
		qs.pop_back();
		while(n_operations_done<nop){
			auto& x=a[start];
			auto& y=a[start+1==n ? 0 : start+1];
			if(x>y)std::swap(x,y);
			start=start+1==n ? 0 : start+1;
			++n_operations_done;

			if(not worked and a[start]==maxa){
				qs.push_back({qind,nop});
				work();
				goto cont_outer;
			}
		}

		assert(n_operations_done==nop);
		out[qind]={
			a[start],
			a[start+1==n ? 0 : start+1]
		};

cont_outer:;
	}

	for(auto const [x,y]:out)std::cout<<x<<' '<<y<<'\n';
}