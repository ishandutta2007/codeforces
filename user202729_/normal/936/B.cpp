#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>

#include<iostream>
#include<vector>

#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
3 2
1 3
1 1
0
2
)");}
#endif // Sublime

std::vector<std::vector<int>> adjl,radjl;
std::vector<char> in_stack,visited;
bool find_circuit(int node){
	visited[node]=true;
	in_stack[node]=true;
	for(int adj:adjl[node]){
		if(visited[adj]){
			if(in_stack[adj])return true; // yayyy
			continue; // just cross edge?
		}
		if(find_circuit(adj))return true;;
	}
	in_stack[node]=false;
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);

	int n_node,n_edge;std::cin>>n_node>>n_edge;
	adjl.resize(n_node);radjl.resize(n_node);
	for(int node=0;node<n_node;++node){
		int x;std::cin>>x;adjl[node].resize(x);
		for(int& a:adjl[node]){
			std::cin>>a;--a;
			radjl[a].push_back(node);
		}
	}
	int start;std::cin>>start;--start;

	std::vector<int> nst_win(n_node,-1),nst_lose(n_node,-1);
	// in that many steps

	std::vector<int> lose_pos;

	for(int i=n_node;i-->0;)
		if(adjl[i].size()==0){
			lose_pos.push_back(i);
			nst_lose[i]=0;
		}

	while(!lose_pos.empty()){
		int node=lose_pos.back();lose_pos.pop_back();
		assert(nst_lose[node]>=0);

		for(int adj:radjl[node]){
			if(nst_win[adj]>=0)continue; // already filled
			nst_win[adj]=1+nst_lose[node];
			for(int ad1:radjl[adj]){
				if(nst_lose[ad1]<0){
					nst_lose[ad1]=1+nst_win[adj];
					lose_pos.push_back(ad1);
				}
			}
		}
	}

	if(nst_win[start]<0){
		if(nst_lose[start]<0||(
			in_stack.resize(n_node),
			visited.resize(n_node),
			find_circuit(start)
		)){
			std::cout<<"Draw\n";
			return 0;
		}
		std::cout<<"Lose\n";
		return 0;
	}

	std::cout<<"Win\n";
	int p=start;
	while(true){
		std::cout<<1+p<<' ';
		for(int p1:adjl[p])
			if(nst_lose[p1]>=0&&nst_lose[p1]<nst_win[p]){
				p=p1;
				break;
			}
		std::cout<<1+p<<' ';
		if(adjl[p].empty())
			break;
		for(int p1:adjl[p])
			if(nst_win[p1]>=0&&nst_win[p1]<nst_lose[p]){
				p=p1;
				break;
			}
	}
	std::cout<<'\n';
}