// :((

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
template<class T>
struct Modular_ {
 int val;
 explicit constexpr operator int() const { return val; }
 constexpr Modular_():val(){}
 constexpr Modular_(auto v):val(int(v%(T{}()))){ if(val<0)val+=(T{}()); }
 [[nodiscard]] bool constexpr operator ==(Modular_ b) const { return val == b.val; } [[nodiscard]] bool constexpr operator !=(Modular_ b) const { return val != b.val; } [[nodiscard]] bool constexpr operator <(Modular_ b) const { return val < b.val; } [[nodiscard]] bool constexpr operator >(Modular_ b) const { return val > b.val; } [[nodiscard]] bool constexpr operator <=(Modular_ b) const { return val <= b.val; } [[nodiscard]] bool constexpr operator >=(Modular_ b) const { return val >= b.val; }
 [[nodiscard]] friend Modular_ constexpr operator-(Modular_ x) { x.val=x.val?(T{}())-x.val:0; return x; }
 Modular_ constexpr& operator+=(Modular_ m) { if ((val += m.val) >= (T{}())) val -= (T{}()); return *this; }
 Modular_ constexpr& operator-=(Modular_ m) { if ((val -= m.val) < 0) val += (T{}()); return *this; }
 Modular_ constexpr& operator*=(Modular_ m) {
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
  val = int((int64_t)val*m.val%(T{}()));
  return *this;
 }
 [[nodiscard]] Modular_ constexpr pow(int p) const {
  Modular_ a=*this;
  Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
  return ans;
 }
 [[nodiscard]] Modular_ constexpr inv() const {
  int a=val,b=(T{}()), ax=1,bx=0;
  while(b){
   int q=a/b, t=a%b;
   a=b; b=t;
   t=ax-bx*q; ax=bx; bx=t;
  }
  assert(a==1);
  if(ax<0)ax+=(T{}());
  return ax;
 }
 Modular_ constexpr& operator/=(Modular_ m) { return (*this) *= m.inv(); }
 [[nodiscard]] friend Modular_ constexpr operator +(Modular_ a, Modular_ b) { return a += b; } [[nodiscard]] friend Modular_ constexpr operator -(Modular_ a, Modular_ b) { return a -= b; } [[nodiscard]] friend Modular_ constexpr operator *(Modular_ a, Modular_ b) { return a *= b; } [[nodiscard]] friend Modular_ constexpr operator /(Modular_ a, Modular_ b) { return a /= b; }
};
template<int x> struct IntConstGetter{ int constexpr operator()() const{ return x; } };
template<int MOD> using Modular=Modular_<IntConstGetter<MOD>>;
template<int const& x> struct IntPointerGetter{ int operator()() const{ return x; } };
template<int const& MOD> using ModularP=Modular_<IntPointerGetter<MOD>>;

int mod;
using modular=ModularP<mod>;

std::vector<modular> values;
std::map<modular, int> len;  // insert should not invalidate iterators


template<int factor>
int computeLen(modular value){
	assert(std::binary_search(begin(values),end(values), value));
	auto [iterator, inserted]=len.insert({value, 0});
	if(inserted){
		if(std::binary_search(begin(values),end(values), value*factor))
			iterator->second=computeLen<factor>(value*factor)+1;
		else return 0;
	}
	return iterator->second;
}

int mod_1;


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int originalSize; std::cin>>mod>>originalSize;

	if(originalSize==mod){
		std::cout<<"0 1\n";
		return 0;
	}

	values.resize(originalSize);
	modular sum{};
	for(auto & it: values){
		std::cin>>it.val;
		sum+=it;
	}

	if(originalSize==1){ std::cout<<(int)sum<<" 0\n"; return 0; }
	
	auto const average=sum/originalSize;
	for(auto & it: values) it-=average;

	{
		auto iterator=std::find(begin(values),end(values), 0);
		if((iterator!=values.end())!=(originalSize&1)){
			std::cout<<"-1\n"; return 0;
		}
		if(iterator!=values.end())
			values.erase(iterator);
	}

	if(originalSize*2+11<=mod){
	//	if(originalSize*3+11<=mod*2){
		modular key; int maxValue=-1;

		std::sort(begin(values),end(values));
		if(originalSize%2==0){
			for(auto it: values) {
				auto value=computeLen<3>(it);
				if(value>maxValue){ maxValue=value; key=it; }
			}

			for(int multiple=1-originalSize; multiple<=originalSize-1; multiple+=2) 
				if(not len.count(multiple*key)){
					std::cout<<"-1\n"; return 0;
				}
			std::cout<<int(average+key*(originalSize-1))<<' '<<int(-2*key)<<'\n';
		}else{
			for(auto it: values) {
				auto value=computeLen<2>(it);
				if(value>maxValue){ maxValue=value; key=it; }
			}

			for(int multiple=1; multiple<=originalSize>>1; ++multiple) 
				if(
						not len.count(multiple*key)
						or not len.count(-multiple*key)
						){
					std::cout<<"-1\n"; return 0;
				}
			std::cout<<int(average+key*(originalSize>>1))<<' '<<int(-key)<<'\n';
		}
	}else{
		std::vector<int> factors;
		auto tmp=mod-1;
		for(auto i=2; i*i<=tmp;++i){
			if(tmp%i==0){
				do tmp/=i; while(tmp%i==0);
				factors.push_back(i);
			}
		}
		if(tmp!=1) factors.push_back(tmp);

		modular root=2;
		while(std::any_of(begin(factors),end(factors),[&](auto prime){
			assert(mod%prime==1);
			return root.pow(mod/prime)==1;
		})) ++root.val;


		mod_1=mod-1;
		using modular1=ModularP<mod_1>;
		std::vector<modular1> log(mod);
		modular value=1;
		for(int exponent=0;exponent<mod-1;++exponent, value*=root) {
			if(exponent!=0) assert(value!=1);
			log[(int)value]=exponent;
		}
		assert(value==1);

		std::vector<modular1> logValues(values.size()), expected;
		std::transform(begin(values),end(values), logValues.begin(),[&](auto it){return log[(int)it];});
		expected.reserve(values.size());

		if(originalSize%2==0){
			for(int multiple=1; multiple<=originalSize-1; multiple+=2) {
				expected.push_back(log[multiple]);
				expected.push_back(log[mod-multiple]);
			}
		}else{
			for(int multiple=1; multiple<=originalSize>>1; ++multiple) {
				expected.push_back(log[multiple]);
				expected.push_back(log[mod-multiple]);
			}
		}

		assert(expected.size()==logValues.size());
		assert((int)expected.size()<mod and expected.size()>0);

		std::sort(begin(logValues),end(logValues));
		std::sort(begin(expected),end(expected));
		auto const logValuesFirst=logValues[0], expectedFirst=expected[0];
		auto logValuesDelta=std::move(logValues), expectedDelta=std::move(expected);
		for(auto pointer: {&logValuesDelta,&expectedDelta}){ // convert those to delta (for KMP)
			auto& it=*pointer;
			auto last=it.back();
			for(auto & value: it)
				std::tie(last, value)=std::pair{value, value-last};
		}

		int matchPos;
		{ // KMP (copy pasted code?)
			auto& pat=expectedDelta;
			std::vector<modular1> txt(logValuesDelta.size()*2);
			std::copy(begin(logValuesDelta),end(logValuesDelta),
					std::copy(begin(logValuesDelta),end(logValuesDelta), txt.begin())
					);



			std::vector<int> shift(pat.size());
			shift[0]=1;
			for(int i=1;i<(int)shift.size();++i){
				shift[i]=shift[i-1];
				while(shift[i]<i and pat[i-1]!=pat[i-1-shift[i]])
					shift[i]+=shift[i-1-shift[i]];
				assert(shift[i]<=i);
			}

			matchPos=0; int match=0;
			while(match<(int)pat.size()){
				while(true){
					if(match>=0){
						if(matchPos==(int)txt.size()){
							std::cout<<"-1\n"; return 0;
						}
						if(txt[matchPos]!=pat[match]){
							match-=shift[match];
							continue;
						}
					}
					break;
				}
				if(match<0) assert(match==-1);
				++match;++matchPos;
			}
			

			matchPos-=(int)pat.size();
		}


		auto const key=root.pow(int(
				logValuesFirst+std::accumulate(logValuesDelta.begin()+1, logValuesDelta.begin()+1+matchPos, modular1{})
				-expectedFirst
				));
		// {expected * key} == {values}

		if(originalSize%2==0){
			std::cout<<int(average+key*(originalSize-1))<<' '<<int(-2*key)<<'\n';
		}else{
			std::cout<<int(average+key*(originalSize>>1))<<' '<<int(-key)<<'\n';
		}

	}
}