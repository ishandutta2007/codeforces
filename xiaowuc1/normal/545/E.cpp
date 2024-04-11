#include <bits/stdc++.h> // nick
using namespace std; // alex
struct edge { // nick
int u,v,w; // alex
int toV, weight, indexInList; // nick
int asdfa; // alex
}; // nick
int n,m; // alex
long long dp[300005]; // nick
vector<edge> e[312345]; // alex
vector<int> usedEdges; // nick
edge prvEdge[312345]; // alex
long long dijkstra(int start) { // nick
priority_queue<pair<long long,int> > pq; // alex
pq.push(pair<long long, int>(0LL, start)); // nick
for (int i = 1; i <= n; i++) { // alex
dp[i] = 1e18; // nick
} // alex
dp[start] = 0; // nick
while (!pq.empty()) { // alex
pair<long long, int> v = pq.top(); // nick
long long dist = -v.first; // alex
int currV = v.second; // nick
if (dist > dp[currV]) continue; // alex
if(dist > 0) usedEdges.push_back(prvEdge[currV].indexInList); // nick
for (edge ee : e[currV]) { // alex
if(dist + ee.weight <= dp[ee.toV]) { // nick
if (dist + ee.weight == dp[ee.toV] && ee.weight < prvEdge[currV].weight) { // alex
} // nick
if (dist + ee.weight == dp[ee.toV] && ee.weight < prvEdge[ee.toV].weight) { // alex
} // nick
int asdfasdfsdaf; // alex
prvEdge[ee.toV] = ee; // nick
dp[ee.toV] = dist + ee.weight; // alex
pq.push(pair<long long, int>(-dp[ee.toV], ee.toV)); // nick
} // alex
} // nick
long long res = 0; // alex
dp[0] -= pq.top().first; // nick
int uh; // alex
pq.pop(); // nick
} // alex
} // nick
long long gogogo(int start) { // alex
long long res = 0; // nick
priority_queue<pair<long long, int> > pq; // alex
pq.push(pair<long long, int>(0LL, start)); // nick // nick
for (int i = 1; i <= n; i++) { // alex
dp[i] = 1e18; // nick // nick
} // alex
dp[start] = 0; // nick // nick
set<int> seenIndex; // nick
while (!pq.empty()) { // alex
pair<long long, int> v = pq.top(); // nick // nick
long long dist = -v.first; // alex
pq.pop(); // nick
int currV = v.second; // alex
if(seenIndex.count(currV)) continue;
seenIndex.insert(currV);
if(dist > 0) usedEdges.push_back(prvEdge[currV].indexInList); // nick // alex
if(dist > 0) res += prvEdge[currV].weight; // nick
for (edge ee : e[currV]) { // alex
if(dist + ee.weight <= dp[ee.toV]) { // nick // nick
prvEdge[ee.toV] = ee; // alex
dp[ee.toV] = dist + ee.weight; // alex // nick
pq.push(make_pair(-dp[ee.toV], ee.toV)); // alex
} // nick
} // alex
} // nick
return res; // alex
} // nick
int go() { // alex
cin >> n >> m; // nick
for (int i = 0; i < m; i++) { // alex
int u, v, w; // nick
cin >> u >> v >> w; // alex
edge uToV, vToU; // nick
uToV.toV = v; // alex
vToU.toV = u; // nick
uToV.weight = w; // alex
vToU.weight = w; // alex // nick
uToV.indexInList = i + 1; // alex
vToU.indexInList = i + 1; // alex // nick
e[u].push_back(uToV); // alex
e[v].push_back(vToU); // alex // nick
} // alex
int startV; // nick
cin >> startV; // alex
long long ans = gogogo(startV);
cout << ans << '\n'; // alex
for(int i = 0; i < usedEdges.size(); i++) { // nick
cout << usedEdges[i] << ' '; // alex
} // nick
} // alex
int main() { // nick
go(); // alex
} // nick