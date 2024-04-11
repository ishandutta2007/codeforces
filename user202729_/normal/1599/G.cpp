// time-limit: 1000
// problem-url: https://codeforces.com/contest/1599/problem/G

// still not proven, might be wrong...?

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct P{
	int x, y;

	P operator-(P other) const{return {x-other.x, y-other.y};}

	bool operator==(P other) const{return x==other.x and y==other.y;}

	int64_t dot(P other) const{return x*(int64_t)other.x+y*(int64_t)other.y;}
	int64_t norm() const{return dot(*this);}

	int64_t cross(P other) const{return x*(int64_t)other.y-y*(int64_t)other.x;}
};

int64_t cross(P first, P sec, P third){return(first-third).cross(sec-third);}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	int k; std::cin>>k; --k;

	std::vector<P> points(n);
	//std::unique_ptr<P[]> points(new P[n]);
	for(auto& [x, y]: points) std::cin>>x>>y;

	//int special=0; // the point outside the line
	assert(n>=3);
	std::pair<P, P> line={points[1], points[2]};
	// any two distinct points on the line

	if(n>=4){
		line=[&]{
			for(int i=0; i<4; ++i)
				for(int j=0; j<i; ++j)
					for(int k=0; k<j; ++k)
						if(cross(points[i], points[j], points[k])==0){
							return std::make_pair(points[i], points[j]);
						}
			assert(false);
		}();
	}

	assert((line.first-line.second).norm()!=0);
	auto const v=line.second-line.first;

	auto const pos=[&](P point)->int64_t{
		return (point-line.first).dot(v);
	};

	P const start=points[k];
	k=-1;
	std::sort(begin(points), end(points), [&](auto const& first, auto const& sec){
		return pos(first)<pos(sec);
	}); // still well defined for the special point
	// actually doesn't need sort but this is fast enough

	int special=-1;
	for(int i=0; i<n; ++i)
		if(cross(line.first, line.second, points[i])!=0){
			special=i;
			break;
		}

	assert(special>=0);

	assert((int)points.size()==n);
	k=int(std::find(begin(points), end(points), start)-points.begin());

	std::vector<int> pivots;
	if(k<special){
		pivots=std::vector<int>{0, k-1, k, k+1, special-2, special-1, special, special+1, special+2, n-1};
	}else{
		pivots=std::vector<int>{0, special-2, special-1, special, special+1, special+2, k-1, k, k+1, n-1};
	}

	{
		auto right=end(pivots);
		std::sort(begin(pivots), right);
		right=std::remove_if(begin(pivots), right, [&](auto x){return x<0 or x>=n;});
		right=std::unique(pivots.begin(), right);
		pivots.erase(right, pivots.end()); // ...
	}


	int total_mask=0;
	std::vector cover(pivots.size(), std::vector<int>(pivots.size()));

	auto const inPivots=[&](auto x)->bool{
		return std::find(begin(pivots), end(pivots), x)!=pivots.end();
	};

	auto const segment=[&](auto l, auto r, auto mask){
		while(l<r and inPivots(l+1)) l++;
		while(l<r and inPivots(r-1)) r--;
		if(l+1<r){
			// nonempty.
			assert(not(l+1<=special and special<=r-1));

			total_mask|=mask;
			for(int i=0; i<(int)pivots.size(); ++i)
				for(int j=0; j<(int)pivots.size(); ++j){ // fill cover[i][j]
					if(pivots[i]==special or pivots[j]==special) continue;
					if(
							(pivots[i]<=l and pivots[j]>=r)
							or
							(pivots[j]<=l and pivots[i]>=r)
					  ){
						// fill this mask
						cover[i][j]|=mask;
					}
				}
		}
	};

	if(k<special){
		segment(0, k-1  , 1);
		segment(k+1, special-2, 2);
		segment(special+2, n-1, 4);
	}else{
		segment(0, special-2  , 1);
		segment(special+2, k-1, 2);
		segment(k+1, n-1, 4);
	}

	double result=DBL_MAX;
	std::vector<int> permutation(pivots.size());
	for(int i=0; i<(int)pivots.size(); ++i) permutation[i]=i;
	do{
		if(pivots[permutation[0]]==k){
			int covered=0;
			for(int i=0; i<(int)pivots.size()-1; ++i)
				covered|=cover[permutation[i]][permutation[i+1]];
			if(covered==total_mask){
				double distance=0;
				for(int i=0; i<(int)pivots.size()-1; ++i)
					distance+=
						std::sqrt((points[pivots[permutation[i]]]-points[pivots[permutation[i+1]]]).norm());

				result=std::min(result, distance);
			}
		}
	}while(std::next_permutation(begin(permutation), end(permutation)));
	
	std::cout<<std::fixed<<std::setprecision(8);
	std::cout<<result<<'\n';
}