#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<string, int> cnt;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        if (cnt.count(S) == 0) {
            cout << "OK" << endl;
            cnt[S] = 1;
        } else {
            cout << S << cnt[S] << endl;
            ++cnt[S];
        }
    }
    return 0;
}