// http://codeforces.com/contest/383/problem/C

#include <iostream>
#include <vector>


int nquery, nvertex;
std::vector<int> val, parent, dfspath, start, finish, height, sign;
std::vector<std::vector<int> > adjlist;

struct FT {
    std::vector<int> dat;
    FT(int x) : dat (x+1, 0) {}
    int get(int i) {
        ++i;
        int result = 0;
        while (i > 0) {
            result += dat[i];
            i -= i&-i;
        }
        return result;
    }
    void update(int i, int val) {
        ++i;
        while (i < dat.size()) { // Double note: dat.size() = N+1, so while i <= N but i < dat.size().
            dat[i] += val;
            i += i&-i;
        }
    }
};

void buildtree(int node) {
    start[node] = dfspath.size();
    dfspath.push_back(node);
    for (int child : adjlist[node]) {
        if (child != parent[node]) {
            parent[child] = node;
            height[child] = height[node]+1;
            buildtree(child);
        }
    }
    finish[node] = dfspath.size();
} // node : [start[node], finish[node])

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> nvertex >> nquery;
    val.assign(nvertex+1, 0); // val[0] = 0 : dummy value
    for (int i = 1; i <= nvertex; ++i) {
        std::cin >> val[i];
    }
    adjlist.assign(nvertex+1, std::vector<int>());
    for (int i = 1; i < nvertex; ++i) { // nvertex-1 edges
        int v1, v2;
        std::cin >> v1 >> v2;
        adjlist[v1].push_back(v2);
        adjlist[v2].push_back(v1);
    }

    parent.assign(nvertex+1, 0); parent[1] = -1;
    start .assign(nvertex+1, 0);
    finish.assign(nvertex+1, 0);
    height.assign(nvertex+1, 0); height[1] = 0;
    buildtree(1);

    // for (int i : dfspath) std::cout << i << " "; std::cout << " <-- dfspath \n";

    std::vector<std::vector<int>>().swap(adjlist);
    std::vector<int>().swap(parent);

    FT result (nvertex);

    std::vector<int> nval (nvertex+1, 0); // nval[0] = 0

    sign.assign(nvertex+1, 0); // sign[0] = 0 : dummy value
    for (int i = 1; i <= nvertex; ++i) {
        sign[i] = height[i]&1 ? 1 : -1;
        nval[start[i]] = sign[i] * val[i];
    }

    std::vector<int>().swap(height);
    result.update(0, nval[0]);
    for (int i = 1; i < nvertex; ++i)
        result.update(i, nval[i] - nval[i-1]);

    // for (int i = 0; i < nvertex; ++i) std::cout << result.get(i) << " "; std::cout << " <- result \n";


    std::vector<int>().swap(nval);

    // each vertex appear exactly once in dfs path.

    // for (int i = 0; i < nvertex; ++i) std::cout << result.get(i) << " "; std::cout << " <-- \n";

    for (int q = 0; q < nquery; ++q) {
        int type, x, v;
        std::cin >> type;
        if (type == 1) {
            std::cin >> x >> v;
            result.update(start [x], v * sign[x]);
            result.update(finish[x],-v * sign[x]);
        } else {
            std::cin >> x;
            std::cout << result.get(start[x]) * sign[x] << "\n";
        }
        // for (int i = 0; i < nvertex; ++i) std::cout << result.get(i) << " "; std::cout << " <-- \n";
    }
}

/*

5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
2 2
2 4


*/