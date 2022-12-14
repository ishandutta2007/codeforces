#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<climits>
#include<iostream>
#include<vector>
#include<algorithm>

int n;
std::vector<char> a;
std::vector<std::pair<int,int>> flipped;

void flip(int cen,int rad){
	assert(rad>0);
	a[cen]^=1;
	a[cen-rad]^=1;
	a[cen+rad]^=1;

	std::pair<int,int> op{cen,rad};
	if(flipped.empty() or flipped.back()!=op)
		flipped.push_back(op);
	else
		flipped.pop_back();
}

bool valid(int cen,int rad){
	assert((int)a.size()==n);
	return cen-rad>=0 and cen+rad<n;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int dbg_min=INT_MAX;
	while(std::cin>>n){
		flipped.clear();
		a.resize(n);
		for(char& c:a) std::cin>>c;
		std::string abkp; assert((abkp.assign(begin(a),end(a)), true));
		for(char& c:a) c=char(c-'0');

		int i=0; // n. of leading zero

		auto const nxti=[](int i){
			return int(std::find(begin(a)+i,end(a),1)-begin(a));
		};

		int const MAXRAD=5;

		while(true){
			i=nxti(i);
			if(i==n)break;
			for(int cen=i;cen<i+10;++cen) for(int rad=1;rad<=MAXRAD;++rad) if(valid(cen,rad)){
				flip(cen,rad);
				if(nxti(std::max(0,i-MAXRAD))>=i+3)
					goto cont_outer;
				else
					flip(cen,rad);
			}

			for(int cen=i;cen<i+10;++cen) for(int rad=1;rad<=MAXRAD;++rad) if(valid(cen,rad))
			for(int cen2=cen;cen2<i+10;++cen2) for(int rad2=1;rad2<=MAXRAD;++rad2) if(valid(cen2,rad2)){
				flip(cen,rad); flip(cen2,rad2);
				if(nxti(std::max(0,i-MAXRAD))>=i+6)
					goto cont_outer;
				else{
					flip(cen2,rad2); flip(cen,rad);
				}
			}

			break;

	cont_outer:;
		}

		/*
		assert(([&]{
			if(i<dbg_min){
				dbg_min=i;
				std::cerr<<"NOTE "<<i<<' '<<std::string(begin(abkp),end(abkp))<<'\n';
			}
			return true;
		}()));
		*/

		assert(nxti(0)>=i);

		while(true){
			i=nxti(i);
			if(i==n)break;
			if(i<=n-3){
				flip(i+1,1);
			}else if(i==n-2){
				if(n<8){
					std::cout<<"NO\n";
					goto nexttest;
				}
				flip(n-5,3);
				flip(n-7,1);
				flip(n-6,1);
			}else if(i==n-1){
				if(n<7){
					std::cout<<"NO\n";
					goto nexttest;
				}
				flip(n-4,3);
				flip(n-6,1);
				flip(n-5,1);
			}

			assert(nxti(0)>=i);
			i=nxti(i);
		}

		assert((int)flipped.size()<=n/3+12 || !(std::cerr<<abkp<<std::endl));

		assert(nxti(0)==n || !(std::cerr<<abkp<<std::endl));
		assert(std::all_of(begin(a),end(a),[](char x){return x==0;}));

		std::cout<<"YES\n"<<flipped.size()<<'\n';
		for(auto [cen,rad]:flipped)
			std::cout
				<<cen+1-rad<<' '
				<<cen+1<<' '
				<<cen+1+rad<<'\n';

nexttest:;
	}
}