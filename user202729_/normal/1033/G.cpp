// [I didn't read the editorial or see any failed test cases]
#ifndef LOCAL
#define NDEBUG
#endif
#include<vector>
#include<algorithm>
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;
	std::vector<int64_t> v(n);for(int64_t& x:v)std::cin>>x;

	int64_t wa=0,wb=0,wf=0,wz=0;

	// consider a==b
	for(int a=1;a<=m;++a){
		auto grundyvalue=1&std::count_if(begin(v),end(v),[a](int64_t /* not int. For some reason the compiler doesn't emit a warning even with -Wconversion and optimization turned on */ x){return (x/a)&1;});
		++(grundyvalue ? wf : wz);
	}

	// consider a!=b
	for(int sum=3;sum<2*m;++sum){
		int mina=std::max(1,sum-m);
		int maxa=std::min(m,(sum-1)/2); // [mina..maxa] inclusive. (this was a bad choice, [mina..maxa[ is better)
		assert(mina<=maxa);
		assert(mina<sum-mina);
		assert(maxa<sum-maxa);

		auto v1=v;
		for(auto& x:v1)x%=sum;
		std::sort(begin(v1),end(v1));

		// binary search can be replaced with O(1) operation...
		{
			int a1=mina-1;
			auto const a1_ok=[&](int a){ // for a (possibly empty) prefix of [mina..maxa]
				if(a>maxa)return false;
				int const b=sum-a;
				auto n_atleast_a=std::count_if(begin(v1),end(v1),[&](int x){return x>=a;});
				// I spent about 30 minutes just because I used v instead of v1 here :(
				auto n_atleast_b=std::count_if(begin(v1),end(v1),[&](int x){return x>=b;});
				return n_atleast_a>n_atleast_b;
			};
			for(int step=1<<20;step;step>>=1)
				if(a1_ok(a1+step))
					a1+=step;

			int const cnt=a1-mina+1;
			for(int a=mina;a<=a1;++a)assert(a1_ok(a));
			assert(cnt>=0);
			wa+=cnt;
			wb+=cnt;
			mina=a1+1;
		}

		{
			int a1=maxa+1;
			auto const a1_ok=[&](int a){ // for a (possibly empty) suffix of [mina..maxa]
				if(a<mina)return false;
				auto n_atleast_a=std::count_if(begin(v1),end(v1),[&](int x){return x>=a;});
				return n_atleast_a==0;
			};
			for(int step=1<<20;step;step>>=1)
				if(a1_ok(a1-step))
					a1-=step;

			int const cnt=maxa-a1+1;
			for(int a=a1;a<=maxa;++a)assert(a1_ok(a));
			assert(cnt>=0);
			wz+=2*cnt;
			maxa=a1-1;
		}

		{
			int a1=mina-1;
			auto const a1_ok=[&](int a){ // for a (possibly empty) prefix of [mina..maxa]
				if(a>maxa)return false;
				auto n_atleast_2a=std::count_if(begin(v1),end(v1),[&](int x){return x>=2*a;});
				return n_atleast_2a>=2;
			};
			for(int step=1<<20;step;step>>=1)
				if(a1_ok(a1+step))
					a1+=step;

			int const cnt=a1-mina+1;
			for(int a=mina;a<=a1;++a)assert(a1_ok(a));
			assert(cnt>=0);
			wa+=cnt;
			wb+=cnt;
			mina=a1+1;
		}

		{
			int a1=mina-1;
			auto const a1_ok=[&](int a){ // for a (possibly empty) prefix of [mina..maxa]
				if(a>maxa)return false;
				auto n_atleast_2a=std::count_if(begin(v1),end(v1),[&](int x){return x>=2*a;});
				return n_atleast_2a==1;
			};
			for(int step=1<<20;step;step>>=1)
				if(a1_ok(a1+step))
					a1+=step;

			int const cnt=a1-mina+1;
			for(int a=mina;a<=a1;++a)assert(a1_ok(a));
			assert(cnt>=0);
			{
				int minb=sum-a1,maxb=sum-mina;
				assert(maxb-minb+1>=0);
				int n_atleast_b=0;

				for(auto i=v1.size();i--;){
					auto const v1_i=v1[i];

					int const minb1=int(v1_i+1); // v1 is modded by a+b, cannot overflow

					for(int b=minb1;b<=maxb;++b)
						assert(n_atleast_b==std::count_if(begin(v1),end(v1),[&](int x){return x>=b;}));

					int const cnt1=std::max(0,maxb-std::max(minb,minb1)+1);
					if(n_atleast_b%2!=0){
						wf+=2*cnt1;
					}else{
						wa+=cnt1;
						wb+=cnt1;
					}

					++n_atleast_b;
					maxb-=cnt1;
					if(minb>maxb)
						break;
				};

				assert(maxb-minb+1>=0);
				if(minb<=maxb){
					int const cnt1=maxb-minb+1;
					if(n_atleast_b%2!=0){
						wf+=2*cnt1;
					}else{
						wa+=cnt1;
						wb+=cnt1;
					}
				}
			}
			mina=a1+1;
		}

		assert(maxa-mina+1>=0);
		int minb=sum-maxa,maxb=sum-mina;
		assert(maxb-minb+1>=0);
		int n_atleast_b=0;

		for(auto i=v1.size();i--;){
			auto const v1_i=v1[i];

			int const minb1=int(v1_i+1); // v1 is modded by a+b, cannot overflow

			for(int b=minb1;b<=maxb;++b)
				assert(n_atleast_b==std::count_if(begin(v1),end(v1),[&](int x){return x>=b;}));

			int const cnt=std::max(0,maxb-std::max(minb,minb1)+1);
			(n_atleast_b&1 ? wf : wz)+=2*cnt;

			++n_atleast_b;
			maxb-=cnt;
			if(minb>maxb)
				break;
		};

		assert(maxb-minb+1>=0);
		if(minb<=maxb){
			int const cnt=maxb-minb+1;
			(n_atleast_b&1 ? wf : wz)+=2*cnt;
		}
	}

	std::cout<<wa<<' '<<wb<<' '<<wf<<' '<<wz<<'\n';
}