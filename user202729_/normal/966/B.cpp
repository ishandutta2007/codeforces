/*
 * While implementing easy problems doesn't help int hard contests, there's some surprisingly tricky
 * "easy" problems...
 * but int this case perhaps I'm just practicing for Codeforces contests.
 * (...)
 *
 * ========
 *
 * Is it too slow to solve 2 easy problems int 30 minutes?...
 */

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,x1,x2;std::cin>>n>>x1>>x2;

	struct server{
		int pow,id; // id: 1-indexing
		bool operator<(server x)const{ return pow<x.pow; }
	};
	std::vector<server> c(n);
	std::generate(begin(c),end(c),[id=0]() mutable { int pow;std::cin>>pow;return server{pow,++id}; });
	std::sort(begin(c),end(c));

	for(int swapped=0;swapped<2;++swapped,std::swap(x1,x2)){
		// assume x1 = service that has the larger req
		for(int nuse1=1;nuse1<n;++nuse1){
			int req1=(x1+nuse1-1)/nuse1;
			if(end(c)[-nuse1].pow>=req1){
				// least satisfied nuse1
				for(int nuse2=1;nuse1+nuse2<=n;++nuse2){
					int req2=(x2+nuse2-1)/nuse2;
					if(end(c)[-nuse1-nuse2].pow>=req2){
						// found assignment
						std::cout<<"Yes\n";

						auto const print_id=[](server x){ std::cout<<x.id<<' '; };

						if(swapped){
							std::cout<<nuse2<<' '<<nuse1<<'\n';
							std::for_each(end(c)-nuse1-nuse2,end(c)-nuse1,print_id);
							std::cout<<'\n';
							std::for_each(end(c)-nuse1,end(c),print_id);
							std::cout<<'\n';
						}else{
							std::cout<<nuse1<<' '<<nuse2<<'\n';
							std::for_each(end(c)-nuse1,end(c),print_id);
							std::cout<<'\n';
							std::for_each(end(c)-nuse1-nuse2,end(c)-nuse1,print_id);
							std::cout<<'\n';
						}

						return 0;
					}
				}
				break;
			}
		}
	}
	std::cout<<"No\n";
}