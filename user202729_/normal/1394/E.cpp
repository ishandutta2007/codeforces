// Change dynamic allocation to deque.
// ==
// from a cursory look at the editorial, a treap isn't necessary
//


#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
std::mt19937 engine(
  std::chrono::duration_cast<std::chrono::nanoseconds>(
   std::chrono::steady_clock::now().time_since_epoch()).count()
  );
       
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

using modular=Modular<1000000007>; // just one mod...

modular const base=
#if LOCAL
10
#else
std::uniform_int_distribution((int)1e6, int(1e9-1e6))(engine)
#endif
	;

struct Segment{ modular multiple, forward, backward; int length;
	// multiple=length^base
	[[nodiscard]] Segment flip() const{ return {multiple, backward, forward, length}; }
	void check() const{ assert(base.pow(length)==multiple); }
	[[nodiscard]] Segment operator+(Segment other) const{
		check(); other.check();
		return {
			multiple*other.multiple,
				forward*other.multiple+other.forward,
				other.backward*multiple+backward,
				length+other.length
		};
	}
	[[nodiscard]] Segment removePrefix(Segment prefix) const{
		check(); prefix.check();
		assert(length>=prefix.length);
		auto const inversePrefixMultiple=1/prefix.multiple;
		Segment result{ multiple*inversePrefixMultiple, 0,
			(backward-prefix.backward)*inversePrefixMultiple,
			length-prefix.length
		};
		result.forward=(forward-prefix.forward)/result.multiple;
		assert(prefix+result==*this);
		return result;
	}

	[[nodiscard]] static Segment empty(){return {1, 0, 0, 0};}
	[[nodiscard]] static Segment one(int value){return {base, value, value, 1};}

	[[nodiscard]] auto tie() const{ check(); return std::tie(length, forward, backward);}
#define COMPARE(OP) \
	[[nodiscard]] bool operator OP(Segment other) const{return tie() OP other.tie();}
	COMPARE(==) COMPARE(!=)
#undef COMPARE
};

struct TreapData;
using Treap=TreapData*;
std::deque<TreapData> treapDataPool;
struct TreapData{
	int priority;
	Segment sum;
	Segment cur;
	std::array<Treap, 2> children;
};

[[nodiscard]] Segment sum(Treap const& it){ return it ? it->sum: Segment::empty(); }
[[nodiscard]] int length(Treap const& it){ return sum(it).length; }

// these functions move from its treap argument.

// in rust, every pass-by-reference must be specified
// at both calling code and function declaration.
// Here, in C++, it's good practice to signifies pass-by-move with an explicit std::move(),
// but pass-by-reference can be implicit.
// [[nodiscard]] helps in this case (plus it's rather obvious that the result must be taken
// from the input, and treap is not copyable -- at least without much effort)
//
// -- edit: perfect forwarding involving template parameters.
// Let's use pass by value and explicit std::move instead.

[[nodiscard]] Treap recalculate(Treap it){
	assert(it);
	it->sum=sum(it->children[0])+it->cur+sum(it->children[1]);
	return it;
}

[[nodiscard]] std::pair<Treap, Treap> split(Treap it, int left){
	if(left==0) return {Treap{}, std::move(it)};
	assert(left<=it->sum.length);
	if(left==it->sum.length) return {std::move(it), Treap{}};
	auto& [a, b]=it->children;
	if(left<=length(a)){
		auto [c, d]=split(std::move(a), left);
		a=std::move(d);
		return {std::move(c), recalculate(std::move(it))};
	}else{
		auto [c, d]=split(std::move(b), left-length(a)-1);
		b=std::move(c);
		return {recalculate(std::move(it)), std::move(d)};
	}
}

[[nodiscard]] Treap merge(Treap left, Treap right){
	if(not left) return right;
	if(not right) return left;
	if(left->priority>right->priority){
		left->children[1]=merge(std::move(left->children[1]), std::move(right));
		return recalculate(std::move(left));
	}else{
		right->children[0]=merge(std::move(left), std::move(right->children[0]));
		return recalculate(std::move(right));
	}
}
template<class... Types>
[[nodiscard]] Treap merge(Treap left, Treap right, Types... rest){
	return merge(std::move(left), merge(std::move(right), std::move(rest)...));
}

[[nodiscard]] Treap makeTreap(Segment value){
	treapDataPool.push_back({
		(int)engine(),
			value,
			value,
			{}
	});
	return &treapDataPool.back();
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;

	auto const readSegment=[&]{
		int value; std::cin>>value;
		return Segment::one(value);
	};

#if 0
	std::vector<Segment> prefixes;
	prefixes.push_back(Segment::empty());
	std::vector<int> lengths;

	auto const sub=[&](std::size_t left, std::size_t right)->Segment{
		assert(left<=right);
		return prefixes[right].removePrefix(prefixes[left]);
	};

	prefixes.push_back(readSegment());
	lengths.push_back(1);

#endif

	std::vector<Treap> parts;
	parts.push_back(makeTreap(readSegment()));
	std::cout<<'0';
	
	int already=0; // number of guaranteed (implicit, not represented in the other data structures)
	// folds in the best fold

	for(int _=0; _<number-1; ++_){
		parts.push_back(makeTreap(readSegment()));
		while(parts.size()>1){
			auto b=std::move(parts.back()); parts.pop_back();
			auto a=std::move(parts.back()); parts.pop_back();
			auto const c=std::min(length(a), length(b));
			auto [a1, a2]=split(std::move(a), length(a)-c);
			auto [b1, b2]=split(std::move(b), c);
			if(sum(a2)==sum(b1).flip()){
				assert(not(a1 and b2));
				if(a1){ // len a > len b and match, done (optional fold)
					assert(not b2);
					parts.push_back(merge(std::move(a1), std::move(a2)));
					parts.push_back(std::move(b1));
					break;
				}else if(parts.empty()){ // remove segment a entirely
					++already;
					parts.push_back(merge(std::move(b1), std::move(b2)));
				}else{ // merge segment a
					already+=2;
					auto& c=parts.back();
					assert(length(c)>=length(b1));
					assert(length(b1)>0);
					assert(([&]{
						auto [c1, c2]=split(std::move(c), length(c)-length(b1));
						assert(sum(c2)==sum(b1));
						c=merge(std::move(c1), std::move(c2));
						return true;
					}()));
					c=merge(std::move(c), std::move(b2));
				}
			}else{ // must be straight
				parts.push_back(merge(std::move(a1), std::move(a2), std::move(b1), std::move(b2)));
			}
		}

		std::cout<<' '<<already+parts.size()-1;

#if 0
		assert(std::cerr<<"[");
		for(auto const& it: parts){
			assert(std::cerr<<(int)sum(it).forward<<' ');
		}
		assert(std::cerr<<"| already="<<already<<"]\n");
#endif
	}
	std::cout<<'\n';

}