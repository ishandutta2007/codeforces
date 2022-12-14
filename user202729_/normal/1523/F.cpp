// time-limit: 2000
// problem-url: https://codeforces.com/contest/1523/problem/F

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTower; std::cin>>numTower;
	int numQuest; std::cin>>numQuest;
	
	struct Pos{int x, y;
		int distance(Pos other) const{return std::abs(x-other.x)+std::abs(y-other.y);}
	};

	std::vector<Pos> towers(numTower);
	for(auto& [x, y]: towers) std::cin>>x>>y;

	struct Quest{
		Pos p; int time;
	};
	std::vector<Quest> quests(numQuest);
	for(auto& [p, time]: quests) std::cin>>p.x>>p.y>>time;
	std::sort(begin(quests), end(quests), [&](auto const& first, auto const& sec){
		return first.time<sec.time;
	});

	struct State{
		int count /* number of completed quests so far */, time;
		bool operator<(State other) const{return time>other.time;}// priority queue top is least time
	};


	std::vector<std::vector<int>> f(numQuest+1, std::vector<int>(1<<numTower, INT_MAX));
	std::vector<std::vector<int>> g(numQuest, std::vector<int>(1<<numTower, INT_MIN));
	for(auto& item: g) item[0]=1;
	for(int tower=0; tower<numTower; ++tower)
		f[0][1<<tower]=0;

	int finalResult=1; // just spawn at a quest location

	for(int mask=0; mask<(1<<numTower); ++mask){

		std::vector<int> distanceTeleportToTower(numTower, INT_MAX);
		for(int j=0; j<numTower; ++j)
			for(int i=0; i<numTower; ++i) if(mask>>i&1)
				distanceTeleportToTower[j]=std::min(distanceTeleportToTower[j],
						towers[i].distance(towers[j]));

		std::vector<int> distanceTeleportToQuest(numQuest, INT_MAX);
		for(int j=0; j<numQuest; ++j)
			for(int i=0; i<numTower; ++i) if(mask>>i&1)
				distanceTeleportToQuest[j]=std::min(distanceTeleportToQuest[j],
						towers[i].distance(quests[j].p));


		auto const distanceWithTeleportToTower=[&](Pos source, int tower){
			int result=source.distance(towers[tower]);
			result=std::min(result, distanceTeleportToTower[tower]);
			return result;
		};

		auto const distanceWithTeleportToQuest=[&](Pos source, int pos){
			int result=source.distance(quests[pos].p);
			result=std::min(result, distanceTeleportToQuest[pos]);
			return result;
		};

		std::priority_queue<State> states; // only f-states
		for(int count=0; count<=numQuest; ++count)
			if(f[count][mask]!=INT_MAX)
				states.push({count, f[count][mask]});

		auto const process=[&](Pos p, int time, int count){
			if(count==INT_MIN) return;

			for(int bit=0; bit<numTower; ++bit) if(not(mask>>bit&1)){
				auto& target=f[count][mask|1<<bit];
				target=std::min(target, time+distanceWithTeleportToTower(p, bit));
			}

			for(int pos=0; pos<numQuest; ++pos)
				if(time<quests[pos].time and // avoid double-counting one quest
						time+distanceWithTeleportToQuest(p, pos)<=quests[pos].time){
					auto& target=g[pos][mask];
					target=std::max(target, count+1);
					finalResult=std::max(finalResult, count+1);
				}
		};

		int gProcessed=0;
		while(not states.empty()){
			auto state=states.top(); states.pop();
			if(f[state.count][mask]!=state.time){
				assert(f[state.count][mask]<state.time);
				continue;
			}


			while(gProcessed<numQuest and quests[gProcessed].time<state.time){
				process(quests[gProcessed].p, quests[gProcessed].time, g[gProcessed][mask]);
				gProcessed++;
			}

			
			assert(mask);
			process(towers[__builtin_ctz(mask)], // any tower is okay
					state.time,
					state.count
				   );
		}

		while(gProcessed<numQuest){
			process(quests[gProcessed].p, quests[gProcessed].time, g[gProcessed][mask]);
			gProcessed++;
		}
	}

	std::cout<<finalResult<<'\n';
}