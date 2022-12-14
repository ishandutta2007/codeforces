// http://orac.amt.edu.au/cgi-bin/train/problem.pl?problemid=273

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>

typedef std::pair<int,int> ii;

std::vector<std::vector<int>> adjlist;
int ncity;

std::vector<int> prev;

ii dfs(int node, int parent) { // furthest node, length
	int furthestnode = node, length = 0;
	prev[node] = node;
	for (int child : adjlist[node]) {
		if (child != parent) {
			auto tmp = dfs(child, node);
			if (1+tmp.second > length) {
				length = 1+tmp.second;
				furthestnode = tmp.first;
				prev[node] = child;
			}
		}
	}
	return std::make_pair(furthestnode, length);
}

struct iii {
	int node, dist, initial;
	iii(int a, int b, int c) : node (a), dist (b), initial (c) {};
};

ii longestpath(int firstRemain) { // <longestlen, minpossible>
	// this is the hardest part
	prev.resize(ncity);
	int a = dfs(firstRemain, -1).first, b, longestlen, minpossible = 1000000000;
	{
		prev.resize(ncity);
		auto tmp = dfs(a, -1);
		b = tmp.first;
		longestlen = tmp.second;
	}
	std::deque<iii> bfs_queue;
	std::vector<bool> reached (ncity, false);
	std::vector<int> mindist_initial (ncity, -1);
	int x = a;
	bfs_queue.emplace_back(x, 0, x);
	reached[x] = true;
	while (x != prev[x]) {
		x = prev[x];
		bfs_queue.emplace_back(x, 0, x);
		reached[x] = true;
	}
	for (int i = 0; i < bfs_queue.size(); ++i) {
		mindist_initial[bfs_queue[i].initial] = std::min(i, int(bfs_queue.size() - 1 - i));
	}
	while (!bfs_queue.empty()) {
		iii x = bfs_queue.front(); bfs_queue.pop_front();
		if (x.dist == mindist_initial[x.initial]) {
			minpossible = std::min(minpossible, x.node);
		} else {
			for (int child : adjlist[x.node]) {
				if (!reached[child]) {
                    reached[child] = true;
                    bfs_queue.emplace_back(child, x.dist+1, x.initial);
				}
			}
		}
	}
	return std::make_pair(longestlen, minpossible);
}

int main() {
	int natk;
	std::cin >> ncity >> natk;
	adjlist.assign(ncity, std::vector<int>());
	for (int i = 1; i < ncity; ++i) {
		int c1, c2;
		std::cin >> c1 >> c2;
		--c1; --c2;
		adjlist[c1].push_back(c2);
		adjlist[c2].push_back(c1);
	}
	std::queue<int> leaf;
	for (int i = 0; i < ncity; ++i) {
		if (adjlist[i].size() == 1) leaf.push(i);
	}

	std::vector<bool> attack (ncity, false), ignored (ncity, false);
	for (int i = 0; i < natk; ++i) {
		int c;
		std::cin >> c;
		--c;
		attack[c] = true;
	}

	int ncityleft = ncity;

	while (!leaf.empty()) {
		int x = leaf.front(); leaf.pop();
		if (attack[x] || ignored[x]) continue;
		int y = adjlist[x][0];

		ignored[x] = true;
		adjlist[y].erase(
			std::remove(adjlist[y].begin(), adjlist[y].end(), x),
			adjlist[y].end()
		);
		--ncityleft;
		//std::cout << x << " removed\n";

		if (adjlist[y].size() == 1) leaf.push(y);
	}

	int firstRemainCity = 0;
	while (ignored.at(firstRemainCity)) ++firstRemainCity;

	auto x = longestpath(firstRemainCity);
	std::cout << (1+x.second) << "\n" << (ncityleft == 1 ? 0 : 2*(ncityleft-1) - x.first) << "\n";
}