#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
        if (a >= 0) {
            a = -a - 1;
        }
    }

    if (N % 2) {
        auto itr = min_element(A.begin(), A.end());
        *itr = -*itr - 1;
    }

    for (auto a : A) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}