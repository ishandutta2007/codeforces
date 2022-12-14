#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<random>
#include<cassert>
#include<algorithm>
#include<vector>
#include<cmath>

int64_t constexpr mul(int64_t a,int64_t b,int64_t mod){
	int64_t ans=0;
	assert(b>=0);
	while(true){
		if(b&1){
			ans+=a;
			if(ans>=mod)ans-=mod;
		}
		if((b>>=1)==0)return ans;
		a+=a;
		if(a>=mod)a-=mod;
	}
}

int64_t pow(int64_t base,int64_t exp,int64_t mod){
	int64_t ans=1;
	assert(exp>=0);
	while(true){
		if(exp&1)ans=mul(ans,base,mod);
		if((exp>>=1)==0)return ans;
		base=mul(base,base,mod);
	}
}

std::mt19937 engine(123456);

bool probable_prime(int64_t const x,int64_t seed){
	// return false if x is definitely composite, true if x may be a prime
	assert(x>3);
	assert(std::__gcd(seed,x)==1);
	int64_t f=x-1;

	int ctz=__builtin_ctzll(f);
	int64_t y=pow(seed,f>>ctz,x);
	if(y==1)
		return true;
	for(int _=ctz;_--;){
		auto y_sqr=mul(y,y,x);
		if(y_sqr==1)
			return y==x-1;
		y=y_sqr;
	}
	return false;
}

// returns any factor of x (may return x if fail)
int64_t factorize(int64_t x){ // pollard rho algorithm. Slow if x is a prime.
	auto const f=[x](int64_t a){
		// return ((__int128)a*a+1)%x;
		a=mul(a,a,x);
		if(a==x-1)return (int64_t)0;else return a+1;
	};

	int64_t hare=std::uniform_int_distribution<int64_t>(0,x-1)(engine);
	int64_t tort=hare;
	while(true){
		hare=f(f(hare));
		tort=f(tort);
		auto gcd=std::__gcd(std::abs(hare-tort),x);
		if(gcd!=1)
			return gcd;
	}
}

std::vector<int64_t> factors;
void factorize_all_large(int64_t x){ // x must not have too small factors otherwise factorize may fail
	if(x==1)return;

	for(int _=0;_<5;++_)
		if(!probable_prime(x,std::uniform_int_distribution<int64_t>(2,x-2)(engine))){
			int64_t y;
			do{
				y=factorize(x);
			}while(y==x||y==1);
			factorize_all_large(y);
			factorize_all_large(x/y);
			return;
		}

	factors.push_back(x);
}

void factorize_all(int64_t x){ // push into factors
	for(int i=2;i<100;++i)
		while(x%i==0){
			x/=i;
			factors.push_back(i);
		}
	factorize_all_large(x);
}

int64_t mod;
int64_t q;int e; // mod = q ^ e (q is a prime)
int64_t phi_mod;
int64_t carmichael_mod;
std::vector<int64_t> carmichael_m_pfs; // prime factors of carmichael(mod) -- also prime factors of phi(mod)

bool is_max_order(int64_t x){
	assert(std::__gcd(x,mod)==1);
	assert(mod%q==0);
	assert(pow(x,carmichael_mod,mod)==1);
	for(int64_t z:carmichael_m_pfs){
		assert(carmichael_mod%z==0);
		if(pow(x,carmichael_mod/z,mod)==1)
			return false;
	}
	return true;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int npass;int64_t p;std::cin>>npass>>mod>>p;

	q=mod;e=1;
	for(int e_=2;e_<70;++e_){
		auto q_=(int64_t)std::round(std::pow(mod,1./e_));
		if(std::pow(q_,e_)<=2.*(double)mod /* avoid possible overflow? */){
			int64_t pow_q_e=1;
			for(int _=e_;_--;)pow_q_e*=q_;
			if(pow_q_e==mod){
				q=q_;e=e_;
			}
		}
	}
	phi_mod=mod/q*(q-1);
	carmichael_mod=mod/q*(q-1); if(q==2&&mod>=8)carmichael_mod/=2;

	if(npass>phi_mod-1 /* there are phi_mod numbers coprime with mod, and 1 cannot be a password */){
		std::cout<<"-1\n";
		return 0;
	}
	if(p%q==0){
		for(int x=2;x<mod;++x)
			if(x%q!=0){
				std::cout<<x;
				if(--npass==0){
					std::cout<<'\n';
					return 0;
				}else{
					std::cout<<' ';
				}
			}
		assert(false);
	}

	if(mod<10000000){
		std::vector<char> mark(mod); // mark = invalid password
		for(int x=0;x<(int)mod;x+=(int)q)
			mark[x]=true;
		for(int x=(int)p;x!=1;x=int(x*(int64_t)p%mod))
			mark[x]=true;
		mark[1]=true;
		
		if(std::count(begin(mark),end(mark),0)<npass){
			std::cout<<"-1\n";
			return 0;
		}
		for(int x=0;x<mod;++x)
			if(!mark[x]){
				std::cout<<x;
				if(--npass==0){
					std::cout<<'\n';
					return 0;
				}else{
					std::cout<<' ';
				}
			}
		return 0;
	}

	// phi(m) = q^(e-1) * (q-1)
	// TODO consider q=2?
	factors.clear();
	factorize_all(q-1);
	std::sort(begin(factors),end(factors));
	if(e>1)
		carmichael_m_pfs.push_back(q);
	carmichael_m_pfs.insert(end(carmichael_m_pfs), begin(factors),std::unique(begin(factors),end(factors)));
	factors.clear(); // unnecessary, avoid bugs

	if(is_max_order(p)){
		if(carmichael_mod==phi_mod){ // p is a primitive root modulo mod
			std::cout<<"-1\n";
			return 0;
		}

		assert(mod%8==0);
		assert(pow(p,mod/4,mod)==1);
		auto zzp=pow(p,mod/8,mod);
		assert(zzp!=1);

		int64_t q=mod-p;
		// now q is a valid password, and so is q*p, q*p**2, ...
		for(int64_t x=q;;x=mul(x,p,mod)){
			std::cout<<x;
			if(--npass==0){
				std::cout<<'\n';
				return 0;
			}else{
				std::cout<<' ';
			}
		}
	} // otherwise any max-order number is a valid password

	int64_t a_max_order_base;
	do{
		a_max_order_base=std::uniform_int_distribution<int64_t>(2,mod-1)(engine);
		//std::cerr<<" ** "<<a_max_order_base<<'\n';
	}while(std::__gcd(a_max_order_base,mod)!=1||!is_max_order(a_max_order_base));

	{
		int exp=1;
		int64_t x=a_max_order_base;
		for(;;x=mul(x,a_max_order_base,mod),++exp){
			if(std::__gcd((int64_t)exp,phi_mod)==1){
				std::cout<<x;
				if(--npass==0){
					std::cout<<'\n';
					return 0;
				}else{
					std::cout<<' ';
				}
			}
		}
		return 0;
	}
}