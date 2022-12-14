// Note: spoiler below (don't read until you've solved the problem)
//
// [I didn't read the editorial or see any failed test cases]
//
// I figured out the necessary and sufficient condition in the contest, but only until about 5 minutes
// remaining I get the key idea (reduce the gap, while ensure that it's not too far from the home -
// instead of reduce the maximum distance to the home - in the end they're the same, but
// the idea allows me to consider less cases)
//
// Before that I only roughly know which cases are "hard" and how to solve them (which cover all cases
// in the solution)
//
// I hope the number of steps in this solution is in o(log^2 (n)) -- UPD: By running some tests I determined
// that the number of steps is usually < 200. It's good enough.
//
// <s>Still WA, and the bug I thought I have found is a checker bug. (Now I add the checker to the
// generator as well as the program)</s>
//
// -> <s>Checked the necessary and sufficient condition again. No error.</s>
// -> Look for all occurrences of int. None of them can cause overflow.
// -> Found out the bug by deciding to print out the nop value and look for tests where it's -1,
// because the bug can only be inside the `prop` function. For some reason I can't find out
// the bug by looking at the code...
// -> Still WA.
// -> Determine that the bug is int the checker, not the code (it should be obvious, but
// it took me a long time trying to find a failing test), so I re-read the problem statement
// and notice the condition that x!=y int the output.
// -> Submit again.

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<array>
#include<numeric>
#include<tuple>
#include<algorithm>
#include<cstdlib>
#include<vector>

using i4=std::array<int64_t,4>;

struct step{
	int64_t pos,cen;
};

struct prop_t{
	int64_t gcd;
	int64_t home;
	int64_t cnthome; // number of values % (2*gcd) == home. the rest has value % (2*gcd) == (home+gcd).
	// between 1 and 3. !=0 when gcd !=0.

	auto tup()const{
		return std::make_tuple(gcd,home,cnthome);
	}
};

template<class Fn>
auto comparator_from_key(Fn f){
	return [f](auto a,auto b){
		return f(a)<f(b);
	};
}

std::vector<step> movehome(i4& p,prop_t pp){
	// cnthome stones at home + (4-cnthome) stones at home+gcd
	auto const [gcd,home,cnthome]=pp;
	assert(gcd!=0);

	std::vector<step> out;

	auto outp=[&](auto pos,auto cen){
		if(pos!=cen)
			out.push_back({pos,cen});
	};

	auto flip=[&](int posi,int ceni){
		if(p[posi]==p[ceni])
			return;
		assert(std::is_sorted(begin(p),end(p)));
		outp(p[posi],p[ceni]);
		p[posi]=2*p[ceni]-p[posi];
		std::sort(begin(p),end(p));
	};
	std::sort(begin(p),end(p));

	while(p[3]<home){
		flip(0,3);
	}

	while(p[0]>home){
		flip(3,0);
	}

	//while(p[3]>home+3*gcd or p[0]<home-3*gcd){
	while(p[3]-p[0]>gcd){
		assert(p[0]<=home and home<=p[3]);
		auto const oldgap=p[3]-p[0];
		auto const oldp=p;

		for(;;){
			auto const mid2=p[0]+p[3];
			auto i=std::min_element(1+begin(p),end(p)-1,comparator_from_key([mid2](auto a){
					return std::abs(a*2-mid2);
					}))-begin(p);

			if(std::abs(p[i]*2-mid2)*2>(p[3]-p[0])){
				if(p[1]*2<mid2){
					if(p[2]*2<mid2){
						// * * * --- *
						flip(0,2);
					}else{
						// * * --- * *
						if(p[1]-p[0]>p[3]-p[2]){
							outp(p[2],p[1]);
							outp(2*p[1]-p[2],p[0]);
							p[2]-=(p[1]-p[0])*2;
							assert(std::is_sorted(begin(p),end(p)));
						}else{
							outp(p[1],p[2]);
							outp(2*p[2]-p[1],p[3]);
							p[1]+=(p[3]-p[2])*2;
							assert(std::is_sorted(begin(p),end(p)));
						}
					}
				}else{
					// * --- * * *
					flip(3,1);
				}
			}else{
				assert(p[0]<p[i] and p[i]<p[3]);

				if(p[i]*2<mid2){
					std::for_each(begin(p),std::find_if(begin(p),end(p),[&](auto x){return x!=p[0];}),
						[&](auto& x){
							outp(x,p[i]);
							x=p[i]*2-x;
						});
				}else{
					std::for_each(p.rbegin(),std::find_if(p.rbegin(),p.rend(),[&](auto x){return x!=p[3];}),
						[&](auto& x){
							outp(x,p[i]);
							x=p[i]*2-x;
						});
				}
				std::sort(begin(p),end(p));
				break;
			}
		}

		auto const gap=p[3]-p[0];
		assert(gap<oldgap and gap>=oldgap/4 /* estimation. Any fraction in [0,1] is ok */);

		while(p[3]<home){
			for(int i=0;i<3;++i){
				outp(p[i],p[3]);
				p[i]=2*p[3]-p[i];
			}
			std::sort(begin(p),end(p));
		}
		while(p[0]>home){
			for(int i=1;i<4;++i){
				outp(p[i],p[0]);
				p[i]=2*p[0]-p[i];
			}
			std::sort(begin(p),end(p));
		}

		assert(p[3]-p[0]==gap);
	}

	for(;;){
		if(p[0]<home){
			auto i=std::min_element(begin(p)+1,end(p),comparator_from_key([&](auto x){
					return std::abs((home*2+gcd)-2*(x*2-p[0]));
					}))-begin(p);
			flip(0,i);
		}else if (p[3]>home+gcd){
			auto i=std::min_element(begin(p),end(p)-1,comparator_from_key([&](auto x){
					return std::abs((home*2+gcd)-2*(x*2-p[3]));
					}))-begin(p);
			flip(3,i);
		}else break;
	}

	assert(p[0]==home and p[3]==home+gcd);
	return out;
}

prop_t prop(i4 p){
	std::sort(begin(p),end(p));

	prop_t out{0,0,0};
	auto& gcd=out.gcd;

	for(int i=1;i<4;++i)
		gcd=std::gcd(gcd,p[i]-p[0]);
	if(gcd!=0){
		out.home=p[0]%gcd;
		if(out.home<0)out.home+=gcd;

		out.cnthome=(int)std::count_if(begin(p),end(p),[gcd,home=out.home](auto x){
				return (x-home)%(2*gcd)==0;
				});
		assert(out.cnthome>0 and out.cnthome<4);
	}else{
		assert(std::all_of(begin(p),end(p),[p0=p[0]](int pi){return pi==p0;}));
		out.home=p[0];
	}

	return out;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	i4 a,b;
	for(auto& x:a)std::cin>>x;
	for(auto& x:b)std::cin>>x;

	std::sort(begin(a),end(a));
	std::sort(begin(b),end(b));
	if(a==b){
		std::cout<<"0\n";
		return 0;
	}

	prop_t pa=prop(a);
	prop_t pb=prop(b);
	if(pa.tup()!=pb.tup()){
		std::cout<<"-1\n";
		return 0;
	}

	assert(pa.gcd!=0);
	auto out1=movehome(a,pa);
	auto out2=movehome(b,pa);

	assert(a==b);

	assert(out1.size()+out2.size()<=500);

	std::cout<<out1.size()+out2.size()<<'\n';
	for(auto [pos,cen]:out1) std::cout<<pos<<' '<<cen<<'\n';
	std::for_each(out2.rbegin(),out2.rend(),[](auto poscen){
			auto [pos,cen]=poscen;
			std::cout<<2*cen-pos<<' '<<cen<<'\n';
			});
}