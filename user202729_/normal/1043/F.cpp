// I still remember having read some similar problem before?... also involve gcd.

// {In contest: suddenly have an idea on the correct algorithm to solve the problem}
//
// I don't know if I could solve this problem if I just ignore G...
// after contest: inclusion/exclusion. => also related to Mobius transformation...
//
// Although the complexity is obviously less than 300000**2, I don't know if it can reach 300000 * 2**12...

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<climits>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);
	for(int& x:a){
		std::cin>>x;
		if(x==1){
			std::cout<<"1\n";
			return 0;
		}
	}
	std::sort(begin(a),end(a));
	a.erase(std::unique(begin(a),end(a)),end(a));
#define n _

	{
		int gcda=a[0];
		for(auto x:a) gcda=std::gcd(gcda,x);
		if(gcda!=1){ std::cout<<"-1\n"; return 0; }
	}

	auto minfactor=[&]{
		std::vector<int> minfactor(std::max(5,a.back()+1),INT_MAX);
		for(unsigned i=2;i<minfactor.size();++i)
			if(minfactor[i]==INT_MAX){
				minfactor[i]=i;
				for(auto j=i*(int64_t)i;j<(int)minfactor.size();j+=i)
					minfactor[j]=std::min<int>(minfactor[j],i);
			}
		return minfactor;
	}();

	for(int& x:a){ // make square-free
		int x1=1;
		while(x!=1){
			int p=minfactor[x];
			x1*=p;
			do{ x/=p; } while(x%p==0);
		}
		x=x1;

		assert(x>1);
		//if(x==minfactor[x]){ std::cout<<"2\n"; return 0; }
	}
	std::sort(begin(a),end(a));
	a.erase(std::unique(begin(a),end(a)),end(a));

	if(0){ //unnecessary
		std::vector<char> have_proper_divisor_in_a(a.back()+1);
		for(int x:a)
			for(unsigned y=x*2;y<have_proper_divisor_in_a.size();y+=x)
				have_proper_divisor_in_a[y]=true;
		a.erase(std::remove_if(begin(a),end(a),[&](int x){ return have_proper_divisor_in_a[x]; }),
				end(a));
	}

	std::vector<char> in_a(a.back()+1);
	for(int x:a) in_a[x]=true;

	std::vector<int> n_multiples_in_a(a.back()+1);
	for(unsigned x=1;x<n_multiples_in_a.size();++x)
		for(unsigned y=x;y<n_multiples_in_a.size();y+=x)
			n_multiples_in_a[x]+=in_a[y];
	assert((int)a.size()==n_multiples_in_a[1]);

	int out=INT_MAX;
	for(auto v:a){
		std::vector<int> primes;
		for(int y=v;y!=1;){
			primes.push_back(minfactor[y]);
			y/=minfactor[y];
		}

		std::vector<int> mask_to_val(1<<primes.size()); // product of primes with corresponding bit on
		std::vector<int> cnt(1<<primes.size());
		mask_to_val[0]=1; cnt[0]=(int)a.size();
		for(int mask=1;mask<(1<<primes.size());++mask){
			mask_to_val[mask]=mask_to_val[mask xor (mask&-mask)]*primes[__builtin_ctz(mask)];
			cnt[mask]=n_multiples_in_a[mask_to_val[mask]];
		}

		for(unsigned bit=0;bit<primes.size();++bit)
		for(int maskcomp=1<<(primes.size()-1);maskcomp--;){
			int const lowmask=(maskcomp&(~((1<<bit)-1)))<<1|(maskcomp&((1<<bit)-1)); // TODO benchmark
			int const highmask=lowmask|(1<<bit);
			cnt[lowmask]-=cnt[highmask];
		}

		for(unsigned mask=0;mask<cnt.size();++mask){
			assert(cnt[mask]==std::count_if(begin(a),end(a),[&](int ai){
						return std::gcd(ai,v)==mask_to_val[mask];
						}));
		}

		std::vector<int> minnval(1<<primes.size(),INT_MAX-1);
		minnval.back()=1;
		// minnval[reached mask] = min number of chosen numbers (including v)

		for(int i=0;i<(1<<primes.size());++i){
			if(cnt[i]!=0){
				assert(cnt[i]>0);
				for(int prevreach=0;prevreach<(1<<primes.size());++prevreach)
					minnval[prevreach&i]=std::min(minnval[prevreach&i],
							minnval[prevreach]+1);
			}
		}
		out=std::min(out,minnval[0]);
	}
	std::cout<<out<<'\n';
}