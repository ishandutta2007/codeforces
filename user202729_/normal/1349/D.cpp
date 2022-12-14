










// a little related: https://codeforces.com/contest/963/problem/E

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
       
 #include<type_traits>
template<class F>
struct Modular_ {
 using T=typename std::decay<decltype((F{}()))>::type;
 T val;
 explicit constexpr operator T() const { return val; }
 constexpr Modular_():val(){}
 constexpr Modular_(auto v):val(T(v%(F{}()))){ if(val<0)val+=(F{}()); }
 [[nodiscard]] bool constexpr operator ==(Modular_ b) const { return val == b.val; } [[nodiscard]] bool constexpr operator !=(Modular_ b) const { return val != b.val; } [[nodiscard]] bool constexpr operator <(Modular_ b) const { return val < b.val; } [[nodiscard]] bool constexpr operator >(Modular_ b) const { return val > b.val; } [[nodiscard]] bool constexpr operator <=(Modular_ b) const { return val <= b.val; } [[nodiscard]] bool constexpr operator >=(Modular_ b) const { return val >= b.val; }
 [[nodiscard]] friend Modular_ constexpr operator-(Modular_ x) { x.val=x.val?(F{}())-x.val:0; return x; }
 Modular_ constexpr& operator+=(Modular_ m) { if ((val += m.val) >= (F{}())) val -= (F{}()); return *this; }
 Modular_ constexpr& operator-=(Modular_ m) { if ((val -= m.val) < 0) val += (F{}()); return *this; }
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
  bool constexpr is_int=std::is_same<T, int>::value;
  bool constexpr is_int64_t=std::is_same<T, int64_t>::value;
  static_assert(is_int or is_int64_t, "Mod type not supported");
  if(is_int){
   val = int((int64_t)val*m.val%(F{}()));
  }else{
   uint64_t result=
    (uint64_t)val*(uint64_t)m.val-
    uint64_t((long double)val*m.val/(F{}()))*(uint64_t)(F{}());
   result+=(F{}());
   if(result>=(F{}())){
    result-=(F{}());
    if(result>=(F{}())) result-=(F{}());
   }
   val=result;
  }
  return *this;
 }
 template<class U>
 [[nodiscard]] Modular_ constexpr pow(U p) const {
  Modular_ a=*this;
  Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
  return ans;
 }
 [[nodiscard]] Modular_ constexpr inv() const {
  T a=val,b=(F{}()), ax=1,bx=0;
  while(b){
   T q=a/b, t=a%b;
   a=b; b=t;
   t=ax-bx*q; ax=bx; bx=t;
  }
  assert(a==1);
  if(ax<0)ax+=(F{}());
  return ax;
 }
 Modular_ constexpr& operator/=(Modular_ m) { return (*this) *= m.inv(); }
 [[nodiscard]] friend Modular_ constexpr operator +(Modular_ a, Modular_ b) { return a += b; } [[nodiscard]] friend Modular_ constexpr operator -(Modular_ a, Modular_ b) { return a -= b; } [[nodiscard]] friend Modular_ constexpr operator *(Modular_ a, Modular_ b) { return a *= b; } [[nodiscard]] friend Modular_ constexpr operator /(Modular_ a, Modular_ b) { return a /= b; }
};
template<int MOD> using Modular=Modular_<std::integral_constant<int, MOD>>;
template<class T, T const& x> struct TPointerGetter{ T operator()() const{ return x; } };
template<int const& x> using IntPointerGetter=TPointerGetter<int, x>;
template<int const& MOD> using ModularP=Modular_<IntPointerGetter<MOD>>;

#if 0
using modular=double;
#else
using modular=Modular<998244353>;
#endif

template<int offset, std::size_t N_> void solve(std::vector<std::array<modular, N_>>& data){
	// data[r][offset+i] = matrix[r][r+i] (offset+i!=0)
	// data[r][0] = matrix[r][VALUE]
	// equations: sum(matrix[r][i]*var[i])==matrix[r][VALUE]
	
	auto const N=(int)N_;
	
	static_assert(offset>0 and offset<N);
	for(int row=0; row<(int)data.size(); ++row){
		assert(data[row][offset]!=0);
		for(int i=1; i<offset; ++i)
			assert(data[row][i]==0);

		{
			auto const inverseCur=1/data[row][offset];
			for(int j=offset+1; j<N; ++j)
				data[row][j]*=inverseCur;
			data[row][0]*=inverseCur;
			data[row][offset]=1;
		}

		for(int i=offset-1; i>0; --i){
			if(row+offset-i>=(int)data.size()) break;
			if(auto const tmp=data[row+offset-i][i]; tmp!=0){
				auto const multiplier=tmp;

				for(int j=offset; j<N; ++j)
					data[row+offset-i][i+j-offset]-=multiplier*data[row][j];
				assert(data[row+offset-i][i]==0);

				data[row+offset-i][0]-=multiplier*data[row][0];
			}
		}
	}

	for(auto row=(int)data.size(); row--;){
		auto const cur=data[row][offset];
		assert(cur==1);
		for(int i=1; i<offset;++i) assert(data[row][i]==0);
		for(int i=offset+1; i<N;++i) assert(data[row][i]==0);

		for(int i=offset+1; i<N;++i){
			if(row+offset-i<0) break;
			if(auto const tmp=data[row+offset-i][i]; tmp!=0){
				data[row+offset-i][i]=0;
				data[row+offset-i][0]-=tmp*data[row][0];
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numPeople; std::cin>>numPeople;
	assert(numPeople>1);
	std::vector<int> numBiscuit(numPeople);
	int sum{};
	for(auto& it: numBiscuit){ std::cin>>it; sum+=it; }
	if(sum==1){
		std::cout<<"0\n";
		return 0;
	}

	if(false)  // it isn't necessary to consider this special case
	if(numPeople==2){
		std::vector<std::array<modular, 4>> data(sum+1);
		int const offset= 2;
		data[0][offset]=1;
		data[0][0]=0;
		data.back()[offset]=1;
		data.back()[0]=0;

		for(int i=1; i<sum; ++i){
			data[i][offset]=-1;
			data[i][offset-1]=modular(i)/sum;
			data[i][offset+1]=modular(sum-i)/sum;
			data[i][0]=-1;
		}

		solve<offset>(data);
		std::cout<<(int)data[numBiscuit[0]][0]<<'\n';
		return 0;
	}
	// although is definitely is easiest case to solve



	auto const A=[&](modular it){return it/sum;};
	auto const B=[&](modular it){return (sum-it)/sum*(numPeople-2)/(numPeople-1)-1;};
	auto const C=[&](modular it){return (sum-it)/(sum*modular(numPeople-1));};

	std::vector<std::array<modular, 6>> data(sum); // variables: f[0], f[1],..., f[sum-1]
	int const offset=3;
	// 0=g[i-1]-2*g[i]+g[i+1]
	// = f[i-2]*something+f[i-1]*something+...

	data[0][offset]=1; // f[0]=0
	for(int i=1; i<sum-1; ++i){
		data[i]={{
			0,
			A(i-1),
			B(i-1)-2*A(i),
			C(i-1)-2*B(i)+A(i+1),
			0     -2*C(i)+B(i+1),
			0          +C(i+1)
		}};
	}
	data[sum-2][offset+2]=0; // this term is the coefficient of f[sum]==0
	data[sum-1][offset]=data[sum-1][0]=1; // arbitrary value. Because all other constant terms are 0, so...
	solve<offset>(data); // all fi values are multiplied by some fixed number

	auto const f=[&](int it)->modular{return it==sum ? 0: data[it][0];};
	auto const g=[&](int i){
		return (i==0 ? assert(A(i)==0), 0: f(i-1)*A(i))
			+f(i)*B(i)+f(i+1)*C(i); 
	};

	assert(f(0)==0);
	auto const multiplier=modular(-1)/(
			g(0)*(numPeople-2)+g(1)+g(sum-1)
			); // adjust f values
	for(auto& it: data) it[0]*=multiplier;

	assert(g(0)*(numPeople-2)+g(1)+g(sum-1)==-1);

	modular result{};
	for(auto it: numBiscuit) result+=f(it);
	std::cout<<(int)result<<'\n';
}