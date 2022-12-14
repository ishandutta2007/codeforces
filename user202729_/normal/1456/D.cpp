// intentionally wrong
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	struct Point{int time, pos;
		Point decreaseTime(int delta) const{
			assert(delta>=0);
			return {time-delta, pos};
		}
		int restTime(Point other) const{ // negative: not possible to reach
			assert(time<other.time);
			return (other.time-time)-std::abs(pos-other.pos);
		}
	};
	std::vector<Point> points(number+1);
	//points[0]={0, 0};
	for(int index=0; index<number; ++index){
		std::cin>>points[index+1].time>>points[index+1].pos;
	}
#if LOCAL
	std::sort(begin(points), end(points), [&](auto const& first, auto const& sec){
		return first.time<sec.time;
	});
#endif

	std::vector<int> lastConnected(points.size());
	lastConnected[(int)lastConnected.size()-1]
		=
		(int)lastConnected.size()-1;
	for(int i= (int)lastConnected.size()-2; i>=0; i--)
		lastConnected[i]= points[i].restTime(points[i+1])>=0 ? lastConnected[i+1]: i;

	struct U{int f; bool g;}; // (see not-attached notes)
	std::vector<U> data(number+1); // inclusive right
	data[0]={0, false}; // include point points[0]=(0, 0) already
	for(int index=1; index<(int)data.size(); ++index){
		auto& cur=data[index]={-1, false};

		{
			auto const j=index-1;
			auto const last=data[j];

			auto const check=[&](Point lastPosition){
				// clones must not be created until last.time
				assert(cur.f>=-1); // so f=max(f, tmp) is no-op if tmp<0
				assert(index>j);

				cur.f=std::max(cur.f, 
						std::min(points[index].time-points[j].time,
							lastPosition.restTime(points[index]))
						);
			};

			if(last.f>=0){
				check(points[j].decreaseTime(last.f));
			}
			if(last.g){
				check(points[j-1]);
			}
		}

		for(int j=0; j<index-1; ++j){
			auto const check=[&](Point lastPosition){
				assert(points[j+1].time>lastPosition.time);
				int const secondLength=std::abs(points[index].pos-points[j+1].pos);
				cur.g=cur.g or (
						points[j+1].time-lastPosition.time
						>=
						std::abs(lastPosition.pos-points[index].pos)+ secondLength
						and
						lastConnected[j+1]>=index-1
						and
						secondLength<=points[j+1].time-points[j].time
						);
			};

			auto const last=data[j];
			if(last.f>=0){
				check(points[j].decreaseTime(last.f));
			}
			if(last.g){
				check(points[j-1]);
			}
		}
	}
	std::cout<<((data.back().f>=0 or data.back().g) ? "YES\n": "NO\n");
}