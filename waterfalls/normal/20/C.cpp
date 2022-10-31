#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

int V, E;
vector<vector<pair<int, int> > > adj; // each pair is (adj vertex, weight)

ll dist[100001];

priority_queue<pair<ll, int> > frontier; // each pair is (-distance, vertex)

int main() {
    // input
    scanf("%d%d", &V, &E);
    adj.resize(V + 1);
    while (E--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    // initialize
    for (int i = 1; i <= V; i++) {
        dist[i] = 1e18;
    }
    dist[1] = 0;

    // dijkstra
    frontier.push(make_pair(0, 1));
    while (frontier.size() > 0) {
        int vertex = frontier.top().second;
        ll tovertex = -frontier.top().first;
        frontier.pop();

        if (dist[vertex] != tovertex) {
            // otherwise, we've already processed the vertex. continue
            continue;
        }

        for (auto edge: adj[vertex]) {
            int othervertex = edge.first;
            int weight = edge.second;
            if (tovertex + weight < dist[othervertex]) {
                dist[othervertex] = tovertex + weight;
                frontier.push(make_pair(-dist[othervertex], othervertex));
            }
        }
    }

    if (dist[V] > 1e17) {
        printf("-1\n");
        return 0;
    }

    // reconstruct
    vector<int> path = { V };
    int current_vertex = V;
    while (current_vertex != 1) {
        for (auto edge: adj[current_vertex]) {
            int j = edge.first;
            int weight = edge.second;
            if (dist[j] == dist[current_vertex] - weight) {
                current_vertex = j;
                path.push_back(current_vertex);
                break;
            }
        }
    }
    
    // output
    reverse(path.begin(), path.end());
    for (int i: path) {
        printf("%d ", i);
    }
    printf("\n");
}