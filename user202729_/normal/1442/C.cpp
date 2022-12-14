// ???
// ah, the sample test cases is not sufficient for testing the second part of the code.
// okay, those bugs are fun.
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
//#include<Modular.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge; std::cin>>numNode>>numEdge;

	std::array<std::vector<std::vector<int>>, 2> add; // 0: forward, 1: reverse
	for(auto& it: add) it.resize(numNode);
	for(int _=0; _<numEdge; ++_){
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		add[0][first].push_back(sec); add[1][sec].push_back(first);
	}

	int const start=0, target=numNode-1;
	int result=INT_MAX;
	{
		std::vector<std::array<int, 20>> distance; // [node][bit]. flip < 20 times
		distance.resize(numNode);
		for(auto& it: distance) it.fill(INT_MAX);

		struct State{int node, numFlip, distance;
			bool operator<(State other) const{return distance>other.distance;}
		};
		std::priority_queue<State> q;
		q.push({start, 0, distance[start][0]=0});
		while(not q.empty()){
			auto const [node, numFlip, distance_]=q.top(); q.pop();
			assert(distance_>=distance[node][numFlip]);
			if(distance_>distance[node][numFlip]) continue;
			if(node==target) result=std::min(result, distance_);

			for(auto other: add[numFlip&1][node])
				if(distance_+1 < distance[other][numFlip])
					q.push({other, numFlip, distance[other][numFlip]=distance_+1 });

			if(numFlip+1<(int)distance[0].size() and
					distance[node][numFlip+1]
					>
					distance_+(1<<numFlip)
			  )
				q.push({node, numFlip+1, distance[node][numFlip+1]=distance_+(1<<numFlip)});
		}
	}

	int const MOD=998244353;
#if LOCAL
	//result=INT_MAX;
#endif
	if(result==INT_MAX){
		//using modular=Modular<998244353>;
		struct T{ int numFlip, numEdge;
			// numFlip: if ==0 mod 2 then add[0] is usable and vice versa
			//modular value()const{ return modular(2).pow(numFlip+1)-1+numEdge; }
			auto tie() const{return std::tie(numFlip, numEdge);}
			bool operator<(T other) const{ return tie()<other.tie(); }
		};
		struct State{int node, bit; T t;
			bool operator<(State other) const{ return other.t<t; }
		};
		std::priority_queue<State> q;
		// std::vector<std::array<T, 2>> distance(numNode, {INT_MAX, INT_MAX}); //[node][bit]
		// * aggregate initialization is dangerous...
		std::vector<std::array<T, 2>> distance(numNode); //[node][bit]
		for(auto& it: distance) it.fill(T{INT_MAX, INT_MAX});
		q.push({start, 0, distance[start][0]={0, 0}});
		T best{INT_MAX, INT_MAX};
		while(not q.empty()){
			auto const [node, bit, t]=q.top(); q.pop();
			assert((t.numFlip&1)==bit);
			assert(not(t<distance[node][bit]));
			if(distance[node][bit]<t) continue;
			if(node==target)
				best=std::min(best, t);

			for(auto other: add[t.numFlip&1][node]){
				auto const nextT=T{t.numFlip, t.numEdge+1};
				if(nextT < distance[other][bit])
					q.push({other, bit, distance[other][bit]=nextT });
			}

			auto const nextT=T{t.numFlip+1, t.numEdge};
			if(nextT < distance[node][not bit])
				q.push({node, not bit, distance[node][not bit]=nextT});
		}

		assert(best.numFlip!=INT_MAX);
		int tmp=1;
		for(int _=best.numFlip; _--;) tmp=tmp*2%MOD;
		result=(tmp-1+best.numEdge)%MOD;
	}

	assert(result!=INT_MAX);

	std::cout<<result<<'\n';
}