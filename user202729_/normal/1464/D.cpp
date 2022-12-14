// ...
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
       
template<class F> struct Modular_ {
 using T=typename std::decay<decltype((F::get()))>::type;
 T val;
 explicit operator T() const { return val; }
 Modular_():val(){}
 template<class U> static auto check_mod_mod()->decltype(std::declval<U>()%(F::get()), void());
 template<class U
  , class=decltype(check_mod_mod<U>())
  > Modular_(U v):val(T(v%(F::get()))){ if(val<0)val+=(F::get()); }
 [[nodiscard]] bool operator ==(Modular_ b) const { return val == b.val; } [[nodiscard]] bool operator !=(Modular_ b) const { return val != b.val; } [[nodiscard]] bool operator <(Modular_ b) const { return val < b.val; } [[nodiscard]] bool operator >(Modular_ b) const { return val > b.val; } [[nodiscard]] bool operator <=(Modular_ b) const { return val <= b.val; } [[nodiscard]] bool operator >=(Modular_ b) const { return val >= b.val; }
 [[nodiscard]] Modular_ operator+() const{ return *this; }
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
 friend std::ostream& operator<<(std::ostream& stream, Modular_ m) { return stream<<m.val<<'M'; }
 [[nodiscard]] friend Modular_ operator +(Modular_ a, Modular_ b) { return a += b; } [[nodiscard]] friend Modular_ operator -(Modular_ a, Modular_ b) { return a -= b; } [[nodiscard]] friend Modular_ operator *(Modular_ a, Modular_ b) { return a *= b; } [[nodiscard]] friend Modular_ operator /(Modular_ a, Modular_ b) { return a /= b; }
};
template<class T, T x> struct TGetter{ static T get(){ return x; } };
template<int MOD> using Modular=Modular_<TGetter<int, MOD>>;
template<int const& MOD> using ModularP=Modular_<TGetter<int const&, MOD>>;
template<int64_t const& MOD> using ModularP64=Modular_<TGetter<int64_t const&, MOD>>;
using modular=Modular<1000000007>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::vector<int> data;
	int numTest; std::cin>>numTest;
	while(numTest--){
		int n; std::cin>>n;
		data.resize(n);
		for(auto& it: data){ std::cin>>it;--it;}
		std::vector<int> lengths;
		for(int i=0; i<n; ++i)if(data[i]>=0){
			int x=i;
			int length=0;
			do{
				std::tie(x, data[x])=std::pair(data[x], -1);
				++length;
			}while(x!=i);
			lengths.push_back(length);
		}

		assert(std::accumulate(begin(lengths), end(lengths), -n)==0);

		assert(n>=3);
		int odd=(n%3==0 ? 0: n%3==1 ? 4: 2);
		assert((n-odd)%3==0);


		std::array<int, 7> count{}; // while(>= 7)  -=3   =>  result after -= is >=4
		for(auto length: lengths){
			int tmp=length;
			if(tmp>=(int)count.size()){
				tmp-=(tmp-(int)count.size())/3*3;
				assert(tmp>=(int)count.size());
				while(tmp>=(int)count.size()) tmp-=3;
			}
			++count[tmp];
		}

		int leastSwap=INT_MAX;
		int const numWhole=(n-odd)/3;

		int const numCycles=(int)lengths.size();
		auto const process=[
			numWhole, 
			count, numCycles, &leastSwap](std::initializer_list<int> const odd){

			auto const maxNumComponent=[&](auto maxNumComponent,
					auto first, auto last, // odd rest
					std::array<int, 7> const count
					)->int{
				if(first==last){
					std::array<int, 3> count1{};
					for(int i=0; i<(int)count.size(); ++i)
						count1[i%3]+=count[i];

					auto const [x, a, b]=count1;
					assert(a%3==b%3);
					return x+std::min(a, b)+(std::max(a, b)-std::min(a, b))/3;
				}
				else{
					assert(*first%3!=0);
					int result{};

					// ouch.
					for(int i1=0; i1<(int)count.size(); ++i1)
					if(i1>=*first and (i1-*first)%3==0)
					{
						auto count1=count;
						if(0>--count1[i1]) continue;
						result=std::max(result,
								maxNumComponent(maxNumComponent, first+1, last, count1)+1
								);
					}

					for(int i1=0; i1<(int)count.size(); ++i1)
					for(int i2=0; i2<(int)count.size(); ++i2)
					if((i1+i2)>=*first and ((i1+i2)-*first)%3==0)
					{
						auto count1=count;
						if(0>--count1[i1]) continue;
						if(0>--count1[i2]) continue;
						result=std::max(result,
								maxNumComponent(maxNumComponent, first+1, last, count1)+1
								);
					}

					for(int i1=0; i1<(int)count.size(); ++i1)
					for(int i2=0; i2<(int)count.size(); ++i2)
					for(int i3=0; i3<(int)count.size(); ++i3)
					if((i1+i2+i3)>=*first and ((i1+i2+i3)-*first)%3==0)
					{
						auto count1=count;
						if(0>--count1[i1]) continue;
						if(0>--count1[i2]) continue;
						if(0>--count1[i3]) continue;
						result=std::max(result,
								maxNumComponent(maxNumComponent, first+1, last, count1)+1
								);
					}
					
					return result;
				}
			};

			int numComponent=maxNumComponent(maxNumComponent, odd.begin(), odd.end(), count);
			assert(numComponent>=0);

			leastSwap=std::min(leastSwap,
					numCycles+
					(numWhole+(int)odd.size())
					-numComponent*2);
		};

		if(odd==0){
			process({});
		}else if(odd==4){
			process({2, 2});
			process({4});
		}else{
			assert(odd==2);
			process({2});
		}

		std::cout<<int(modular(3).pow(numWhole)*(odd==0 ? 1: odd))<<' '<<
			leastSwap
			<<'\n';
	}
}