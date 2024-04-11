#include <iostream>
#include <vector>

int ncity;
typedef std::vector<int> vi;
std::vector<vi> adjlist;
vi parent, stsize;
std::vector<char> rank;

void remove(vi &vec, int value) {
    auto it = vec.begin();
    while (it != vec.end() && *it != value) ++it;
    if (it == vec.end()) std::cout << "ERROR!\n";
    std::swap(*it, *--vec.end());
    vec.pop_back();
}

/// return subtree size
int buildtree(int node) {
    stsize[node] = 1;
    for (int child : adjlist[node]) {
        if (parent[node] != child) {
            parent[child] = node;
            stsize[node] += buildtree(child);
        }
    }
    if (parent[node] != -1) remove(adjlist[node], parent[node]);
    return stsize[node];
}

void calculate(int node, char minrank) {
    /*
    std::cout << "calculate(" << node << ", " << minrank << "):\n";
    for (int i = 0; i < ncity; ++i) {
        std::cout << i << "(" << parent[i] << ") -> ";
        for (int j : adjlist[i]) std::cout << j << " ";
        std::cout << "\n";
    }
    */
    if (stsize[node] == 1) {
        rank[node] = minrank;
        return;
    }
    do {
        vi::iterator itmax = adjlist[node].begin(); // it is not a leaf
        for (auto it = ++adjlist[node].begin(); it != adjlist[node].end(); ++it) {
            if (stsize[*it] > stsize[*itmax]) itmax = it;
        }
        //std::cout << "node=" << node << ", max=" << *itmax << "\n";
        if (stsize[*itmax] * 2 > stsize[node]) {
            // must be strict. Rotate it upward
            //std::cout << "strict\n";
            if (parent[node] != -1) {
                for (int &n1 : adjlist[parent[node]]) {
                    if (n1 == node) {
                        n1 = *itmax;
                        break; // for
                    }
                }
            }
            parent[*itmax] = parent[node];
            parent[node] = *itmax;
            adjlist[*itmax].push_back(node);
            stsize[node] -= stsize[*itmax];
            stsize[*itmax] += stsize[node];

            /*
            std::cout << "stsize[" << node << "]=" << stsize[node] << "\n";
            std::cout << "stsize[" << *itmax << "]=" << stsize[*itmax] << "\n";

            for (int i = 0; i < ncity; ++i) {
                std::cout << i << "(" << parent[i] << ") -> ";
                for (int j : adjlist[i]) std::cout << j << " ";
                std::cout << "\n";
            }
            */

            int tmp = *itmax;
            remove(adjlist[node], *itmax);
            node = tmp;
        } else break;
    } while (true);
    rank[node] = minrank;

    for (int child : adjlist[node]) calculate(child, minrank+1);
}

int main() {
    std::cin >> ncity;
    adjlist.resize(ncity); parent.resize(ncity);
    stsize.resize(ncity); rank.resize(ncity);
    for (int i = 1; i < ncity; ++i) {
        int city1, city2;
        std::cin >> city1 >> city2;
        --city1; --city2;
        adjlist[city1].push_back(city2);
        adjlist[city2].push_back(city1);
    }
    parent[0] = -1;
    buildtree(0);

    calculate(0, 'A');
    for (int i = 0; i < ncity; ++i)
        std::cout << rank[i] << " ";
    std::cout << "\n";
}