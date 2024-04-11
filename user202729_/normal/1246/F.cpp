// I didn't read the editorial and didn't see the test details
// NOTE: avoid assignment of form mystruct.a = expr1; mystruct.b = expr2(mystruct.a);
// NOTE: turn on assertions and run the test case before trying to optimize.
// Assertion failed will make the complexity calculation wrong.
//#ifndef _GLIBCXX_DEBUG
//#define NDEBUG
//#endif
#include<iostream>
#include<algorithm>
#include<string>
#include<cassert>
#include<vector>
#include<array>

struct result_t{
	std::vector<int> pre;
	std::vector<std::array<int,26>> jl;
	std::vector<std::array<int64_t,26>> sum; // sum - includes first step, go inf. steps from i, assume fixed c
	std::vector<std::vector<std::array<int,26>>> jt;
	std::vector<std::array<int,26>> nxt;
};

result_t build(std::string const& s){
	std::vector<int> pre(s.size()); // pre[i]=max j<i, s[j]==s[i], or 0
	std::array<int,26> last{}; // last[char] = last index
	for(int i=0;i<(int)s.size();++i){
		pre[i]=last[s[i]];
		last[s[i]]=i;
	}

	std::vector<std::array<int,26>> jl(s.size());
	// jl[i][k] = min pre[x] for x>=i, over k+1 smallest values of x s.t.
	// s[x] are distinct

	std::vector<std::array<int,26>> nxt(s.size());
	// nxt[i][k] = index of the k'th distinct character of s[i:]

	struct item{
		char c;
		int pre,nxt;
	};
	std::array<item,26> is;
	for(char c=0;c<26;++c)
		is[c]={c,(int)s.size(),(int)s.size()};

	for(auto i=(int)s.size();i--;){
		auto iter=std::find_if(begin(is),end(is),[c=s[i]](auto p){
				return p.c==c;
				});
		iter->nxt=i;
		iter->pre=pre[i];
		while(iter!=begin(is)&&iter->nxt<iter[-1].nxt){
			std::swap(*iter,iter[-1]);
			--iter;
		}

		auto& jli=jl[i];
		std::transform(begin(is),end(is),begin(nxt[i]),
				[](item i){return i.nxt;});

		jli[0]=is[0].pre;
		for(int c=1;c<26;++c)
			jli[c]=std::min(is[c].pre,jli[c-1]);
	}

	std::vector<std::vector<std::array<int,26>>> jt;
	// see result_t description

	jt.emplace_back(s.size());
	auto& jt0=jt.back();
	std::vector<std::array<int64_t,26>> sum(s.size());
	for(int i=0;i<(int)s.size();++i){
		for(int c=0;c<26;++c){
			jt0[i][c]=jl[i][c];
			sum[i][c]=i+sum[jl[i][c]][c]; // it's okay if i = jl[i][c]
		}
	}

	while(true){
		auto const& a=jt.back();

		// stop here if all of x values ina are 0
		if(std::all_of(begin(a),end(a),[](auto ai){
					return std::all_of(begin(ai),end(ai),[](auto aic){
							return aic==0;
							});
							})){
			break;
		}

		auto b=a;
		for(auto& bi:b){
			for(int c=0;c<26;++c){
				int& bic=bi[c];
				bic = a[bic][c];
			}
		}

		if((1<<jt.size() /* layer of b */)>2*s.size()){ // this is just something to assert on memory usage.
			// it doesn't need to be very strict.
			std::cerr<<jt.size()<<' '<<s.size()<<'\n';
			assert(false);
		}
		jt.push_back(std::move(b));
	}

	return {std::move(pre),std::move(jl),std::move(sum),std::move(jt),std::move(nxt)};
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;
	for(char& x:s)x=char(x-'a');

	auto rel=build(s);
	std::reverse(begin(s),end(s));
	auto rer=build(s);
	std::reverse(begin(s),end(s));

	assert(std::cerr<<"nlayer="<<std::max(rel.jt.size(),rer.jt.size())<<'\n');
	int64_t ans=0;
	for(int i=0;i<(int)s.size();++i){
		int l=i,r=i+1;
		int n=0; // number of distinct characters int l..r - 1
		while(l!=0 or r!=(int)s.size()){
			ans+=rel.sum[l][n];
			ans+=rer.sum[(int)s.size()-r][n];

			for(auto layer=std::max(rel.jt.size(),rer.jt.size());
					layer--;){
				auto l_=layer>=rel.jt.size() ? 0 : rel.jt[layer][l][n];
				auto r_=layer>=rer.jt.size() ? (int)s.size() : (int)s.size()-rer.jt[layer][s.size()-r][n];

				assert(rel.nxt[l_][n]<r_);
				if(n<25 and rel.nxt[l_][n+1]<r_){
					// jumping will increase n
					continue;
				}

				l=l_;r=r_;
			}

			int const oldn=n;
			if(l!=0 or r!=(int)s.size()){
				auto l_=rel.jt[0][l][n];
				auto r_=rer.jt[0][s.size()-r][n];
				r_=(int)s.size()-r_;
				auto nxtl=rel.nxt[l_];
				auto n_=int(std::lower_bound(begin(nxtl),end(nxtl),r_)-begin(nxtl)-1);
				assert(n<n_);

				n=n_;
				l=l_;r=r_;
			}

			ans-=rel.sum[l][oldn];
			ans-=rer.sum[(int)s.size()-r][oldn];
		}
	}

	std::cout<<ans<<'\n';
}


/*
abcde
20

abacaba
58
*/