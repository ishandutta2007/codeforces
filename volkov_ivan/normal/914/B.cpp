#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    map <int, int> num;
    int n;
    cin >> n;
    int now;
    for (int i = 0; i < n; i++) {
        cin >> now;
        num[now]++;
    }
    for (auto elem : num) {
        if (elem.second % 2 == 1) {
            cout << "Conan" << endl;
            return 0;
        }
    }
    cout << "Agasa" << endl;
    return 0;
}