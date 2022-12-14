// 1512

// http://codeforces.com/problemset/problem/398/D

#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>

#include<iostream>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<vector>
#include<set>

#ifdef _GLIBCXX_DEBUG
#define cin cin_
#include<sstream>
namespace std{std::stringstream cin(R"(
5 2 9
1
4
1 3
3 4
C 3
A 2 5
O 1
D 1 3
A 1 2
A 4 2
C 2
F 4
C 2

)");}
#endif

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);

	// nNode == nUser
	int nNode,nQuery;std::vector<char> online;
	std::vector<std::set<int>> adjl;

	std::vector<int> maxDeg; // used to estimate the big nodes

	{
		int nPair;
		std::cin>>nNode>>nPair>>nQuery;
		adjl.resize(nNode);
		online.resize(nNode);maxDeg.resize(nNode);
		{ // read online users.
			int nOnline;std::cin>>nOnline;
			while(nOnline-->0){int user;std::cin>>user;online[--user]=true;}
		}
		// read initial friend pairs
		while(nPair-->0){
			int u,v;std::cin>>u>>v;--u;--v;
			assert(u>=0&&v>=0);
			adjl[u].insert(v);
			adjl[v].insert(u);
			++maxDeg[u];++maxDeg[v];
		}
	}


	struct query{char type;int u,v;};
	std::vector<query> queries(nQuery);
	for(query& q:queries){
		std::cin>>q.type>>q.u;--q.u;
		if(q.type=='A'||q.type=='D'){std::cin>>q.v;--q.v;}
		if(q.type=='A'){
			++maxDeg[q.u];++maxDeg[q.v];
		} // just an estimation...
	}

	int const bigThreshold=std::max(1,(int)std::round(std::sqrt(
		std::accumulate(maxDeg.begin(),maxDeg.end(),0)
	)/2));
	auto const isBigNode_=[&](int node){
		assert((unsigned)node<(unsigned)nNode);
		return maxDeg[node]>=bigThreshold;
	};

	std::vector<std::set<int>> bigAdjl(nNode);
	for(int node=0;node<nNode;++node)for(int e:adjl[node]){
		if(isBigNode_(e))
			bigAdjl[node].insert(bigAdjl[node].end(),e);
	}

	std::vector<int> cntOnline(nNode,-1); // -1 for small nodes
	for(int node=nNode;node-->0;)if(isBigNode_(node)){
		int cntOnlineNode=0;
		for(int n:adjl[node])
			if(online[n])++cntOnlineNode;
		cntOnline[node]=cntOnlineNode;
	}

	decltype(maxDeg){}.swap(maxDeg); // clear its memory // cannot do this
	auto const isBigNode=[&](int node){
		return cntOnline[node]>=0;
	};

	for(query const q:queries){
		int const u=q.u,v=q.v;
		switch(q.type){
		case 'O':{
			online[u]=true;
			for(int n:bigAdjl[q.u]){
				assert(cntOnline[n]>=0);
				++cntOnline[n];
			}
			break;
		}
		case 'F':{
			online[u]=false;
			for(int n:bigAdjl[q.u]){
				assert(cntOnline[n]>0);
				--cntOnline[n];
			}
			break;
		}
		case 'A':{
			adjl[u].insert(v);
			adjl[v].insert(u);
			if(isBigNode(v)){
				bigAdjl[u].insert(v);
				assert(cntOnline[v]>=0);
				cntOnline[v]+=online[u];
			}
			if(isBigNode(u)){
				bigAdjl[v].insert(u);
				assert(cntOnline[u]>=0);
				cntOnline[u]+=online[v];
			}
			break;
		}
		case 'D':{
			adjl[u].erase(v);
			adjl[v].erase(u);
			if(isBigNode(v)){
				bigAdjl[u].erase(v);
				cntOnline[v]-=online[u];
				assert(cntOnline[v]>=0);
			}
			if(isBigNode(u)){
				bigAdjl[v].erase(u);
				cntOnline[u]-=online[v];
				assert(cntOnline[u]>=0);
			}
			break;
		}
		case 'C':
			if(isBigNode(u)){
				std::cout<<cntOnline[u]<<'\n';
			}else{
				int ans=0;
				for(int n:adjl[u])
					ans+=online[n];
				std::cout<<ans<<'\n';
			}
			break;
		} // end switch q.type
	} // next query
}