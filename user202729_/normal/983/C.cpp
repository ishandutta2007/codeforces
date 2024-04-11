// Think simple. 9 is small.
// Teddious implementation...
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<array>

int constexpr NFLOOR=9;
using state_t=std::array<int8_t,4>;

auto const states=[]{
	std::array<state_t,715> states;
	auto out_iter=begin(states);

	state_t st;
	for(st[0]=0;st[0]<=NFLOOR;++st[0])
	for(st[1]=0;st[1]<=NFLOOR;++st[1])
	for(st[2]=0;st[2]<=NFLOOR;++st[2])
	for(st[3]=0;st[3]<=NFLOOR;++st[3]){ // NFLOOR : empty
		if(std::is_sorted(begin(st),end(st)))
			*out_iter++=st;
	}

	assert(out_iter==end(states));
	assert(std::is_sorted(begin(states),end(states)));
	//std::cerr<<states.size()<<'\n';
	return states;
}();

auto state_ind(state_t x){
	auto iter=std::lower_bound(begin(states),end(states),x);
	assert(x==*iter); return int(iter-begin(states));
}

auto const state_add=[]{
	std::array<std::array<int,NFLOOR>,states.size()> state_add;
	for(unsigned old_state=0;old_state<states.size();++old_state)
		for(int x=NFLOOR;x--;){
			auto st=states[old_state];
			auto& cur_out=state_add[old_state][x];
			if(st.back()!=NFLOOR)
				cur_out=-1;
			else{
				st.back()=int8_t(x);
				std::sort(begin(st),end(st));
				cur_out=state_ind(st);
			}
		}
	return state_add;
}();

auto const state_rm=[]{
	std::array<std::array<int,NFLOOR>,states.size()> state_rm;
	for(unsigned old_state=0;old_state<states.size();++old_state)
		for(int x=NFLOOR;x--;){
			auto st=states[old_state];
			auto iter=std::remove(begin(st),end(st),x);
			std::fill(iter,end(st),NFLOOR);
			state_rm[old_state][x]=state_ind(st);
		}
	return state_rm;
}();

/*
auto const state_cnt=[]{
	std::array<int8_t,states.size()> state_cnt;
	std::transform(begin(states),end(states),[](auto st){
			return st.size()-std::count(begin(st),end(st),NFLOOR);
			});
	return state_cnt;
}();
*/

/*
auto const state_isfull=[]{
	std::array<bool,states.size()> state_isfull;
	std::transform(begin(states),end(states),[](auto st){
			return std::all_of(begin(st),end(st),[](auto x){ return x!=NFLOOR; });
			});
	return state_isfull;
}();
*/

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::array<std::array<int,NFLOOR>,states.size()> dp;
	// dp[state][floor elevator is at] = min time to reach state excluding time to get in/out of elevator

	std::memset(&dp,0x7F,sizeof dp);
	struct dpstate{
		int time,st,floor;
		bool operator<(dpstate s)const{ return time>s.time; }
	};
	std::priority_queue<dpstate> q; // TODO is deque faster?

	auto const run_dijkstra=[&]{
		auto const update=[&](int new_time,int new_st,int nfloor){
			assert(new_time<0x7F7F7F7F);
			auto& dpx=dp[new_st][nfloor];
			if(new_time<dpx) q.push({dpx=new_time,new_st,nfloor});
		};
		while(not q.empty()){
			auto [time,st,floor]=q.top();q.pop();
			if(dp[st][floor]<time)continue;
			assert(dp[st][floor]==time);
			update(time,state_rm[st][floor],floor);
			if(floor!=0) update(time+1,st,floor-1);
			if(floor+1!=NFLOOR) update(time+1,st,floor+1);
		}
	};

	auto const elevator_empty_state=state_ind({NFLOOR,NFLOOR,NFLOOR,NFLOOR});
	{
		auto const initial_floor=0;
		q.push({dp[elevator_empty_state][initial_floor]=0,elevator_empty_state,initial_floor});
	}
	run_dijkstra();

	for(int z=n;z--;){
		int start_floor,end_floor;
		std::cin>>start_floor>>end_floor;
		--start_floor; --end_floor;
		
		auto const old_dp=dp;
		std::memset(&dp,0x7F,sizeof dp);
		assert(q.empty());
		for(unsigned st=states.size();st--;){
			auto new_st=state_add[st][end_floor];
			if(new_st>=0 and old_dp[st][start_floor]!=0x7F7F7F7F){
				assert(old_dp[st][start_floor]<0x7F7F7F7F);
				assert(dp[new_st][start_floor]==0x7F7F7F7F);
				q.push({dp[new_st][start_floor]=old_dp[st][start_floor],new_st,start_floor});
			}
		}
		run_dijkstra();
	}
	
	auto out=*std::min_element(begin(dp[elevator_empty_state]),end(dp[elevator_empty_state]));
	std::cout<<2*n+out<<'\n';
}