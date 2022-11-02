#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    cout << ((N + 1) % 4 >= 2 ? 1 : 0) << endl;
    return 0;
}