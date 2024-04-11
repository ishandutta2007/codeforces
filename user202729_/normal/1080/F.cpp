// (why do I have this problem in the "pending problem set" anyway?)
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numSet, numQuery, numSegment; std::cin>>numSet>>numQuery>>numSegment;
	struct Segment{int left, right;
		bool operator==(Segment other) const{return std::tie(left, right)== std::tie(other.left, other.right); }
		//auto operator<=>(const Segment&)const=default;
		bool contains(Segment other) const{return left<=other.left and other.right<=right;}
	};
	struct Set{
		std::vector<Segment> segments;
		void buildSet(){ // for efficient `anyInside` answers
			if(segments.empty()) return;
			std::sort(begin(segments), end(segments), [&](auto const& first, auto const& sec){
				return first.right!=sec.right ? first.right<sec.right: first.left>sec.left;
			});
			auto out=segments.begin()+1;
			std::for_each(out, segments.end(), [&](auto const& it){
				if(it.left>out[-1].left) *out++=it;
				else assert(it.contains(out[-1]));
			});
			segments.erase(out, segments.end());
			//assert(checkSetBuilt()); // infinite recursion with this line
		}
		[[nodiscard]] bool checkSetBuilt()const{
			Set tmp{segments};
			tmp.buildSet();
			assert(tmp.segments==segments);
			return true;
		}
		bool anyInside(Segment container) const{
			assert(checkSetBuilt());
			/*
			return std::any_of(begin(segments), end(segments), [&](auto const& it){
				return container.contains(it);
			});
			*/
			auto const iter=std::lower_bound(begin(segments), end(segments), container.left, [&](Segment a, int b){
				return a.left<b;
			});
			return iter!=segments.end() and (
					assert(iter->left>=container.left), iter->right<=container.right);
		}
		Set combine(Set other) const{
			// such that a.combine(b).anyInside(segment) == (a.anyInside(segment) and b.anyInside(segment))
			assert(checkSetBuilt());
			assert(other.checkSetBuilt());
			/* // this implementation will make the `and` an `or`. Wrong.
			for(auto it: segments) other.segments.push_back(it);
			other.buildSet();
			*/

			auto it1=segments.end(); auto it2=other.segments.end();
			int right1=INT_MAX, right2=INT_MAX;
			Set result{};
			while(not(it1==segments.begin() and it2==other.segments.begin())){
				// merge in decreasing left order
				// built set must have segments stored in increasing left order.
				int curLeft;
				if(it1!=segments.begin() and (it2==other.segments.begin() or it1[-1].left>it2[-1].left)){
					--it1;
					right1=it1->right;
					curLeft=it1->left;
				}else{
					--it2;
					right2=it2->right;
					curLeft=it2->left;
				}
				int curRight=std::max(right1, right2);
				if(curRight==INT_MAX){ assert(result.segments.empty()); continue; }
				if(result.segments.empty()){ result.segments.push_back({curLeft, curRight}); continue; }
				assert(curLeft<=result.segments.back().left);
				assert(curRight<=result.segments.back().right);
				if(curRight==result.segments.back().right) continue;
				if(curLeft==result.segments.back().left) result.segments.pop_back();
				result.segments.push_back({curLeft, curRight});
			}
			std::reverse(begin(result.segments), end(result.segments));
			assert(result.checkSetBuilt());
			return result;
		}
	};
	//std::vector<Set> sets(numSet);
	struct Tree{
		std::vector<Set> data;
		Tree(int number): data(number*2){}
		int offset() const{return int(data.size()/2);}
		void build(){
			for(int i=offset(); i--;) data[i+offset()].buildSet();
			for(int i=offset(); --i;) data[i]=data[i<<1].combine(data[i<<1|1]);
		}
	};
	Tree tree(numSet);
	auto allSatisfy=[&](int left, int right, auto f){
		for(left+=tree.offset(), right+=tree.offset(); left<right; left>>=1, right>>=1){
			if(left&1) if(not f(tree.data[left++])) return false;
			if(right&1) if(not f(tree.data[--right])) return false;
		}
		return true;
	};
	for(int _=0; _<numSegment; ++_){
		int left, right, setIndex; std::cin>>left>>right>>setIndex;
		--setIndex;
		//sets[setIndex]
		tree.data[tree.offset()+setIndex]
			.segments.push_back({left, right});
	}
	tree.build();
	for(int _=0; _<numQuery; ++_){
		int firstSet, lastSet; Segment s;
		std::cin>>firstSet>>lastSet>>s.left>>s.right;
		--firstSet;
		bool result;

		/*
		result=std::all_of(sets.begin()+firstSet, sets.begin()+lastSet, [&](Set const& it){
			return it.anyInside(s);
		});
		*/

		result=allSatisfy(firstSet, lastSet, [&](auto const& it){ return it.anyInside(s); });

		std::cout<<(result? "yes\n": "no\n")<<std::flush;
	}
}