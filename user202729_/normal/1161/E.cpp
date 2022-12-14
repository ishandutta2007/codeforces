#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<algorithm>
#include<array>
#include<vector>

void merge(std::vector<int>& a,std::vector<int> b){
	if(a.size()<b.size())std::swap(a,b);
	a.insert(end(a),begin(b),end(b));
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		int n;std::cin>>n;
		struct group{
			std::vector<int> ind;
			bool e2; // grs[i].e2 = grs[i] equal to grs[i-2]?
		};

		std::vector<group> grs;
		{
			std::vector<char> eq(n-1); // eq[i] = coin (i+1) equal to (i+2)? 

			if(n/2){
				std::cout<<"Q "<<n/2;
				for(int i=2;i<=n;i+=2)std::cout<<' '<<i-1<<' '<<i;
				std::cout<<std::endl;
			}

			for(int i=2;i<=n;i+=2){
				char c;std::cin>>c;
				eq[i-2]=c=='1';
			}

			if((n-1)/2){
				std::cout<<"Q "<<(n-1)/2;
				for(int i=3;i<=n;i+=2)std::cout<<' '<<i-1<<' '<<i;
				std::cout<<std::endl;
			}

			for(int i=3;i<=n;i+=2){
				char c;std::cin>>c;
				eq[i-2]=c=='1';
			}

			grs.push_back({{1},false});
			for(int i=2;i<=n;++i)
				if(eq[i-2])
					grs.back().ind.push_back(i);
				else
					grs.push_back({{i},false});
			// right now e2 values are not correct
		}

		{ // compute e2
			for(int base:{2,4}){
				int nquery=0;
				for(unsigned i=base  ;i<grs.size();i+=4)++nquery;
				for(unsigned i=base+1;i<grs.size();i+=4)++nquery;

				if(nquery){
					std::cout<<"Q "<<nquery;
					for(unsigned i=base  ;i<grs.size();i+=4)std::cout<<' '<<grs[i-2].ind[0]<<' '<<grs[i].ind[0];
					for(unsigned i=base+1;i<grs.size();i+=4)std::cout<<' '<<grs[i-2].ind[0]<<' '<<grs[i].ind[0];
					std::cout<<std::endl;

					for(unsigned i=base  ;i<grs.size();i+=4){ char c; std::cin>>c; grs[i].e2=c=='1'; };
					for(unsigned i=base+1;i<grs.size();i+=4){ char c; std::cin>>c; grs[i].e2=c=='1'; };
				}
			}
		}

		while(grs.size()>3){
			if(grs.back().e2){
				merge(grs.end()[-3].ind, std::move(grs.back().ind));
				grs.pop_back();
			}
			else if(grs.end()[-2].e2){
				merge(grs.end()[-4].ind, std::move(grs.end()[-2].ind));
				grs.erase(grs.end()-2);
				assert(grs.back().e2==false);
			}
			else{
				merge(grs.end()[-4].ind, std::move(grs.back().ind));
				grs.pop_back();
			}
		}

		if(grs.size()==3){
			std::cout<<"Q 1 "<<grs[0].ind[0]<<' '<<grs[2].ind[0]<<std::endl;
			char c;std::cin>>c;
			if(c=='1'){
				merge(grs[0].ind, std::move(grs[2].ind));
				grs.pop_back();
			}
		}

		std::array<std::vector<int>,3> out;
		for(unsigned i=0;i<grs.size();++i)
			out[i]=std::move(grs[i].ind);
		grs.clear();

		std::cout<<'A';
		for(auto const& x:out)std::cout<<' '<<x.size();
		std::cout<<'\n';
		for(auto const& x:out){
			for(auto y:x)std::cout<<y<<' ';
			std::cout<<'\n';
		}
		std::cout<<std::flush;

	}
}