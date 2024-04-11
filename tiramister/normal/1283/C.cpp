#include <iostream>
#include <vector>
#include <set>
#include <cassert>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n), free;
    std::set<int> ungiven;
    for (int i = 0; i < n; ++i) ungiven.insert(i);

    for (int i = 0; i < n; ++i) {
        auto& x = xs[i];
        std::cin >> x;
        --x;
        if (x < 0) {
            free.push_back(i);
        } else {
            ungiven.erase(x);
        }
    }

    for (auto i : free) {
        int to = *ungiven.begin();
        if (to == i && ungiven.size() > 1) {
            to = *(++ungiven.begin());
        }
        xs[i] = to;
        ungiven.erase(to);
    }

    {
        int i = free.back();
        if (xs[i] == i) {
            int j = free.front();
            std::swap(xs[i], xs[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        assert(xs[i] != i);
        std::cout << xs[i] + 1 << " ";
    }
    std::cout << std::endl;
    return 0;
}