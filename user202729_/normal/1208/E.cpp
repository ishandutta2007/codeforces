#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<vector>
#include<deque>
#include<climits>
#include<cassert>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int narr,w;std::cin>>narr>>w;

	struct item{
		int i,val;
	};

	std::vector<int64_t> acm(w+1);

	auto const work=[&](){
		for(int i=1;i<w;++i)
			acm[i]+=acm[i-1];
	};

	auto const addrange=[&](int l,int r,int64_t del){
		//assert(std::cerr<<l<<' '<<r<<" -> "<<del<<'\n');
		acm[l]+=del;
		acm[r]-=del;
	};

	std::vector<int> a;a.reserve(w);
	for(int _=narr;_--;){
		int n;std::cin>>n;
		a.resize(n);
		for(auto& x:a)std::cin>>x;
		if(w-n /* min range segment size */ >n /* total of nonzero values */){
			// must process quickly, there are a bunch of equal max ranges
			// also all element could be 0
			int maxpart=0;
			for(int i=0;i<n;++i){
				maxpart=std::max(maxpart,a[i]);
				addrange(i,i+1,maxpart);
			}

			maxpart=0;
			for(int i=n;i--;){
				maxpart=std::max(maxpart,a[i]);
				addrange(w-n+i,w-n+i+1,maxpart);
			}

			addrange(n,w-n,maxpart);
		}else{
			int i=0;

			int r=0;
			int l=n-w;
			std::deque<item> is; // back = max ind, min val
			if(l<0)
				is.push_back({-1,0});

			while(i<w){
				// compute range for new i
				item newi{r,r<n?a[r]:0};
				while(!is.empty()&&is.back().val<=newi.val)
					is.pop_back();
				is.push_back(newi);
				++r;


				while(is.front().i<l)
					is.pop_front();
				++l;

				//assert(std::cerr<<i<<' '<<l<<' '<<r<<'\n');


				addrange(i,i+1,is.front().val);
				++i;
			}
		}
	}

	work();
	acm.pop_back();
	for(auto x:acm)std::cout<<x<<' ';
	std::cout<<'\n';
}