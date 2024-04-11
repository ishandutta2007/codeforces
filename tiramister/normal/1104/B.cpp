#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int cnt = 0;
    string stack;
    for (char c : S) {
        if (stack.back() == c) {
            ++cnt;
            stack.pop_back();
        } else {
            stack.push_back(c);
        }
    }

    cout << (cnt % 2 > 0 ? "Yes" : "No") << endl;
    return 0;
}