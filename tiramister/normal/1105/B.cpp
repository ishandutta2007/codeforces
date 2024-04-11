#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    int cnt[26];
    fill(cnt, cnt + 26, 0);
    for (int i = 0; i + K - 1 < N;) {
        bool judge = true;
        for (int j = 1; j < K; ++j) {
            if (S[i] == S[i + j]) continue;
            judge = false;
            i = i + j;
            break;
        }
        if (judge) {
            ++cnt[S[i] - 'a'];
            i += K;
        }
    }

    cout << *max_element(cnt, cnt + 26) << endl;
    return 0;
}