// I think this problem is similar to some problem I've done
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

std::vector<std::vector<int>> ad;

std::vector<std::vector<int>> cps; // root[ i = cps[rooti][j]] == rooti
std::vector<int> root;
std::unordered_set<int> roots;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;
	ad.resize(n);
	for(int z=m;z--;){
		int u,v;std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
	for(int i=n;i--;)
		std::sort(begin(ad[i]),end(ad[i]));

	root.resize(n);
	cps.resize(n);
	roots.reserve(n);
	for(int i=n;i--;){
		root[i]=i;
		cps[i].assign(1,i);
		roots.insert(i);
	}

	std::vector<int> todojoin;
	for(int i=n;i--;){
		todojoin.clear();

		auto ri=root[i];
		for(int rj:roots)if(ri!=rj){
			for(int j:cps[rj])
				if(!std::binary_search(begin(ad[i]),end(ad[i]),j)){
					// join ri and rj
					todojoin.push_back(rj);
					break;
				}else{
					// happens at most m times
				}
		}

		// todojoin is sorted int decrasing order
		for(int rj:todojoin){
			if(cps[ri].size()<cps[rj].size()){
				std::swap(ri,rj);
			}
			roots.erase(rj);
			for(int x:cps[rj]){
				assert(root[x]==rj);
				root[x]=ri;
			}
			cps[ri].insert(end(cps[ri]),begin(cps[rj]),end(cps[rj]));
			cps[rj].clear();
		}
	}

	std::cout<<roots.size()-1<<'\n';
}