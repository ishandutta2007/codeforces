/*
 * {deleted comments}
 * Applied some optimization (to the exponential part) that may not be very useful
 * in the random case, but should significantly speed up the algorithm for this problem.
 * ===
 * Tested with max test case ("59 $(seq 2 60)"). Runtime is ~ 0.18ms now.
 * Oddly, when I add the "useless-by-dominated" part of leaves, it's actually (slightly) slower.
 *
 * ===
 *
 * { Mundo doesn't work very well with huge undo file. }
 * Ran the generator script and found out a bug. Fixed.
 */

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

using compressed_mask_t=int;

std::vector<compressed_mask_t> ad; // of compressed

auto ctz(int x){ return __builtin_ctz(x); }
auto ctz(unsigned x){ return __builtin_ctz(x); }
static_assert(sizeof(int64_t)==sizeof(long long));
auto ctz(int64_t x){ return __builtin_ctzll(x); }
auto ctz(uint64_t x){ return __builtin_ctzll(x); }

#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 0
int const MOD=1000000007;
struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	constexpr modular(int64_t v):val(int(v%MOD)){
		if(val<0)val+=MOD;
	}
#else
	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) bool constexpr operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	modular operator-() const { return modular(val ? MOD-val : 0); }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	void asm_mul(modular m){
		auto x=(uint64_t)val*m.val;
		unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, mm;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (mm)
			: "d" (xh), "a" (xl), "r" (MOD)
		);
		val= mm;
	}

	modular & operator*=(modular m) {
		//if(__builtin_is_constant_evaluated()){
		//	val = int((int64_t)val*m.val%MOD);
		//}else{
			asm_mul(m);
		//}
		return *this;
	}
	modular inv() const {
		int a=val,b=MOD, ax=1,bx=0;
		while(b){
			int q=a/b, t=a%b;
			a=b; b=t;
			t=ax-bx*q; ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	modular & operator/=(modular m) { return (*this) *= m.inv(); }

#define ARITHBINARYOP(OP) friend modular operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
};

auto const [factorial,invfact]=[]{
	std::array<modular,64> factorial,invfact;
	factorial[0]=invfact[0]=1;
	for(unsigned i=1;i<factorial.size();++i){
		factorial[i]=factorial[i-1]*i;
		invfact[i]=1/factorial[i];
	}
	return std::pair{factorial,invfact};
}();

auto const inv=[]{
	std::array<modular,64> inv;
	for(unsigned i=1;i<inv.size();++i){
		inv[i]=modular(1)/i;
	}
	return inv;
}();

std::vector<modular> mem;

struct bit_iter:std::iterator<std::forward_iterator_tag,int>{
	compressed_mask_t mask;

	bit_iter():mask(){}
	bit_iter(compressed_mask_t mask):mask(mask){}

	int operator*()const{ return ctz(mask); }
	auto operator==(bit_iter x)const{ return mask==x.mask; }
	auto operator!=(bit_iter x)const{ return mask!=x.mask; }
	auto& operator++(){ mask-=mask&-mask; return *this; }
};
// std::for_each(bit_iter{x}, bit_iter{}, [](int bit_position){ ... })

struct bit_value_iter:std::iterator<std::forward_iterator_tag,int>{
	compressed_mask_t mask;

	bit_value_iter():mask(){}
	bit_value_iter(compressed_mask_t mask):mask(mask){}

	compressed_mask_t operator*()const{ return mask&-mask; }
	auto operator==(bit_value_iter x)const{ return mask==x.mask; }
	auto operator!=(bit_value_iter x)const{ return mask!=x.mask; }
	auto& operator++(){ mask-=mask&-mask; return *this; }
};

std::vector<int64_t> divisible_masks;
std::vector<int> divisible_mask_cnt;


// Returns any connected component of subgraph with vertices = mask_.
compressed_mask_t component(compressed_mask_t mask_){
	compressed_mask_t pending=mask_&-mask_;
	compressed_mask_t visited=pending;
	while(pending){
		auto newvisit=ad[ctz(pending)]&mask_&~visited;
		pending^=pending&-pending;
		pending|=newvisit;
		visited|=newvisit;
		if(visited==mask_) break;
	}
	return visited;
}

bool is_connected(compressed_mask_t mask_){
	//return component(mask_)==mask_;

	if(mask_==0) return true;

	compressed_mask_t pending=mask_&-mask_;
	compressed_mask_t visited=pending;
	while(pending){
		auto newvisit=ad[ctz(pending)]&mask_&~visited;
		pending^=pending&-pending;
		pending|=newvisit;
		visited|=newvisit;
		if(visited==mask_) return true;
	}
	return false;
}

int uncompressed_size(compressed_mask_t mask){
	int n1=0;
	std::for_each(bit_iter{mask},bit_iter{},[&](int b1){
		n1+=divisible_mask_cnt[b1];
	});
	return n1;
}

compressed_mask_t cur_component;
int uncompressed_size_cur_component;

modular solve(compressed_mask_t const vertices_mask){
	mem[0]=factorial[uncompressed_size_cur_component-uncompressed_size(0)-1];
	assert(cur_component==vertices_mask);
	for(auto x=vertices_mask;;){
		x=(x-1)&vertices_mask;


		auto const m1=vertices_mask^x;

		if(not is_connected(m1)){
			mem[m1]=0;
			goto nextx;
		}

		{
			int n0=uncompressed_size(m1);
			int n1=uncompressed_size_cur_component-n0;

			/*
			if(0){ // WRONG
				if(std::all_of(bit_iter{m1},bit_iter{},[&](int b){
					return (ad[b]&m1)==m1;
				})){
					mem[m1]/factorial[uncompressed_size_cur_component-uncompressed_size(m1)-1]=
						//factorial[__builtin_popcountll(m1)]*
						factorial[n1+n0-1]*(n0)*invfact[n1];
					goto nextx;
				}
			}
			*/

			modular f=0;
			std::for_each(bit_value_iter{m1},bit_value_iter{},[&](auto val){
				// assume component b is the first (*) one to have last element removed
				// (*): Is it possible to compute if 'first' is replaced by 'last'? At least in that case
				// cur_component is not required to be global.
				auto submask=m1^val;
				auto const n2=divisible_mask_cnt[ctz(val)];
				switch(n2){
					case 1: f+=mem[submask]; break;
					case 2: f+=mem[submask]+mem[submask]; break;
					default: f+=mem[submask]*n2; break;
				} // funny optimization that actually works

				/*
				static struct X{
					int64_t c=0;
					~X(){ std::cerr<<"c="<<c<<'\n'; }
				} x;
				++x.c;
				*/
			});
			if(x==0){
				assert(n1==0);
				return f;
			}
			mem[m1]=f*inv[uncompressed_size_cur_component-uncompressed_size(m1)];
		}

nextx:;
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n); for(int& ai:a) std::cin>>ai;
	std::sort(begin(a),end(a));
	assert(n>=3 and 1<=a[0]);
	std::vector<int> leaves=a;
	leaves.erase(
			std::remove_if(begin(leaves),end(leaves),[&](int x){
				return std::any_of(begin(a),end(a),[&](int y){ return y<x and x%y==0; });
			}),end(leaves));
	a.erase(std::set_difference(begin(a),end(a),begin(leaves),end(leaves),begin(a)),
			end(a));
	n=-1;

	// remove useless leaves
	leaves.erase(
			std::remove_if(begin(leaves),end(leaves),[&](int leaf){
				return std::count_if(begin(a),end(a),[&](int y){ return y%leaf==0; })<=1;
			}),end(leaves));

	std::map<int64_t,int> divisible_mask_cnt_map;
	for(int x:a){
		int64_t mask=0;
		for(int y:leaves)
			mask=mask<<1|(x%y==0);
		++divisible_mask_cnt_map[mask];
	}
	divisible_mask_cnt_map.erase(0);

	divisible_masks.resize(divisible_mask_cnt_map.size());
	divisible_mask_cnt.resize(divisible_mask_cnt_map.size());
	std::transform(begin(divisible_mask_cnt_map),end(divisible_mask_cnt_map),
			begin(divisible_masks),[](auto p){ return p.first; });
	std::transform(begin(divisible_mask_cnt_map),end(divisible_mask_cnt_map),
			begin(divisible_mask_cnt),[](auto p){ return p.second; });
	divisible_mask_cnt_map.clear();


	ad.resize(divisible_masks.size());
	for(unsigned x=0;x<ad.size();++x)
	for(unsigned y=0;y<ad.size();++y)
		ad[x]|=compressed_mask_t((divisible_masks[x]&divisible_masks[y])!=0)<<y;

	compressed_mask_t mask=(compressed_mask_t(1)<<ad.size())-1;
	modular out=1;
	int max_nbox=0;

	modular modular_invalid;
	modular_invalid.val=-1;
	mem.resize(1LL<<ad.size(),modular_invalid);

	while(mask){
		cur_component=component(mask);
		assert(cur_component!=0);
		uncompressed_size_cur_component=uncompressed_size(cur_component);
		max_nbox+=uncompressed_size(cur_component)-1;
		out*=invfact[uncompressed_size(cur_component)-1];
		out*=solve(cur_component);
		mask^=cur_component;
	}
	out*=factorial[max_nbox];
	std::cout<<(int)out<<'\n';
}