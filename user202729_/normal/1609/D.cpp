// time-limit: 2000
// problem-url: https://codeforces.com/contest/1609/problem/D
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// too slow


struct DSU{
	struct Item{int par, size;};
	std::vector<Item> p;
	DSU():p(){}
	DSU(int n):p(){reset(n);}
	void reset(int n){
		p.resize(n);
		while(n--)p[n]={n, 1};
	}
	int root(int x){
		return p[x].par!=x?p[x].par=root(p[x].par):x;
	}
	int join(int a,int b){ // let root(a) be the root, return new size
		a=root(a); b=root(b);
		if(a!=b){
			p[a]={a, p[a].size+p[b].size};
			p[b]={a, -1};
		}
		return p[a].size;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numPeople; std::cin>>numPeople;
	int numCondition; std::cin>>numCondition;
	DSU dsu(numPeople);

	int dummy{};
	std::set<std::pair<int, int>> sets;

	auto iter=sets.end();
	int sumAfterIter=0;
	int countAfterIter=0;

	auto const addElement=[&](int x){
		auto const [newIter, inserted]=sets.insert({x, ++dummy});
		assert(inserted);
		if(iter!=sets.end() and *newIter >= *iter){
			sumAfterIter+=newIter->first;
			countAfterIter++;
		}
	};
	auto const removeElement=[&](int x){
		auto const a=sets.lower_bound({x, -1});
		assert(a->first==x);

		if(a==iter){
			sumAfterIter-=x;
			countAfterIter--;
			iter++;
		}else if(iter!=sets.end() and *a >= *iter){
			sumAfterIter-=x;
			countAfterIter--;
		}
		sets.erase(a);
	};
	auto const adjustIter=[&](int size){
		while(countAfterIter<size){
			--iter;
			sumAfterIter+=iter->first;
			countAfterIter++;
		}
		while(countAfterIter>size){
			sumAfterIter-=iter->first;
			countAfterIter--;
			++iter;
		}
	};

	for(int _=0; _<numPeople; ++_)
		addElement(1);


	int extra {};

	for(int i=0; i<numCondition; ++i){
		int x; std::cin>>x; --x;
		int y; std::cin>>y; --y;
		x=dsu.root(x); y=dsu.root(y);

		if(x==y){
			extra++;
		}else{
			removeElement(dsu.p[x].size);
			removeElement(dsu.p[y].size);
			addElement(dsu.join(x, y));
			// (what a mess)
		}

		adjustIter(extra+1);

		std::cout<<sumAfterIter-1<<'\n';
	}
}