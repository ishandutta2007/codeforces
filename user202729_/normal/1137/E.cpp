// I feel that this is easier than both C and D...?
// 38 min impl + ~0 think (actually it may be more than that of C, but definitely less than D)
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int start_ncar,nquery;std::cin>>start_ncar>>nquery;

	int offset=0;
	int64_t sumb=0,sums=0;
	struct car{
		int pos;int64_t val;
	};

	auto const realval=[&](car c){
		return c.val+sumb+sums*c.pos;
	};

	std::vector<car> train{ {0,0} };
	// if c=[pos,val] int train -> value of car at 0-based index (pos+offset) = realval(c)
	// train only contain the lower convex hull int strictly decreasing (real value) / increasing pos order

	int endpos=start_ncar;
	// currently there are (endpos+offset) trains, with
	// pos = -offset, -offset+1, ..., endpos-1 <=> index = 0, 1, ..., endpos-1+offset
	
	//enum class add_location {front,back};

	auto const add_back=[&](int index,int64_t realval_){
		int pos =index-offset;
		car c{pos,realval_-sumb-sums*pos};
		assert(realval(c)==realval_);

		if(train.empty()){ train.push_back(c);return; }
		if(realval_>=realval(train.back())) return;

		for(unsigned i=1;i<train.size();++i)
			assert(realval(train[i-1])>realval(train[i]));

		while(train.size()>=2){
			std::pair<int,int64_t>
				x{train.end()[-2].pos,realval(train.end()[-2])},
				y{train.back().pos   ,realval(train.back())},
				z{c.pos              ,realval_},
				v1{y.first-x.first,y.second-x.second},
				v2{z.first-y.first,z.second-y.second};
			double v1_cross_v2=(double)v1.first*v2.second-(double)v1.second*v2.first;
			if(v1_cross_v2<=0) // TODO optimize formula to avoid having to use double?
				train.pop_back();
			else
				break;
		}
		train.push_back(c);
	};

	for(int z=nquery;z--;){
		char type;std::cin>>type;
		int cnt,b,s;
		switch(type){
			case '1':
				std::cin>>cnt;
				offset+=cnt;

				for(auto c:train)
					assert(realval(c)>=0);

				train.clear();
				add_back(0,0);

				break;
			case '2':
				std::cin>>cnt;
				endpos +=cnt;
				add_back(endpos+offset-cnt,0);
				break;
			case '3':
				std::cin>>b>>s;
				sums+=s; // the train at pos (-offset) will get value += s*(-offset). Need to balance that.
				sumb+=s*(int64_t)offset;

				sumb+=b;
				while(train.size()>=2 and realval(train.back())>=realval(train.end()[-2]))
					train.pop_back();
				break;
			default:
				assert(false);__builtin_unreachable();
		}

		std::cout
			<<train.back().pos+offset+1<<' '
			<<realval(train.back())
			<<'\n';
	}
}