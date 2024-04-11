// :(

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
struct Fraction{
 int numerator, denom;
 void constexpr check() const{
  assert(denom>0);
 }
 [[nodiscard]] bool constexpr operator ==(Fraction other)const{ check(); other.check(); return (int64_t)numerator*other.denom == (int64_t)other.numerator*denom; } [[nodiscard]] bool constexpr operator !=(Fraction other)const{ check(); other.check(); return (int64_t)numerator*other.denom != (int64_t)other.numerator*denom; } [[nodiscard]] bool constexpr operator <(Fraction other)const{ check(); other.check(); return (int64_t)numerator*other.denom < (int64_t)other.numerator*denom; } [[nodiscard]] bool constexpr operator >(Fraction other)const{ check(); other.check(); return (int64_t)numerator*other.denom > (int64_t)other.numerator*denom; } [[nodiscard]] bool constexpr operator <=(Fraction other)const{ check(); other.check(); return (int64_t)numerator*other.denom <= (int64_t)other.numerator*denom; } [[nodiscard]] bool constexpr operator >=(Fraction other)const{ check(); other.check(); return (int64_t)numerator*other.denom >= (int64_t)other.numerator*denom; }
};

using modular=Modular<998244353>;

struct pipe{
	int pos, speed;
	modular probability; // to the right, 0~1
};
std::vector<pipe> pipes;


struct SegmentTree{
	struct Node{
		std::array<std::array<modular, 2>, 2> probability;
		// [left value][right value]=probability of choosing the middle elements and satisfy all conditions
		// (1: right, 0: left)
		// (not multiplied by the probability of choosing the boundary elements)

		void combine(Node first, Node sec, modular midRightProbability){
			for(int left=0; left<2; ++left)
				for(int right=0; right<2; ++right)
					probability[left][right]=
						first.probability[left][0]* sec.probability[0][right]* (1-midRightProbability)+
						first.probability[left][1]* sec.probability[1][right]* midRightProbability;
		}
	};
	std::vector<Node> data;
	SegmentTree(int number): data(2*number, {{1, 1, 1, 1}}){
		for(auto node=number;--node;)
			combine(node);
	}

	int nodeAt(int index) const{
		assert(unsigned(index)<unsigned(data.size()/2));

		index+=1<<(31^__builtin_clz((int)data.size()));
		if(index>=(int)data.size()) index-=int(data.size()/2);
		return index;
	}

	void combine(int node){
		// ......
		auto splitNode=(node*2+1)<<(
				(31^__builtin_clz((int)data.size())) - (31^__builtin_clz(node*2+1))
				);
		if(splitNode>=(int)data.size()) splitNode>>=1;

		auto splitIndex=splitNode-(1<<(31^__builtin_clz((int)data.size())));
		if(splitIndex<0) splitIndex+=int(data.size()/2);
		assert(nodeAt(splitIndex)==splitNode or nodeAt(splitIndex)*2==splitNode);

		data[node].combine(data[node*2], data[node*2+1], pipes[splitIndex].probability);
	}

	Node getCondition(int index)const{
		return data[nodeAt(index)];
	}

	void set(int index, Node value){
		int node=nodeAt(index);
		data[node]=value;
		for(node>>=1; node; node>>=1) combine(node);
	}

	modular get() const{
		modular result{};
		assert(pipes.size()==data.size()/2+1);
		for(int left=0; left<2; ++left)
			for(int right=0; right<2; ++right)
				result+=data[1].probability[left][right]
					*(left ? pipes[0].probability: 1-pipes[0].probability)
					*(right ? pipes.back().probability: 1-pipes.back().probability);
		return result;
	}
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	if(number==1){ std::cout<<"0\n"; return 0; }

	pipes.resize(number);
	for(auto &[pos, speed, probability]: pipes){
		int percent;
		std::cin>>pos>>speed>>percent;
		probability=modular(percent)/100;
	}

	SegmentTree segmentTree(number-1);
	struct Condition{
		int index; // [0~number-1[
		char first, sec; // 0: left, 1: right
		Fraction time;
		auto operator<(Condition other) const{return time<other.time;};
	};

	std::vector<Condition> conditions; conditions.reserve(number*2);
	for(int index=0; index<number-1; ++index){
		auto const a=pipes[index].speed, b=pipes[index+1].speed, d=pipes[index+1].pos-pipes[index].pos;
		assert(d>0);
		conditions.push_back({index, 1, 0, Fraction{d, a+b}});
		if(a<b)
			conditions.push_back({index, 0, 0, Fraction{d, b-a}});
		else if(a>b)
			conditions.push_back({index, 1, 1, Fraction{d, a-b}});
	}
	assert((int)conditions.size()<=number*2);

	assert(segmentTree.get()==1); // no conditions imposed so far

	std::sort(begin(conditions), end(conditions));
	modular result{};
	for(auto [index, first, sec, time]: conditions){
		// require (condition)
		auto const oldCondition=segmentTree.getCondition(index);

		auto newCondition1=oldCondition; // ==oldCondition and (collide with this condition)
		for(int left=0; left<2; ++left)
			for(int right=0; right<2; ++right)
				if(left!=first or right!=sec) newCondition1.probability[left][right]=0;
		segmentTree.set(index, newCondition1);
		result+=segmentTree.get()*modular(time.numerator)/time.denom;

		auto newCondition2=oldCondition; // ==oldCondition and not (collide with this condition)
		newCondition2.probability[first][sec]=0;
		segmentTree.set(index, newCondition2);
	}
	std::cout<<(int)result<<'\n';
}