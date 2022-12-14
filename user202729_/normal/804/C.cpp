// I didn't read the editorial or see any failed test cases
// But why did I fail int the virtual contest...
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

std::vector<std::vector<int>> ad,cream;

std::vector<int> colof;
std::vector<char> used;

void dd(int x,int par){
	for(int y:cream[x])
		if(colof[y]>=0){
			assert(not used[colof[y]]);
			used[colof[y]]=true;
		}

	int col=0;
	for(int y:cream[x])
		if(colof[y]<0){
			while(true){
				if(col==(int)used.size()){
					used.push_back(false);
					break;
				}
				if(used[col])
					++col;
				else
					break;
			}
			assert(not used[col]);
			used[col]=true;
			colof[y]=col;
		}

	for(int y:cream[x]) used[colof[y]]=false;

	for(int y:ad[x])if(y!=par){
		dd(y,x);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;
	cream.resize(n);
	for(auto& x:cream){
		int z;std::cin>>z;
		x.resize(z);for(auto& i:x){
			std::cin>>i;
			--i;
		}
	}

	ad.resize(n);
	for(int u,v,z=n-1;z--;){
		std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	used.reserve(m);
	colof.assign(m,-1);
	dd(0,-1);

	std::cout<<std::max(1,(int)used.size())<<'\n';
	for(int x:colof)
		std::cout<<(x<0 ? 1 : 1+x)<<' ';
	std::cout<<'\n';
}