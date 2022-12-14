// time-limit: 2500
// problem-url: https://codeforces.com/contest/1572/problem/D

// ...
// just a little too slow...?
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
#include<variant>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numBit; std::cin>>numBit;
	int k; std::cin>>k;
	k=std::min(k, 1<<(numBit-1));
	auto const numPlayer=1<<numBit;
	std::vector<int> money(numPlayer);
	for(auto& it: money) {
		std::cin>>it;
	}
	
	struct DirectEdge{
		int value, a, b;
		bool operator<(DirectEdge other) const{return value<other.value;};
	};
	std::priority_queue<DirectEdge> edges; // pop is largest value
	for(int i=0; i<numPlayer; ++i){
		for(int bit=numPlayer; bit>>=1;)
			if(i&bit)
				edges.push({
					money[i] + money[i^bit],
					i,
					i^bit
				}); // one entry per undirected edge
	}

	std::vector<int> match(numPlayer, -1); // the other player, or -1 if there's none
	std::vector<int> matched; // set of items with match value>=0

	std::vector<int> trace(numPlayer, -1); // temp vector
	std::vector<int> queue; // temp vector for bfs
	auto const find=[&](int a, auto b1){
		// if b is monostate, find as usual
		// if b is not, keep trace and go back
		struct{int money, pos;}best{INT_MIN, INT_MIN};

		// bfs
		queue.clear();
		queue.push_back(a); trace[a]=INT_MAX;
		for(int index=0; index<(int)queue.size(); ++index){
			a=queue[index]; assert(trace[a]>=0);
			auto const b=match[a]; assert(trace[b]<0);
			for(int bit=numPlayer; bit>>=1;){
				auto const c=b^bit;
				if(c==a) continue;
				if(match[c]>=0){
					if(trace[c]>=0) continue;
					queue.push_back(c); trace[c]=a;
				}else{
					if constexpr(std::is_same_v<decltype(b1), std::monostate>){

						// find as usual
						if(money[c]>best.money) best={money[c], c};

					}else{

						if(c==b1){
							// go back and flip edges
							match[c]=b; match[b]=c;

							while(true){
								auto x=trace[a];
								if(x==INT_MAX) break;
								match[a]=match[x];
								match[match[x]]=match[a];
								a=x;
							}

							// done
							goto break_outer;
						}
						

					}
				}
			}
		}
break_outer:

		// reset trace for next iterations
		for(auto x: queue){
			assert(trace[x]>=0);
			trace[x]=-1;
		}

		return best;
	};


	int totalMoney {}; // 200  1e6 small
	for(int _=0; _<k; ++_){

		// remove unusable direct edges
		while(not edges.empty() and 
				(match[edges.top().a]>=0 or
				match[edges.top().b]>=0))
			edges.pop();

		struct{int money, a1, a, b1;}bestPair{INT_MIN};
		if(not edges.empty()){
			auto a=edges.top().a;
			auto b=edges.top().b;
			bestPair={money[a]+money[b], a, b, b};
		}

		// compute indirect edges
		for(auto a: matched) if(__builtin_popcount(a)%2==0){

			struct{int money, pos;}bestA{INT_MIN, INT_MIN};
			for(int bit=numPlayer; bit>>=1;){
				auto const c=a^bit;
				if(match[c]<0 and money[c]>bestA.money) bestA={money[c], c};
			}
			if(bestA.pos==INT_MIN) continue;


			auto bestB=find(a, std::monostate{});
			if(bestB.pos==INT_MIN) continue;


			if(bestA.money+bestB.money>bestPair.money) bestPair={bestA.money+bestB.money,
				bestA.pos, a, bestB.pos
			};
		}

		assert(bestPair.money!=INT_MIN);
		totalMoney+=bestPair.money;

		if(bestPair.a!=bestPair.b1)
			find(bestPair.a, bestPair.b1);
		//assert(match[bestPair.a]==-1);
		assert(match[bestPair.a1]==-1);
		match[bestPair.a]=bestPair.a1;
		match[bestPair.a1]=bestPair.a;

		matched.push_back(bestPair.a1); matched.push_back(bestPair.b1);
	}
	std::cout<<totalMoney<<'\n';
}