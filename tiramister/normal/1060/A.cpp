#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    cout << min(N / 11, (int)count(S.begin(), S.end(), '8')) << endl;
    return 0;
}