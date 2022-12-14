// [I didn't read the editorial or see the failed test case]
// {}
// is it safe to use only 1 mod?

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
  Modular_ ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
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
template<int x> struct IntConstGetter{ int operator()() const{ return x; } };
template<int MOD> using Modular=Modular_<IntConstGetter<MOD>>;
template<int& x> struct IntPointerGetter{ int operator()() const{ return x; } };
template<int& MOD> using ModularP=Modular_<IntPointerGetter<MOD>>;
std::mt19937 engine(
  std::chrono::duration_cast<std::chrono::nanoseconds>(
   std::chrono::steady_clock::now().time_since_epoch()).count()
  );

using modular=Modular<1000000007>;

int const maxNumber=8000;
std::vector<std::bitset<maxNumber>> add;

std::vector<int> order; std::vector<char> visited;
void computePostOrder(int node){
	assert(not visited[node]);
	visited[node]=true;
	for(int other=0;other<(int)add.size();++other) if(add[node][other] and not visited[other])
		computePostOrder(other);
	order.push_back(node);
}

int main(){
	modular const base(std::uniform_int_distribution<int>(2, 1000000006)(engine));

	std::ios::sync_with_stdio(0);std::cin.tie(0);
	unsigned number; std::cin>>number;
	assert(number<=maxNumber);
	add.resize(number);
	{
		std::string line; line.reserve(number/4);
		for(unsigned row=0;row<number;++row) {
			std::cin>>line; assert(line.size()==(number+3)/4);
			for(int index=0;index<(int)line.size();++index) {
				auto const ch=line[index];
				auto const digit=ch>='A' ? ch-'A'+10 : ch-'0';
				for(int x=0;x<4;++x)
					add[row][index*4+x]=digit>>(3-x)&1;
			}
		}
	}

	visited.assign(number, false);
	assert(order.empty()); order.reserve(number);
	for(auto node=number; node--;) if(not visited[node])
		computePostOrder(node);

	int64_t result=0;
	while(not order.empty() and std::all_of(order.begin(), order.end()-1, [&](auto it){
		return add[order.back()][it];
	})) {
		order.pop_back();
		result+=(int64_t)order.size()*(614*number+1);
	}

	// now the remaining part is a strongly connected component and
	// doesn't have an edge that points to any outside vertex
	
	std::vector<modular> value(number);
	for(auto node: order){
		value[node]=0;
		for(int index=number; index--;) value[node]=value[node]*base+add[node][index];
	}

	std::vector<modular> basePow(number);
	{
		modular basePowIndex=basePow[0]=1;
		for(unsigned index=1; index<number;++index) basePow[index]=basePowIndex*=base;
	}


	std::vector<int> next(number, -1), previous(number, -1);
	for(auto first: order){
		for(auto sec: order) if(add[first][sec]){
			if(value[first]==value[sec]+basePow[sec]){
				// edge first->sec is compressible
				next[first]=sec;
				previous[sec]=first;
				break;
			}
		}
	}

	result+= order.size()*int64_t(order.size()-1)/2 * (1+2);

	// if a can reach b with only compressible edges, then d(a, b)==1 and d(b, a)==3
	// otherwise, d(a, b)==1 and d(b, a)==2, or vice versa
	for(auto start: order) if(previous[start]<0){
		int count=1;
		while(next[start]>=0){
			++count;
			start=next[start];
		}
		result+=count*int64_t(count-1)/2; // 1+2 -> 1+3
	}

	std::cout<<result<<'\n';
}