#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M=1e9+7;

int tLines;
bool *visited, *nodeUniX, *nodeUniY, hasCycle;
vector<int> *graph;

void dfs(int node, int prev) {
	visited[node]=true;
	if(nodeUniX[node])
		++tLines;
	if(nodeUniY[node])
		++tLines;
	for(int neighbor : graph[node]) {
		if(neighbor==prev)
			continue;
		if(visited[neighbor])
			hasCycle=true;
		else
			dfs(neighbor, node);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	visited = new bool[n](), nodeUniX = new bool[n](), nodeUniY = new bool[n]();
	graph = new vector<int>[n];
	unordered_map<int, int> nodeWithX, nodeWithY;
	for(int i=0; i<n; ++i) {
		int x, y;
		cin >> x >> y;
		auto search=nodeWithX.find(x);
		if(search==nodeWithX.end()) {
			nodeWithX[x]=i;
			nodeUniX[i]=true;
		} else {
			graph[i].push_back(search->second);
			graph[search->second].push_back(i);
		}
		search=nodeWithY.find(y);
		if(search==nodeWithY.end()) {
			nodeWithY[y]=i;
			nodeUniY[i]=true;
		} else {
			graph[i].push_back(search->second);
			graph[search->second].push_back(i);
		}
	}
	ll *pow2 = new ll[n+2], t=1;
	pow2[0]=1;
	for(int i=1; i<n+2; ++i)
		pow2[i]=pow2[i-1]*2%M;
	for(int i=0; i<n; ++i) {
		if(!visited[i]) {
			dfs(i, -1);
			t=(t*(pow2[tLines]-!hasCycle))%M;
			tLines=0;
			hasCycle=false;
		}
	}
	cout << t;
}