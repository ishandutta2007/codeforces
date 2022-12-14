// 16

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
template<class F> struct Modular_ {
 using T=typename std::decay<decltype((F::get()))>::type;
 T val;
 explicit operator T() const { return val; }
 Modular_():val(){}
 template<class U> Modular_(U v):val(T(v%(F::get()))){ if(val<0)val+=(F::get()); }
 [[nodiscard]] bool operator ==(Modular_ b) const { return val == b.val; } [[nodiscard]] bool operator !=(Modular_ b) const { return val != b.val; } [[nodiscard]] bool operator <(Modular_ b) const { return val < b.val; } [[nodiscard]] bool operator >(Modular_ b) const { return val > b.val; } [[nodiscard]] bool operator <=(Modular_ b) const { return val <= b.val; } [[nodiscard]] bool operator >=(Modular_ b) const { return val >= b.val; }
 [[nodiscard]] friend Modular_ operator-(Modular_ x) { x.val=x.val?(F::get())-x.val:0; return x; }
 Modular_& operator+=(Modular_ m) { if ((val += m.val) >= (F::get())) val -= (F::get()); return *this; }
 Modular_& operator-=(Modular_ m) { if ((val -= m.val) < 0) val += (F::get()); return *this; }
 Modular_& operator*=(Modular_ m) {
  if(__builtin_constant_p(m.val)){
   switch(m.val){
    case 1: return *this;
    case 2: return *this+=*this;
    case 3: return *this+=*this+*this;
    case 0: return *this=0;
    case -1: return *this=-*this;
   }
  }else if(__builtin_constant_p(val)){
   return *this=m**this;
  }
  if(std::is_same<T, int>::value){
   val = int((int64_t)val*m.val%(F::get()));
  }else if(std::is_same<T, int64_t>::value){
   uint64_t result=
    (uint64_t)val*(uint64_t)m.val-
    uint64_t((long double)val*m.val/(F::get()))*(uint64_t)(F::get());
   result+=(F::get());
   if(result>=(F::get())){
    result-=(F::get());
    if(result>=(F::get())) result-=(F::get());
   }
   val=result;
  }else{
   assert(false);
  }
  return *this;
 }
 template<class U>
 [[nodiscard]] Modular_ pow(U p) const {
  Modular_ a=*this;
  Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
  return ans;
 }
 [[nodiscard]] Modular_ inv() const {
  T a=val,b=(F::get()), ax=1,bx=0;
  while(b){
   T q=a/b, t=a%b;
   a=b; b=t;
   t=ax-bx*q; ax=bx; bx=t;
  }
  assert(a==1);
  if(ax<0)ax+=(F::get());
  return ax;
 }
 Modular_& operator/=(Modular_ m) { return (*this) *= m.inv(); }
 [[nodiscard]] friend Modular_ operator +(Modular_ a, Modular_ b) { return a += b; } [[nodiscard]] friend Modular_ operator -(Modular_ a, Modular_ b) { return a -= b; } [[nodiscard]] friend Modular_ operator *(Modular_ a, Modular_ b) { return a *= b; } [[nodiscard]] friend Modular_ operator /(Modular_ a, Modular_ b) { return a /= b; }
};
template<class T, T x> struct TGetter{ static T get(){ return x; } };
template<int MOD> using Modular=Modular_<TGetter<int, MOD>>;
template<int const& MOD> using ModularP=Modular_<TGetter<int const&, MOD>>;
template<int64_t const& MOD> using ModularP64=Modular_<TGetter<int64_t const&, MOD>>;

using modular=Modular<1000000007>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	//std::vector<std::vector<modular>> probability(number, std::vector<modular>(number));
	std::vector<modular> probability(number*number);
	//for(auto& row: probability)
	for(auto& value: probability){
		int percentage; std::cin>>percentage;
		value=modular(1)/100*percentage;
	}

	std::vector<modular> total;

	int const middle=number/2;
	auto const maskValue=[&]{
		std::array<int, 1<<6> maskValue;
		assert(number<=6);
		int count=0;
		for(int matchMask=0; matchMask<(int)maskValue.size(); ++matchMask){
			maskValue[matchMask]=__builtin_popcount(matchMask)==middle ? count++: -1;
		}
		total.resize(1<<count);
		return maskValue;
	}();

	auto const process=[&](int left, int right, auto handle){
		auto const len=right-left;
		for(int edgeMask=0; edgeMask<(1<<(len*number)); ++edgeMask){
			modular totalProbability=1;

			// inefficient
			for(int tmp=edgeMask, i=left*number; i<right*number; ++i, tmp>>=1){
				totalProbability*=tmp&1 ?  probability[i]: 1-probability[i];
				if(totalProbability==0) goto continue_outer_2;
			}

			{ // compute matchSets and call handle
				// even more inefficient...?
				std::array<char, 3> data{};
				assert(len<=(int)data.size());
				int matchSets{};
				while(true){
					// process data
					int matchMask{};
					for(int index=0; index<len; ++index){
						if(not(edgeMask>>(index*number+data[index])&1)) goto continue_outer;
						if(matchMask&1<<data[index]) goto continue_outer;
						matchMask|=1<<data[index];
					}
					if(right==number) // second half, should invert
						matchMask^=(1<<number)-1;

					matchSets|=1<<maskValue[matchMask];

continue_outer:
					// increase data
					for(int i=len-1;;){
						if(i<0) goto break_outer;
						if(data[i]==number-1){data[i]=0; --i;}
						else{++data[i]; break;}
					}
				}
break_outer:;

				handle(matchSets, totalProbability);
			}

continue_outer_2:;
		}
	};
	assert(middle<number);
	process(0, middle,[&](int sets, modular probability){
		total[sets]+=probability;
	});
	for(int dim=1; dim<(int)total.size(); dim<<=1)
		for(int i=0; i<(int)total.size(); ++i)
			if(not(i&dim))
				total[i|dim]+=total[i];

	modular result{};
	process(middle, number,[&](int sets, modular probability){
		result+=probability*(total.back()-total[total.size()-1-sets]);
	});
	std::cout<<(int)result<<'\n';
	
}