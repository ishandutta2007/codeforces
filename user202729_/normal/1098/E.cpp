#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

//#define GENERATE_RANDOM_RUNS 1
//#define STRESS_TEST 1

int64_t countTriangleNaive(int64_t gapX, int64_t gapY, int64_t distance){
	int64_t result{};
	for(int i=0;i*gapX<=distance;++i) 
		for(int j=0;i*gapX+j*gapY<=distance;++j) 
			++result;
	return result;
}

// {gcd, ax} | gcd == ax*x + ay*y for some integer y
std::pair<int64_t, int64_t> extendedGcd(int64_t const x, int64_t const y){
	int64_t a=x, b=y, ax=1, bx=0;
	while(b){
		ax-=bx*(a/b); a%=b;
		std::swap(a, b); std::swap(ax, bx);
	}
	return {a, ax};
}

int64_t countUnderNaive(int64_t x, int64_t y, int64_t maxX){
	// returns number of points with 0<=x<=maxX and are not above the line (0, 0)...(x, y)
	int64_t result{};
	for(int curX=0;curX<=maxX;++curX) 
		result+=(y*curX)/x+1;
	return result;
}

template<bool include=true>
int64_t countUnder(int64_t x, int64_t y, int64_t maxX){
	if(y>=x) return (y/x)*maxX*(maxX+1)/2 + countUnder<include>(x, y%x, maxX);
	if(y==0) return include ? maxX+1: 0;
	auto y1=y*maxX/x;
	return (maxX+1)*(y1+1)-countUnder<not include>(y, x, y1);
}

// == countTriangleNaive
int64_t countTriangle(int64_t gapX, int64_t gapY, int64_t distance){
	//return countTriangleNaive(gapX, gapY, distance);

	if(distance<0) return 0;
	auto [g, ax]=extendedGcd(gapX, gapY);
	if(distance<g) return 1;
	gapX/=g; gapY/=g; distance/=g;
	assert((1-ax*gapX)%gapY==0);
	auto const ay=(1-ax*gapX)/gapY;

	auto x1=ax*distance, y1=ay*distance;
	//if(y1>0)  // <-  (easier to create integer overflow)
	{
		auto const q=y1/gapX+1;
		x1+=gapY*q; y1-=gapX*q;
		assert(y1<=0);
	}

	auto x2=x1, y2=y1;
	//if(x2>0)
	{
		auto const q=x2/gapY+1;
		x2-=gapY*q; y2+=gapX*q;
		assert(x2<=0);
	}

	auto const dx=x1-x2, dy=y2-y1;
	assert(dx>0); assert(dy>0);
	assert(dx/gapY==dy/gapX);

	assert(std::gcd(dx, dy)==dx/gapY);
	auto const tmp=((dx+1)*(dy+1)+dx/gapY+1)/2;
	assert(countUnder(dx, dy, dx)==tmp);
	return
		countUnder(dx, dy, x1)+countUnder(dy, dx, y2)+x2*y1 -tmp;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
#if not GENERATE_RANDOM_RUNS
	int number; std::cin>>number;
	std::vector<int> values(number);for(auto & it: values) std::cin>>it;
#endif

	struct run{ int value, count; };
	std::vector<run> runs;
#if not GENERATE_RANDOM_RUNS
	{
		int right=1;
		struct minLeft{ int left, value; };
		std::vector<minLeft> lefts{ {0, values[0]} };
		while(true){
			// process (lefts, right)
			runs.push_back({lefts.back().value, right-lefts.back().left});
			for(int index=1;index<(int)lefts.size();++index) 
				runs.push_back({lefts[index-1].value, lefts[index].left-lefts[index-1].left});

			// increment right
			if(right==number) break;
			for(auto &[_, value]: lefts) value=std::gcd(value, values[right]);
			lefts.erase(std::unique(begin(lefts),end(lefts),
						[&](auto first, auto sec){ return first.value==sec.value; }), lefts.end());
			if(lefts.back().value!=values[right])
				lefts.push_back({right, values[right]});
			++right;
		}
	}

	{ // process (runs)
		std::sort(begin(runs),end(runs),[&](run first, run sec){ return first.value<sec.value; });
		assert(not runs.empty()); auto out=++runs.begin();
		std::for_each(out, runs.end(),[&](auto item){
			if(item.value==out[-1].value)
				out[-1].count+=item.count;
			else *out++=item;
		});
		runs.erase(out, runs.end());
	}
	// now (runs) is the run-length encoding of the array (b)
#endif

#if not GENERATE_RANDOM_RUNS
	auto const lenB=number*int64_t(number+1)/2; // <= 1.25e9
	assert(lenB==std::accumulate(begin(runs),end(runs), (int64_t)0, [&](auto result, run run_){
		return result+run_.count;
	}));
#else
	int lenRuns,seed; std::cin>>lenRuns>>seed;
	std::mt19937 engine(seed);

	runs.resize(lenRuns);
	//std::sort(begin(runs),end(runs), [&](

	int64_t lenB{};
	for(auto & it: runs) {
		it={
			std::uniform_int_distribution(1, 3)(engine),
			std::uniform_int_distribution(1, 3)(engine)
		};
		lenB+=it.count;
	}


#endif
	
	auto const lenC=lenB*int64_t(lenB+1)/2; // <= 7.812500007e17

	auto const sumB=std::accumulate(begin(runs),end(runs), (int64_t)0, [&](auto result, run run_){
		return result+run_.value*(int64_t)run_.count;
	}); // also maxC. About max(A)*lenB <= 1.25e14

	auto const numLENaive=[&](int64_t const value){
		std::vector<int64_t> prefixSums{0};
		for(auto [value, count]: runs){
			assert(value!=0);
			for(int _=0;_<count;++_) 
				prefixSums.push_back(prefixSums.back()+value);
		}
		int64_t result{};
		for(auto large: prefixSums)
		for(auto small: prefixSums){
			if(small==large) break;
			result+=(large-small<=value);
		}
		//assert(std::cerr<<"naive result="<<result<<'\n');
		return result;
	};

	auto const numLE=[&](int64_t const value){ // count number of values in array C <= value
		int64_t result=-lenB*int64_t(lenB-1)/2;
		// -(number of points on or below the diagonal, and above the y==0 line, exclude the last column)

		auto iterator=runs.begin();

		int64_t leftX=0, downY=0, upY=iterator->count*(int64_t)iterator->value;
		int64_t lenUnderY=0;

		auto const distanceUnderLine=[&](int64_t x, int64_t y){ return x+value-y; };
		auto const underLine=[&](int64_t x, int64_t y){ return distanceUnderLine(x, y)>=0; };

		auto const incrementIterator=[&]{
			lenUnderY+=iterator->count;
			++iterator;
			downY=upY;
			if(iterator!=runs.end())
				upY+=iterator->count*(int64_t)iterator->value;
		};


		for(auto [runValue, count]: runs){
			auto const rightX=leftX+count*(int64_t)runValue;

			while(iterator!=runs.end() and underLine(leftX, upY))
				incrementIterator();
			assert(underLine(leftX, downY)); // block under iterator must be fully under the line
			result+=lenUnderY*count;
			while(iterator!=runs.end() and underLine(rightX, upY)){
#if 1
				result+=count*(int64_t)iterator->count;
				result-=countTriangle(runValue, iterator->value, -distanceUnderLine(leftX, upY)-1);
				result+=countTriangle(runValue, iterator->value, -distanceUnderLine(leftX, downY)-1);
#else
				for(int i=0;i<count;++i)
					for(int j=0;j<iterator->count;++j)
						result+=underLine(leftX+i*runValue, upY-j*iterator->value);
#endif

				incrementIterator();
			}

			if(iterator!=runs.end()){
#if 1
				result+=countTriangle(runValue, iterator->value, distanceUnderLine(rightX-runValue, downY+iterator->value));
				result-=countTriangle(runValue, iterator->value, distanceUnderLine(leftX-runValue, downY+iterator->value));
#else
				for(int i=0;i<count;++i) 
					for(int j=0;j<iterator->count;++j)
						result+=underLine(leftX+i*runValue, upY-j*iterator->value);
#endif
			}

			leftX=rightX;
		}
		//assert(false);

		assert(result==numLENaive(value));
		return result;
	};

#if STRESS_TEST
	for(int i=0;i<100;++i) 
		numLE(i);
#else
	auto result=sumB;
	for(int64_t step=(int64_t)1<<60; step; step>>=1)
		if(result-step>=0 and numLE(result-step)>=(lenC+1)/2)
			result-=step;

	assert(result==[&]{
		std::vector<int64_t> prefixSums{0};
		for(auto [value, count]: runs){
			assert(value!=0);
			for(int _=0;_<count;++_) 
				prefixSums.push_back(prefixSums.back()+value);
		}
		std::vector<int64_t> values;
		for(auto large: prefixSums)
		for(auto small: prefixSums){
			if(small==large) break;
			values.push_back(large-small);
		}
		auto const iter=values.begin()+(values.size()-1)/2;
		std::nth_element(values.begin(), iter, values.end());
		return *iter;
	}());

	std::cout<<result<<'\n';
#endif
}