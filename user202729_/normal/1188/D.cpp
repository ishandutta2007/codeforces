/*
 * <s>Somehow I feel that this problem is even easier than B and C.</s>
 *
 * ... 16 minutes later...
 *
 * Did I even run the sample test cases by hand?... the algorithm is wrong.
 *
 * Have another algorithm.
 * Took another 60 minutes.
 *
 * WA.
 * Took another ~ 15 minutes to debug.
 * WA.
 *
 * Find out that there's something wrong with the solution (increasing MAXBIT increases answer)
 * Took ~30 more minutes (or is it 60?) to debug.
 * (NICE BUG)
 * (note: if it's hard to write a brute force solution, it's useful to
 * compare the program behavior with itself but with different parameter (BLOCKSIZE is the most common)
 *
 * [I didn't see any failed test cases or read the editorial.]
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<climits>
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

using longint_t=int64_t;
// using longint_t=__int128;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<longint_t> a(n);
	for(auto& x:a){
		int64_t y;
		std::cin>>y;
		x=y;
	}
	std::transform(begin(a),end(a),begin(a),
			[maxa=*std::max_element(begin(a),end(a))](longint_t ai){return ai-maxa;});

	struct ev{
		longint_t val;
		int deg;
		bool operator<(ev b)const{return val<b.val;}
	};
	std::vector<ev> f; // current function

	auto const simplify=[&]{
		assert(std::is_sorted(begin(f),end(f)));
		auto out=begin(f);
		for(auto e:f){
			auto [val,deg]=e;
			if(deg==0)continue;
			if(out!=begin(f) and out[-1].val==val){
				if((out[-1].deg+=deg)==0)
					--out;
				continue;
			}
			*out++=e;
		}
		f.erase(out,end(f));
	};

#ifndef MAXBIT
#define MAXBIT 62
#endif

	f.push_back({((longint_t)1<<MAXBIT)+*std::min_element(begin(a),end(a)),1000000000 /* sufficiently large */});
	f.push_back({(longint_t)1<<MAXBIT,-1000000000});

	for(int bit=MAXBIT;bit;--bit){
		longint_t const mask=((longint_t)1<<bit)-1;
		{ // add current layer to function
			int nwrap=0;
			for(auto x:a){
				auto l=(x+((longint_t)1<<(bit-1)))&mask;
				auto r=x&mask; // segment [l..r[ += 1
				f.push_back({l,1});
				f.push_back({r,-1});
				if(l>r)
					++nwrap;
			}
			if(nwrap){
				f.push_back({0,nwrap});
				f.push_back({(longint_t)1<<bit,-nwrap});
			}
			std::sort(begin(f),end(f));
		}

		simplify();

		auto const half=(longint_t)1<<(bit-1);
		{ // f(x) = min(f(x), f(x+half))
			// split f into two parts
			auto iter=std::lower_bound(begin(f),end(f),ev{half,0});
			std::vector<ev> g; g.reserve(end(f)-iter+2); g.assign(iter,end(f));
			for(auto& e:g)
				e.val-=half;
			f.erase(iter,end(f));

			int degf=0;
			for(auto [val,deltadeg]:f)
				degf+=deltadeg;
			if(degf){
				f.push_back({half,-degf});
				g.insert(begin(g),{0,degf});
			}

			// splitted to f and g. now execute out = min(f, g)
			std::vector<ev> out;out.reserve(f.size()+g.size());
			f.push_back({half,0});
			g.push_back({half,0});
			auto i1=begin(f),i2=begin(g);
			degf=0;int degg=0,degmin=0;
			longint_t last=0;

			for(;;){ //for(auto z=f.size()+g.size();z--;){
				longint_t val=std::min(i1->val,i2->val);

				if(val>last){
					int newdeg=std::min(degf,degg);
					if(newdeg!=degmin){
						out.push_back({last,newdeg-degmin});
						degmin=newdeg;
					}
					last=val;
					if(val==half)
						break;
				}

				if(i1->val<i2->val){
					degf+=i1->deg;
					++i1;
				}else{
					degg+=i2->deg;
					++i2;
				}

			}
			if(degmin)
				out.push_back({half,-degmin});

			f=std::move(out);
		}

		simplify();
		/*
		if(bit>70 and not f.empty()){
			assert(false);
		}
		*/

	}

	simplify();

	int ans; // get min of function
	if(f.empty()){
		ans=0;
	}else{
		assert(f.size()==2);
		assert(f[0].deg==-f[1].deg);
		ans=f[0].deg;
	}

	std::cout<<ans<<'\n';
}