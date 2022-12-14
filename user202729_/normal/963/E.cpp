// I have read the editorial, although (again) it does not involve any special knowledge,
// and I should be able to figure it out by myself.
// Anyway the information is useful for other problems too...
//
// UPD: Just a bad constant factor.
// UPD2: I have to use the asm mul trick...?

#ifdef LOCAL
#else
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>


#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 0
int const MOD=1000000007; // I put the wrong mod here...
// (that's why the result is correct with `define modular double`)
struct modular {
	int val;
	explicit  operator int() const { return val; }
	 modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	 modular(int64_t v):val(int(v%MOD)){
		if(val<0)val+=MOD;
	}
#else
	 modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) bool  operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	modular operator-() const { return modular(val ? MOD-val : 0); }
	modular & operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular & operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular & operator*=(modular m) {
		auto x=(uint64_t)val*m.val;
		unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, mm;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (mm)
			: "d" (xh), "a" (xl), "r" (MOD)
		);
		val= mm;
		return *this;
	}
	modular  pow(int p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	modular  inv() const {
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

#define ARITHBINARYOP(OP) friend modular  operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
};

template<class T> struct offseted_vector{
	std::vector<T> d;
	int offset;

	// Immutable, slower (includes bound checking)
	T operator[](int i)const{ return std::size_t(i-offset)>=d.size() ? T{} : d[i-offset]; }
	// Mutable, faster.
	T& at(int i){ return d[i-offset]; }
	// Immutable, faster.
	T at(int i)const{ return d[i-offset]; }

	int first_index()const{ return offset; }
	int last_index()const{ return offset+(int)d.size(); }
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int radius,a1,a2,a3,a4;
	std::cin>>radius>>a1>>a2>>a3>>a4;
	modular const invsum=modular(1)/(a1+a2+a3+a4);
	auto p1=invsum*a1;
	auto p2=invsum*a2;
	auto p3=invsum*a3;
	auto p4=invsum*a4;
	assert(p1+p2+p3+p4==1);

	int const ncirclerow=2*radius+3,nitem=ncirclerow*ncirclerow;

	struct row_t{ offseted_vector<modular> coef; modular val; };
	std::vector<row_t> t(nitem);

	auto const ind=[&](int x,int y){
		return (x+radius+1)*ncirclerow+(y+radius+1);
	};

	for(unsigned r=0;r<t.size();++r){
		t[r].coef.offset=r-ncirclerow-2;
		t[r].coef.d.resize(2*ncirclerow+4);
	}

	for(int x=-radius-1;x<=radius+1;++x)
	for(int y=-radius-1;y<=radius+1;++y){
		auto& cur_row=t[ind(x,y)];


		if(x*x+y*y>radius*radius){
			cur_row.coef.at(ind(x,y))=1;
			assert(cur_row.val==0);
		}else{
			cur_row.coef.at(ind(x,y))=1;
			cur_row.val=1;

			auto const in_range=[&](int x){ return -radius-1<=x and x<=radius+1; };
			auto const process_neighbor=[&](int r1,int c1,modular prob){
				assert(in_range(r1) and in_range(c1));
				assert(cur_row.coef[ind(r1,c1)]==0);
				cur_row.coef.at(ind(r1,c1))=-prob;
			};
			process_neighbor(x-1,y,p1);
			process_neighbor(x,y-1,p2);
			process_neighbor(x+1,y,p3);
			process_neighbor(x,y+1,p4);
		}
	}
	
	// Gaussian elimination
	auto const elim=[](row_t const& src,row_t& dest,int col,modular inv_src_col){
		assert(src.coef[col]*inv_src_col==1);
		if(dest.coef[col]==0) return;

		auto const factor=-dest.coef[col]*inv_src_col; // then run dest += src*factor
		for(int c1=std::max(src.coef.first_index(),dest.coef.first_index());
				c1<std::min(src.coef.last_index(),dest.coef.last_index());
				++c1){
			dest.coef.at(c1)+=factor*src.coef.at(c1);
		}

		dest.val+=factor*src.val;
		assert(dest.coef[col]==0);
	};

	for(int i=0;i<nitem;++i){
		auto inv_src_col=1/t[i].coef[i];
		for(int j=i+1;j<nitem;++j)
			elim(t[i],t[j],i,inv_src_col);
	}
	for(int i=nitem;i--;){
		auto inv_src_col=1/t[i].coef[i];
		for(int j=i;j--;)
			elim(t[i],t[j],i,inv_src_col);
	}
	
	//for(auto& row:t) assert(row.coef.d.size()<=2ULL*(ncirclerow+2));

	auto const homerow=ind(0,0);
	std::cout<<int(t[homerow].val/t[homerow].coef[homerow])<<'\n';

	t[homerow].coef.at(homerow)=0;
	assert(std::all_of(begin(t[homerow].coef.d),end(t[homerow].coef.d),[](auto x){return x==0;}));
}