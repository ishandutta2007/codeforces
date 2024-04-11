#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    sort(S.begin(), S.end());
    cout << S << endl;
    return 0;
}