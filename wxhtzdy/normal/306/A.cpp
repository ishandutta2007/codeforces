#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;

    for (int i = 0; i < M; i++)
        cout << N / M + (i < N % M ? 1 : 0) << " ";

    return 0;
}