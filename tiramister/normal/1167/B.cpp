#include <iostream>
#include <algorithm>
#include <vector>

int query(int i, int j) {
    std::cout << "? " << i + 1 << " " << j + 1 << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void answer(std::vector<int> ans) {
    std::cout << "!";
    for (auto x : ans) {
        std::cout << " " << x;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int>
        is({0, 1, 3, 4}),
        js({1, 2, 4, 5}),
        prods(4);

    for (int i = 0; i < 4; ++i) {
        prods[i] = query(is[i], js[i]);
    }

    std::vector<int> ans({4, 8, 15, 16, 23, 42});
    do {
        bool judge = true;
        for (int i = 0; i < 4; ++i) {
            if (ans[is[i]] * ans[js[i]] != prods[i]) {
                judge = false;
            }
        }

        if (judge) {
            answer(ans);
            return 0;
        }
    } while (std::next_permutation(ans.begin(), ans.end()));

    std::terminate();
    return 0;
}