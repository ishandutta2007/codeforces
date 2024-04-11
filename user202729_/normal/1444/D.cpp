// not completely proven (see comments in code)
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

bool split(std::vector<int>& data) {
	// flip signs of data such that the sum is 0.
	for(auto it: data) assert(it>0);
	int sum=std::accumulate(begin(data), end(data), 0);
	if(sum%2!=0) return false;

	int half=sum/2;
	int const maxHalf=500000;
	assert(half<=maxHalf);
	using B=std::bitset<maxHalf+1>;
	
	static std::vector<B> table;
	table.resize(data.size()+1); // memory consumption: 500000/8*1000 = 500/8 MB
	table[0][0]=true; // it's unnecessary to set table[0]={} because the other bits are not set anywhere
	for(int index=1; index<=(int)data.size(); ++index)
		table[index]=table[index-1]|table[index-1]<<data[index-1];

	if(not table[data.size()][half]) return false;

	int curSum=half;
	for(int index=(int)data.size(); index--;){
		assert(table[index+1][curSum]);
		if(not table[index][curSum]){
			assert(data[index]>0);
			curSum-=data[index];
			data[index]=-data[index];
			assert(table[index][curSum]);
		}
	}
	assert(curSum==0);
	return true;
}

void up(){
	// okay...
	int n; std::cin>>n;
	std::vector<int> horizontal(n);
	for(auto& it: horizontal) {
		std::cin>>it;
	}
	int n_; std::cin>>n_;
	std::vector<int> vertical(n_);
	for(auto& it: vertical) {
		std::cin>>it;
	}
	if(n!=n_ or not split(horizontal) or not split(vertical)){
		std::cout<<"No\n";
		return;
	}


	auto horizontalSorted=horizontal, verticalSorted=vertical;
	std::sort(begin(horizontalSorted), end(horizontalSorted));
	std::sort(begin(verticalSorted), end(verticalSorted));

	struct Segment{int index, coordinate;
		bool operator<(Segment other) const{return coordinate<other.coordinate;}
	};
	std::vector<Segment> segments;

	// this is proven to converge, but **not** proven to have a correct result
	// **or** converge in 10 iterations...

	for(int _=0; _<10; ++_){
		// consider horizontal segments
		int x=0, y=0;
		segments.clear();
		for(int i=0; i<n; ++i){
			segments.push_back({i, y});
			x+=horizontal[i];
			y+=vertical[i];
		}
		assert(x==0); assert(y==0);
		std::stable_sort(begin(segments), end(segments));
		for(int index=0; index<n; ++index)
			horizontal[segments[index].index]=horizontalSorted[index];

		// consider vertical segments
		x=0, y=0;
		segments.clear();
		for(int i=0; i<n; ++i){
			x+=horizontal[i];
			segments.push_back({i, x});
			y+=vertical[i];
		}
		assert(x==0); assert(y==0);
		std::stable_sort(begin(segments), end(segments));
		for(int index=0; index<n; ++index)
			vertical[segments[index].index]=verticalSorted[index];
	}

	std::cout<<"Yes\n";
	int x=0, y=0;
	for(int i=0; i<n; ++i){
		std::cout<<x<<' '<<y<<'\n';
		x+=horizontal[i];
		std::cout<<x<<' '<<y<<'\n';
		y+=vertical[i];
	}
	assert(x==0); assert(y==0);


}