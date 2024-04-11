//https://codeforces.com/contest/506/problem/E
#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<vector>
#include<array>
#include<cassert>
#include<string>
#include<algorithm>

int const MOD=10007;

int inv(int x,int y=MOD){
	int a=x,b=y,ax=1,bx=0;
	while(b){
		int q=a/b,t=a%b;
		a=b;b=t;
		t=ax-bx*q;ax=bx;bx=t;
	}
	assert(a==1);
	return ax;
}

struct BK{
	std::vector<int> d,base; // LFSR sequence, last item = 1

	void init(std::vector<int> const& v){
		std::vector<int> d0{1};
		int pos0,del0;

		{
			auto firstnonz=std::find_if(begin(v),end(v),[](int x){return x!=0;});

			if(firstnonz==end(v)){
				d=d0;
				return;
			}

			pos0=firstnonz-begin(v)+1; // evaluate at end=pos will return del0
			del0=*firstnonz;
		}

		std::vector<int> d1(pos0+1);d1.back()=1;
		int pos1=pos0+1;
		int del1=v[pos0];

		while(true){
			if(del1!=0){
				int const f=(MOD*(int64_t)MOD-del1*(int64_t)inv(del0))%MOD;
				for(int& x:d0)
					x=x*(int64_t)f%MOD;
				// del0=del0*(int64_t)f%MOD; :
				// del0=(MOD-del1)%MOD;      : -> equivalent

				assert(pos1>pos0);
				d0.resize(d0.size()+pos1-pos0);
				pos0=pos1;

				std::vector<int> newd1;
				{
					std::vector<int> const& smaller=d0.size()<d1.size()?d0:d1;
					std::vector<int> const& larger=d0.size()<d1.size()?d1:d0;
					newd1=larger;
					std::transform(smaller.rbegin(),smaller.rend(),newd1.rbegin(),
							newd1.rbegin(),[](int a,int b){return (a+b)%MOD;});
				}

				d0=std::move(d1);del0=del1;pos0=pos1;
				d1=std::move(newd1);del1=0; // pos1=pos1;
			}else{
				if(pos1==(int)v.size())
					break;
				++pos1;
				del1=0;
				for(int i=pos1,j=(int)d1.size();
						i--,j-->0;
				   ){
					del1=(del1+v[i]*(int64_t)d1[j])%MOD;
				}
			}
		}

		d=d1;
		base=v;
		base.resize(d.size()-1);
	}

	std::vector<int> mul(std::vector<int> a,std::vector<int> b)const{
		assert(a.size()==d.size()-1);
		assert(b.size()==d.size()-1);
		std::vector<int> c(a.size()+b.size()-1);
		for(unsigned i=0;i<a.size();++i)
		for(unsigned j=0;j<b.size();++j)
			c[i+j]=(c[i+j]+a[i]*(int64_t)b[j])%MOD;
		while(c.size()>=d.size()){
			int fac=(MOD-c.back())%MOD;
			c.pop_back();

			auto a=c.end();
			auto b=--d.end();
			while(true){
				--a;--b;
				*a=(*a+*b*(int64_t)fac)%MOD;
				if(b==d.begin())
					break;
			}
		}
		return c;
	}

	std::vector<int> pow(std::vector<int> base,unsigned exp)const{
		std::vector<int> ans=base;--exp;
		while(true){
			if(exp&1)
				ans=mul(ans,base);
			exp>>=1;
			if(exp==0)
				return ans;
			base=mul(base,base);
		}
	}

	int eval(unsigned x)const{
		if(x<base.size())
			return base[x];
		std::vector<int> x0(base.size());
		x0[1]=1;
		auto ans_vec=pow(x0,x);
		assert(ans_vec.size()==base.size());
		int ans=0;
		for(unsigned i=0;i<ans_vec.size();++i)
			ans=(ans+ans_vec[i]*(int64_t)base[i])%MOD;
		return ans;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	std::string st;std::cin>>st;
	int addlen;std::cin>>addlen;
	// newlen+=(int)st.size();

	unsigned fsize=8000;
	std::vector<int> ans(fsize);
	std::vector<std::array<std::array<int,200>,200>> f(4);
	// f[addlen%4u][l][r] (r inclusive) = num of palindromes

	for(unsigned r=0;r<st.size();++r)
		for(unsigned l=0;l<=r;++l){
			auto& cur=f[(0)%4][l][r];
			if(l==r)cur=1;
			else if(st[l]==st[r]){
				if(l+1==r)cur=st[l]==st[r];
				else cur=f[(0)%4][l+1][r-1];
			}
		}
	f[(0)%4][1][0]=1; // [1:0] = empty

	ans[0]=f[(0)%4][0][st.size()-1];

	for(unsigned addlen_=1;addlen_<fsize;++addlen_){
		unsigned const addlen=addlen_;

		// NOTE: addlen must be unsigned so (addlen-2)%4 == 3 for addlen == 1
		// assume f[-1][l][r] = 0 for all (l,r)
		f[addlen%4][1][0]=addlen>1?f[(addlen-2)%4][1][0]*26LL%MOD:26;

		for(unsigned r=0;r<st.size();++r)
			for(unsigned l=r+1;l-->0;){
				auto& cur=f[addlen%4][l][r];
				if(st[l]==st[r]){
					cur=( // switch outermost character
							(l==r?
							 	f[(addlen-1)%4][1][0]:
							 l+1==r?
							 	f[addlen%4][1][0]:
								f[addlen%4][l+1][r-1])+ // case st[l]
							f[(addlen-2)%4][l][r]*25LL // default
						)%MOD;
				}else{ // l < r, st[l:r] len is >= 2
					cur=( // switch outermost character
							f[(addlen-1)%4][l+1][r]+ // case st[l]
							f[(addlen-1)%4][l][r-1]+ // case st[r]
							f[(addlen-2)%4][l][r]*24LL // default
						)%MOD;
				}
			}

		ans[addlen]=f[(addlen%4)%4][0][st.size()-1];
	}

	BK bk;
	bk.init(ans);
	std::cout<<bk.eval(addlen)<<'\n';
}