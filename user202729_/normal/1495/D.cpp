#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
       
template<class F> struct Modular_ {
 static auto MOD(){ return
  (F::get()); }
 using T=typename std::decay<decltype((F::get()))>::type;
 T val;
 explicit operator T() const { return val; }
 Modular_():val(){}
 template<class U> static auto check_mod_mod()->decltype(std::declval<U>()%(F::get()), void());
 template<class U
  , class=decltype(check_mod_mod<U>())
  > Modular_(U v):val(T(v%(F::get()))){ if(val<0)val+=(F::get()); }
 template<class U> static Modular_ raw(U value){
  assert(0<=value); assert(value<(F::get()));
  Modular_ result; result.val=value; return result;
 }
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
using modular=Modular<998244353>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n, m; std::cin>>n>>m;
	auto const infinity=INT_MAX/2;
	std::vector<std::vector<int>> distance(n, std::vector<int>(n, infinity));
	std::vector<std::vector<int>> add(n);
	for(int _=0; _<m; ++_){
		int a; std::cin>>a; --a;
		int b; std::cin>>b; --b;
		distance[a][b]=distance[b][a]=1;
		add[a].push_back(b); add[b].push_back(a);
	}
	for(int c=0; c<n; ++c)
		distance[c][c]=0;
	for(int c=0; c<n; ++c)
		for(int a=0; a<n; ++a)
			for(int b=0; b<n; ++b)
				distance[a][b]=std::min(distance[a][b], distance[a][c]+distance[c][b]);

	std::vector<int> bfsDistance(n), markDistance(n);
	std::vector<int> queue; queue.reserve(n);
	std::vector<std::vector<modular>> result_(n, std::vector<modular>(n));
	for(int a=0; a<n; ++a)
		for(int b=0; b<n; ++b){
			if(a>b){ result_[a][b]=result_[b][a]; continue; }
			std::fill(markDistance.begin(), markDistance.begin()+distance[a][b]+1, 0);
			bfsDistance.assign(n, infinity);

			modular& result=result_[a][b];
			assert(result==0);
			[&]{
				queue.clear();
				// push to queue all nodes on the unique path from a..b
				for(int c=0; c<n; ++c)
					if(distance[a][c]+distance[c][b]==distance[a][b]){
						if(markDistance[distance[a][c]])
							// if there are more than one paths, return immediately
							return;
						markDistance[distance[a][c]]=true;
						bfsDistance[c]=0;
						queue.push_back(c);
					}

				assert((int)queue.size()==distance[a][b]+1);

				// typical BFS
				result=1;
				for(auto it=queue.begin(); it!=queue.end(); it++){
					assert((int)queue.size()<=n); assert((int)queue.capacity()==n);
					auto const curDistance=bfsDistance[*it];
					if(distance[a][b]+2*curDistance!=distance[a][*it]+distance[b][*it]){
						result=0;
						return;
					}
					int count{};
					for(auto other: add[*it]) if(bfsDistance[other]==infinity){
						bfsDistance[other]=curDistance+1;
						queue.push_back(other);
					}else{
						assert(bfsDistance[other]<=curDistance+1);
						count+=bfsDistance[other]==curDistance-1;
					}
					assert((count==0)==(curDistance==0));
					if(count!=0) result*=count;
				}
			}();
		}

	for(int a=0; a<n; ++a){
		for(int b=0; b<n; ++b)
			std::cout<<(int)result_[a][b]<<' ';
		std::cout<<'\n';
	}
}