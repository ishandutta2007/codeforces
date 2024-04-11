#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> stack;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        a %= 2;
        if (!stack.empty() && stack.back() == a) {
            stack.pop_back();
        } else {
            stack.push_back(a);
        }
    }

    cout << (stack.size() <= 1 ? "YES" : "NO") << endl;
    return 0;
}