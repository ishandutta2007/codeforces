#include <iostream>
#include <string>
#include <vector>

int lastremove = 0, result = 0, nbox;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::cin >> nbox;
    std::string command;
    std::vector<int> stack;
    for (int i = 0; i < 2*nbox; ++i) {
        std::cin >> command;
        if (command == "add") {
            int number;
            std::cin >> number;
            stack.push_back(number);
        } else {
            ++lastremove;
            if (!stack.empty()) {
                if ((*stack.rbegin()) == lastremove) { // recently pushed
                    stack.pop_back();
                } else {
                    ++result;
                    stack.clear();
                }
            }
        } // remove command
    }
    std::cout << result << "\n";
}