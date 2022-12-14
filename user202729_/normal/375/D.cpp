// http://codeforces.com/contest/375/problem/D

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int nquery, nvertex;
std::vector<int> color, parent, dfspath, colpath, start, finish;
std::vector<std::vector<int> > adjlist;

void buildtree(int node) {
    start[node] = dfspath.size();
    dfspath.push_back(node);
    colpath.push_back(color[node]);
    for (int child : adjlist[node]) {
        if (child != parent[node]) {
            parent[child] = node;
            buildtree(child);
        }
    }
    finish[node] = dfspath.size();
} // node : [start[node], finish[node])

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> nvertex >> nquery;
    color.assign(nvertex, 0);
    for (int i = 0; i < nvertex; ++i) {
        std::cin >> color[i];
    }
    adjlist.assign(nvertex, std::vector<int>());

    for (int i = 1; i < nvertex; ++i) { // nvertex-1 edges
        int v1, v2;
        std::cin >> v1 >> v2;
        --v1; --v2;
        adjlist[v1].push_back(v2);
        adjlist[v2].push_back(v1);
    }

    parent.assign(nvertex, 0); parent[0] = -1;
    start .assign(nvertex, 0);
    finish.assign(nvertex, 0);
    buildtree(0); // every vertex id appear in dfspath exactly once
    // -----------------------------

    // for (int i : dfspath) std::cout << i << " "; std::cout << " <-- dfspath \n";

    std::vector<std::vector<int>>().swap(adjlist);
    std::vector<int>().swap(parent);

    struct query_t {
        int start, finish, ncolor, id;
    };
    std::vector<query_t> queries (nquery);
    for (int i = 0; i < nquery; ++i) {
        int vertex, ncol;
        std::cin >> vertex >> ncol;
        --vertex;
        query_t query;
        query.start  = start [vertex];
        query.finish = finish[vertex];
        query.ncolor = ncol;
        query.id = i;
        queries.push_back(query);
    }

    int sqrtn = static_cast<int>(std::sqrt(nvertex));
    std::sort(queries.begin(), queries.end(), [sqrtn](query_t x, query_t y)->bool {
        if (x.start / sqrtn != y.start / sqrtn) return x.start < y.start;
        return x.finish < y.finish;
    });

    std::vector<int> ncol_geq (nvertex+1, 0), n_occur (100001, 0),
    // 100001: maximum value of color + 1
    // the number of color is at most the number of vertex
    result (nquery);
    int start = 0, finish = 0;
    for (query_t query : queries) { // MO's algorithm - Sqrt query decomposition
        while (start > query.start)
            ++ncol_geq[++n_occur[colpath[--start]]];
        while (finish < query.finish)
            ++ncol_geq[++n_occur[colpath[finish++]]];
        while (start < query.start)
            --ncol_geq[n_occur[colpath[start++]]--];
        while (finish > query.finish)
            --ncol_geq[n_occur[colpath[--finish]]--];
        result[query.id] = query.ncolor >= ncol_geq.size() ? 0 : ncol_geq[query.ncolor];
    }

    for (int i : result) std::cout << i << "\n";
}

/*
8 5
1 2 2 3 3 2 3 3
1 2
1 5
2 3
2 4
5 6
5 7
5 8

1 2
1 3
1 4
2 3
5 3


5 9
1 2 2 3 3
1 2
1 3
1 4
1 5

1 2
1 1
1 3
2 1
3 1
4 1
2 2
3 2
4 2

*/