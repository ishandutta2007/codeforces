// :(
// 6
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;

	struct T{int64_t left, value;};
	struct F{
		std::vector<T> segments; // sorted by increasing left
		int64_t last;
		void check() const{assert(last>segments.back().left);}

		int64_t maximum(int slope)const{
			check();
			auto result=INT64_MIN;
			for(int index=0; index<(int)segments.size(); ++index){
				auto pos=(index==(int)segments.size()-1 ? last: segments[index+1].left)-1;
				auto value=segments[index].value;
				result=std::max(result, pos*slope+value);
			}
			return result;
		}

		F split(int64_t const pos, int const slope){
			check();
			assert(pos<last and pos>=0);
			F right; right.last=last-pos; last=pos;
			int i=(int)segments.size()-1; while(segments[i].left>pos)--i;
			right.segments.resize(segments.size()-i);
			int64_t const delta=slope*pos;
			for(int index=0; index<(int)right.segments.size(); ++index)
				right.segments[index]={
					segments[i+index].left-pos,
					segments[i+index].value+delta};
			assert(right.segments[0].left<=0);
			if(right.segments[0].left<0){
				right.segments[0].left=0;
				++i;
			}
			segments.erase(segments.begin()+i, segments.end());
			return right;
		};
	}; // the slope is not stored in F
	std::vector<F> functions;
	int slope=0;
	int64_t maxPendSize=0, minLastValue=INT64_MAX;

	auto const pushPend=[&]{
		if(maxPendSize==0){
			assert(functions.size()==1);
			return;
		}
		assert(functions.size()>1);

		struct Event{
			int64_t pos;
			int64_t add, remove;
			bool operator<(Event other) const{return pos<other.pos;}
		};
		std::vector<Event> events;
		for(auto const& it: functions){
			it.check();
			assert(it.last<=functions[0].last);
			int64_t last=INT_MIN;
			for(auto [left, value]: it.segments){
				events.push_back({left, value, last});
				last=value;
			}
			if(it.last!=functions[0].last)
				events.push_back({it.last, INT64_MIN, last});
		}
		std::sort(begin(events), end(events));
		int64_t last=0;
		std::multiset<int64_t, std::greater<>> values;
		F result; result.last=functions[0].last;
		for(auto [pos, add, remove]: events){
			if(pos!=last){
				result.segments.push_back({last, *values.begin()});
				last=pos;
			}
			if(pos)
				values.erase(values.find(remove));
			if(add!=INT64_MIN)
				values.insert(add);
		}
		result.segments.push_back({last, *values.begin()});
		assert(last<result.last);

		functions.clear(); functions.push_back(std::move(result));
		maxPendSize=0;
	};

	auto const addPend=[&](F f){
		maxPendSize=std::max(maxPendSize, f.last);
		functions.push_back(std::move(f));
	};

	std::vector<int64_t> values;
	assert((values.resize(number), true));
	for(int _=0; _<number; ++_){
		int64_t value; std::cin>>value;
		assert((values[_]=value));
		if(functions.empty()){
			functions.push_back({{T{0, 0}}, value});
			assert(slope==0);
			assert(maxPendSize==0);
		}else{
			assert(functions[0].last==minLastValue);
			if(value<minLastValue){
				if(std::max(maxPendSize, minLastValue-value)>value){
					pushPend();
				}

				//bool seenBlock=false;
				auto cur=std::move(functions[0]);
				if(cur.last%value!=0){
					addPend(cur.split(cur.last/value*value, slope));
				}
				assert(cur.last%value==0);
				while(cur.last!=value){
					assert(cur.last%value==0);
					assert(cur.last>value);
					assert(cur.segments.back().left<cur.last);
					if(cur.segments.back().left<cur.last-value){
						// single block
						addPend(cur.split(cur.last-value, slope));

						// remove all remaining blocks
						assert((cur.segments.back().left+value-1)/value*value<=cur.last);
						assert(cur.last>=value);
						cur.last=(cur.segments.back().left+value-1)/value*value;

						if(cur.last==0){
							cur.last=value;
						}else if(cur.last==cur.segments.back().left)
							cur.segments.pop_back();
					}else
						addPend(cur.split(cur.last-value, slope));
				}
				functions[0]=std::move(cur);
			}
		}
		++slope;
		minLastValue=std::min(minLastValue, value);
	}
	pushPend();
	auto const result=functions[0].maximum(slope);
	std::cout<<result<<'\n';
	assert(([&]{
		auto naive=-1;
		for(int start=0; start<values[0]; ++start){
			int result=0, cur=start;
			for(auto it: values) result+=cur%=it;
			naive=std::max(naive, result);
		}
		assert(naive==result);
		return true;
	}()));
}