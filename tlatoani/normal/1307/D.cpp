//
// Created by Danny Mittal on 2/17/20.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    pair<int, int> special[200000];
    for (int j = 0; j < k; j++) {
        int a;
        cin >> a;
        special[j] = make_pair(0, a);
    }
    vector<int> adj[200001];
    for (int j = m; j; j--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int dist1[200001];
    for (int j = 1; j <= n; j++)  {
        dist1[j] = 1151153;
    }
    dist1[1] = 0;
    set<pair<int, int>> pq;
    pq.insert(make_pair(0, 1));
    while (!pq.empty()) {
        pair<int, int> p = *pq.begin();
        pq.erase(p);
        int a = p.second;
        for (int b : adj[a]) {
            if (dist1[a] + 1 < dist1[b]) {
                pq.erase(make_pair(dist1[b], b));
                dist1[b] = dist1[a] + 1;
                pq.insert(make_pair(dist1[b], b));
            }
        }
    }
    int distN[200001];
    for (int j = 1; j <= n; j++)  {
        distN[j] = 1151153;
    }
    distN[n] = 0;
    pq.insert(make_pair(0, n));
    while (!pq.empty()) {
        pair<int, int> p = *pq.begin();
        pq.erase(p);
        int a = p.second;
        for (int b : adj[a]) {
            if (distN[a] + 1 < distN[b]) {
                pq.erase(make_pair(distN[b], b));
                distN[b] = distN[a] + 1;
                pq.insert(make_pair(distN[b], b));
            }
        }
    }
    for (int j = 0; j < k; j++) {
        int a = special[j].second;
        special[j] = make_pair(dist1[a] - distN[a], a);
    }
    sort(special, special + k);
    int answer = -1;
    int largest1 = -1;
    for (int j = 0; j < k; j++) {
        int a = special[j].second;
        if (largest1 != -1) {
            answer = max(answer, distN[a] + 1 + largest1);
        }
        largest1 = max(largest1, dist1[a]);
    }
    if (answer == -1) {
        cout << dist1[n];
    } else {
        cout << min(dist1[n], answer);
    }
}