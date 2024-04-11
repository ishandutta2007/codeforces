


#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> a(number);for(auto& it: a) std::cin>>it;
	struct Query{int x, y, index;};
	int numQuery; std::cin>>numQuery;
	std::vector<Query> queries(numQuery);
	for(int index=0, x, y; index<numQuery; ++index){
		std::cin>>x>>y;
		queries[index]={x, --y, index};
	}
	std::sort(begin(queries), end(queries),[&](auto first, auto sec){return first.y>sec.y;});

	struct Segment{
		int length; int slope;
		int64_t change() const{return length*(int64_t)slope;}
	};
	struct Tree{
		struct Segment1{
			int length; int64_t change;
			operator Segment() const{
				if(length==0) return {0, 0}; // workaround
				assert(change%length==0);
				return {length, int(change/length)};
			}
			Segment1 operator+(Segment1 other) const{return {length+other.length, change+other.change};}
		};
		std::vector<Segment1> data;
		Tree(int size): data(size*2){}
		int size()const{return int(data.size()/2);}

		Segment get(int index){return data[size()+index];}

		void set(int index, Segment value){
			//assert(value.length>0);
			int node=index+size();
			data[node]={value.length, value.length*(int64_t)value.slope};
			for(node>>=1; node; node>>=1)
				data[node]=data[node*2]+data[node*2+1];
		}

		int64_t valueAfter(int left, int length) const{
			left+=size(); int right=(int)data.size();
			std::vector<int> rights;
			int64_t pastValue=0;

			auto const extract=[&](int node, int length, int64_t pastValue){
				while(node<size()){
					node<<=1;
					if(length>=data[node].length){
						length-=data[node].length;
						pastValue+=data[node].change;
						++node;
					}
				}
				assert(length>=0); assert(length<=data[node].length);
				return pastValue+Segment(data[node]).slope*(int64_t)length;
			};

			for(; left<right; left>>=1, right>>=1){
				if(left&1){
					auto const node=left++;

					if(data[node].length>=length)
						return extract(node, length, pastValue);
					length-=data[node].length;
					pastValue+=data[node].change;
				}
				if(right&1) rights.push_back(--right);
			}
			for(auto index=rights.size(); index--;){
				auto const node=rights[index];
				if(data[node].length>=length)
					return extract(node, length, pastValue);
				length-=data[node].length;
				pastValue+=data[node].change;
			}
			assert(false);
		}
	};
	//std::vector<Segment> changes(number+1);
	Tree changes(number+1);



	int start=(int)changes.size();
	std::vector<int64_t> result(queries.size());
	for(int index=0;; ++index){
		auto const ai=a[index];

		{
			int pos=start;
			std::pair<int64_t, int64_t> value{};
			while(true){
				if(pos==(int)changes.size()){
					start=pos;
					assert(value.first<=number);
					changes.set(--start, {(int)value.first+1, ai});
					break;
				}
				auto value1=value;
				value1.first+=changes.get(pos).length;
				value1.second+=changes.get(pos).change();
				if(value1.second<=value1.first*ai){
					if(value.first==0){
						changes.set(--start, {1, ai});
						break;
					}else{
						assert(changes.get(pos).slope<ai);
						assert(value.second>value.first*ai);
						auto const delta_=(value.second-value.first*ai)/(ai-changes.get(pos).slope);
						assert(delta_<=changes.get(pos).length);
						auto const delta=(int)delta_-(delta_==changes.get(pos).length);
						auto const y1=ai*(value.first+delta), y2=y1+ai,
							 z1=value.second+changes.get(pos).slope*delta, z2=z1+changes.get(pos).slope;
						assert(y1<=z1); assert(z2<=y2);

						changes.set(pos, {changes.get(pos).length-delta-1, changes.get(pos).slope});
						start=pos;
						assert(z2>=y1);
						assert(z2-y1<=ai);
						changes.set(--start, {1, int(z2-y1)});
						changes.set(--start, {int(value.first+delta+1), ai});
						break;
					}
				}else{
					++pos; value=value1;
				}
			}
		}

		while(true){ // process queries
			if(queries.empty()) goto break_outer;
			if(queries.back().y!=index) break;
			auto const [x, y_, queryIndex]=queries.back();
			assert(y_==index);

			if(0){
				std::pair<int64_t, int64_t> value{};
				for(int pos=start;;++pos){
					if(x<=value.first+changes.get(pos).length){
						assert(value.first<=x);
						result[queryIndex]=value.second+(x-value.first)*changes.get(pos).slope;
						break;
					}
					value.first+=changes.get(pos).length; value.second+=changes.get(pos).change();
				}
			}else{
				result[queryIndex]=changes.valueAfter(start, x);
			}

			queries.pop_back();
		}
	}

break_outer:
	assert(queries.empty());
	for(auto it: result) std::cout<<it<<'\n';
}