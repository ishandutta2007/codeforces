// time-limit: 2000
// problem-url: https://codeforces.com/contest/1566/problem/F

//... spent 30' figuring out solution of G, then decide it's too difficult to implement

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int numPoint; std::cin>>numPoint;
	int numSegment; std::cin>>numSegment;
	std::vector<int> points(numPoint);
	for(auto& it: points) {
		std::cin>>it;
	}
	
	std::sort(begin(points), end(points));

	std::vector<std::pair<int, int>> segments(numSegment);
	for(auto& [l, r]: segments) std::cin>>l>>r;
	std::sort(begin(segments), end(segments), [&](auto const& first, auto const& sec){
		return first.first!=sec.first ? first.first<sec.first: first.second>sec.second;
	});
	// by increasing first, decreasing second

	{
		// if segment a is inside segment b, remove segment b
		// also remove segments that already contain a point
		auto out=segments.begin();
		for(auto segment: segments){

			auto iter=std::lower_bound(begin(points), end(points), segment.first);
			if(iter!=points.end() and *iter<=segment.second){
				// this segment already contain a point
				continue;
			}

			while(out!=segments.begin() and out[-1].second>=segment.second)
				out--;
			*out++=segment;
		}
		segments.erase(out, segments.end());
	}

	auto iter=segments.begin();
	int last=INT_MIN;
	struct T{
		int64_t distance, total; // int64_t just in case...
	};
	std::vector<T> items;

	std::vector<int64_t> X, Y;
	// X: minimum prefix of total+distance*2
	// Y: minimum suffix of total+distance

	auto const precompute=[&]()->void{
		// call this exactly once whenever items changed, so compute() can return correct result.
		X.resize(items.size()+1);
		X[0]=INT64_MAX;
		for(int index=0; index<(int)items.size(); ++index)
			X[index+1]=std::min(X[index], items[index].total+items[index].distance*2);

		Y.resize(items.size()+1);
		Y.back()=INT64_MAX;
		for(int index=(int)items.size(); index--;)
			Y[index]=std::min(Y[index+1], items[index].total+items[index].distance);
	};

	auto const compute=[&](int64_t lastRightLen)->int64_t{
		// return (minimum) total including last if last have to go right for (lastRightLen)
		auto tmp=INT64_MAX;
		auto const iter=std::upper_bound(begin(items), end(items), lastRightLen, [&](auto const& first, auto const& sec){
			return first<sec.distance;
		});

		/*
		for(auto [lastLeftLen, total]: items)
			tmp=std::min(tmp, total+lastLeftLen+lastRightLen+std::min(lastLeftLen, (int64_t)lastRightLen));
		*/

		/*
		for(auto i=items.begin(); i<iter; i++)
			tmp=std::min(tmp, i->total+i->distance*2+lastRightLen);
		for(auto i=iter; i<items.end(); i++)
			tmp=std::min(tmp, i->total+i->distance+lastRightLen*2);
			*/

		assert(X[0]==INT64_MAX);
		if(iter!=items.begin())
			tmp=std::min(tmp, X[iter-items.begin()]+lastRightLen);
		assert(Y.back()==Y[items.size()]); assert(Y.back()==INT64_MAX);
		if(iter!=items.end())
			tmp=std::min(tmp, Y[iter-items.begin()]+lastRightLen*2);

		return tmp;
	};

	
	for(auto point: points){
		auto next=iter;
		while(next!=segments.end() and next[0].first<point){
			assert(next[0].second<point);
			++next;
		}
		std::vector<T> items1;
		[&]()->void{
			// process
			// now item={distance, total}
			// distance: distance that (last) have to move to the left
			// total: total movement distance of points strictly <left
			// sorted by increasing distance

			// iter... next: range between the 2 points (last... point)
			if(last==INT_MIN){
				items1.push_back({
					.distance=iter==next ? 0: point-iter->second,
						.total=0
				});
				return;
			}

			/*
			if(iter==next){ // is this redundant?...
				auto tmp=INT64_MAX;
				for(auto [distance, total]: items)
					tmp=std::min(tmp, total+distance);
				assert(tmp!=INT64_MAX);
				items1.push_back({
					.distance=0,
						total=tmp
				});
				return;
			}
			*/

			precompute();

			items1.push_back({
				.distance=0,
					.total=compute(
							iter==next ? 0: next[-1].first-last
							)
			});

			for(auto middle=next;;){
				if(middle==iter) break;
				--middle;
				items1.push_back({
					.distance=point-middle->second,
						.total=compute(middle==iter ? 0: middle[-1].first-last
								)
				});
			}

		}();
		// items1:
		// distance: distance that (point) have to move to the left
		// total: total movement distance of points strictly <point (<=left)
		items=std::move(items1);
		iter=next;
		last=point;
	}

	precompute();

	// process last
	std::cout<<
		compute(iter==segments.end() ? 0: segments.back().first-last)
		<<'\n';
}