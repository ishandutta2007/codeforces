// An algorithm using hash. O(n log^2 n).
//
// Stress tested against assertions.
// This is not the first time I implement tree-search, and I still get it wrong.
// Perhaps I should use the less memory-efficient method (traverse the range,
// store every intermediate nodes, iterate the resulting list)
//
// Not tested by large inputs.



#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
#include<variant>
std::mt19937 engine(
  std::chrono::duration_cast<std::chrono::nanoseconds>(
   std::chrono::steady_clock::now().time_since_epoch()).count()
  );
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

using Hash=Modular<1000000007>;
Hash const base(std::uniform_int_distribution<int>(1000000, 1000000006)(engine));

std::vector<Hash> basePowData;
std::vector<Hash>::iterator basePow;


struct SegmentTree{
	/*
	 *
	 *     #
	 *      #
	 *       #
	 *        #   /\/\       /\*
	 *         # /    \     *
	 *          #      \   *
	 *                  # *
	 *                   o
	 * ----+-------------------+------> pos
	 *    left               right
	 *
	 * data[0]= (number of #, parentheses value of # -- topmost = least significant, base=base)
	 * data[1]= (number of *, parentheses value of *)
	 */
	struct Node{
		struct Side{
			int height;
			Hash value;
		};
		//int left, right;
		bool used;
		std::optional<std::array<Side, 2>> data;

		template<bool first>
		void assign(int value){
			assert(used);
			assert(value!=0);
			if(first) data=std::array<Side, 2>{}; else assert(data);
			if(value>0){
				(*data)[0]={};
				(*data)[1]={1, Hash(value)};
			}else{
				(*data)[0]={1, Hash(-value)};
				(*data)[1]={};
			}
		}

		static Node empty(){
			return {//0, 0,
				true,
				{{ Side{}, Side{} }} };
		}

		bool balanced() const{
			assert(used);
			return data and (*data)[0].height==0 and (*data)[1].height==0;
		}
	};
	std::vector<Node> data;

	__attribute__((pure)) int offset()const{ return int(data.size()/2u); }

	__attribute__((pure)) int getLeafPosition(int node)const{
		while(node<offset()) node<<=1;
		return node;
	}

	enum class DescendSide{ left=0, right=1 };

	template<DescendSide side_> int descend(int node, int height) const{
		if(height==0) return node;

		auto const side=(int)side_;
		assert((*data[node].data)[side].height>=height);

		if(node>=offset()) // leaf
			return node+not side;

		auto const d=*data[node*2+side].data;
		if(d[side].height>=height)
			return descend<side_>(node*2+side, height);
		else
			return descend<side_>(node*2+not side, height-d[side].height+d[not side].height);
	}

	template<DescendSide side_> int descendFromPos(int node, int height) const{
		// might loop forever if there's no such node
		// O(log n).
		assert(node>=offset());

		if(side_==DescendSide::left){
			while(true){
				while(not data[node].data) node<<=1;
				if(height>(*data[node].data)[0].height){
					if((node&1)==0 and data[node>>1].data) node>>=1;
					else{
						height+=(*data[node].data)[1].height-(*data[node].data)[0].height;
						++node;
					}
				}else
					return descend<side_>(node, height);
			}
		}else{
			while(true){
				while(not data[node-1].data) node<<=1;
				if(height>(*data[node-1].data)[1].height){
					if((node&1)==0 and data[(node>>1)-1].data) node>>=1;
					else{
						height+=(*data[node-1].data)[0].height-(*data[node-1].data)[1].height;
						--node;
					}
				}else
					return descend<side_>(node-1, height);
			}
		}
	}

	enum class CheckedState{ unchecked, checked };
	//enum class CombineRange{ local, range };

	template<CheckedState checkedState
		//, CombineRange combineRange
		>
	void combineNode(Node& result, Node const& left, int split, Node const& right) const{
		//if(combineRange==CombineRange::local){
		//	assert(left.left==getLeafPosition(split-1)-offset() and left.right==getLeafPosition(split)-offset());
		//	assert(right.left==getLeafPosition(split)-offset() and right.right==getLeafPosition(split+1)-offset());
		//}
		assert(result.used);

		bool constexpr checked=checkedState==CheckedState::checked;
		// alias (result and left|right) is okay
		if constexpr(checked) {
			assert(offset()<=split);
			if(not left.data or not right.data){
				result.data={};
				return;
			}
		}

		auto const [a, b]=*left.data; auto const [c, d]=*right.data;
		if(b.height>c.height){
			if constexpr(checked){
				if(c.height!=0){
					auto const x=descendFromPos<DescendSide::right>(split, c.height);
					auto const [height_, value_]=(*getRangeNode<CheckedState::unchecked>(x, split).data)[1];
					assert(height_==c.height);
					if(value_!=c.value) {
						result.data={}; return;
					}
				}
			}

			result.data={
				a,
				Node::Side{ b.height-c.height+d.height, (b.value-c.value)*basePow[d.height-c.height]+d.value }};
		}else{
			if constexpr(checked){
				if(b.height!=0){
					auto const x=descendFromPos<DescendSide::left>(split, b.height);
					auto const [height_, value_]=(*getRangeNode<CheckedState::unchecked>(split, x).data)[0];
					assert(height_==b.height);
					if(value_!=b.value) {
						result.data={}; return;
					}
				}
			}

			result.data={
				Node::Side{ c.height-b.height+a.height, (c.value-b.value)*basePow[a.height-b.height]+a.value },
				d};
		}
	}


	template<CheckedState checkedState>
	Node getRangeNode(int leftNode, int rightNode) const{
		Node leftSum=Node::empty(), rightSum=Node::empty();

		for(; leftNode!=rightNode; leftNode>>=1, rightNode>>=1){
			if(leftNode&1) {
				combineNode<checkedState>(leftSum , leftSum, getLeafPosition(leftNode), data[leftNode]);
				++leftNode;
			}
			if(rightNode&1) {
				combineNode<checkedState>(rightSum, data[rightNode-1], getLeafPosition(rightNode), rightSum);
				--rightNode;
			}
		}

		combineNode<checkedState>(leftSum, leftSum,  getLeafPosition(leftNode), rightSum);
		return leftSum;
	}
	template<CheckedState checkedState>
	Node getRange(int left, int right) const{ return getRangeNode<checkedState>(left+offset(), right+offset()); }


	template<bool first, CheckedState checked> void combine(int node){
		auto& parent=data[node];
		assert(parent.used);
		auto const& left=data[node*2]; auto const& right=data[node*2+1];

		//assert(parent.left==left.left and parent.right==right.right);
		//if(first) { parent.left=left.left; parent.right=right.right; }
		//assert(parent.left==left.left and parent.right==right.right);
		//assert(left.right==right.left);
		if(not left.data or not right.data){ parent.data={}; return; }

		combineNode<checked>(parent, left, getLeafPosition(node*2+1), right);
	}

	void set(int index, int value){
		assert(index<offset()); index+=offset();
		data[index].assign<false>(value);
		for(int y=index>>1;y;y>>=1) {
			if(not data[y].used) break;
			combine<false, CheckedState::checked>(y);
		}
	}

	static SegmentTree readFromInput(int len){
		SegmentTree result; result.data.resize(len*2);

		for(auto & node: result.data) node.used=true;
		{
			result.data[0].used=false;
			auto const process=[&](auto node){
				for(node>>=1; node; node>>=1) result.data[node].used=false;
			};
			for(int leftNode=len, rightNode=2*len; leftNode!=rightNode; leftNode>>=1, rightNode>>=1){
				if(leftNode&1) process(leftNode++);
				if(rightNode&1) process(--rightNode);
			}
		}


		for(int index=0;index<len;++index) {
			int value; std::cin>>value;
			auto& node=result.data[len+index];
			//node.left=index; node.right=index+1;
			node.assign<true>(value);
		}
		for(int i=len; --i;) {
			//if(result.data[i*2].right==result.data[i*2+1].left)
			if(result.data[i].used)
				result.combine<true, CheckedState::checked>(i);
		}
		return result;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int len, numParen; std::cin>>len>>numParen;

	basePowData.resize(len*2+1);
	basePowData[0]=(1/base).pow(-len);
	for(int index=1;index<(int)basePowData.size();++index) 
		basePowData[index]=basePowData[index-1]*base;
	basePow=basePowData.begin()+len;


	auto tree=SegmentTree::readFromInput(len);
	int numQuery; std::cin>>numQuery;
	while(numQuery--){
		char type; std::cin>>type;
		if(type=='2'){
			int left, right; std::cin>>left>>right;--left;
			std::cout<<(
					tree.getRange<SegmentTree::CheckedState::checked>(left, right).balanced()
					? "Yes\n": "No\n");
		}else{
			int index, value; std::cin>>index>>value;
			tree.set(--index, value);
		}
	}
}