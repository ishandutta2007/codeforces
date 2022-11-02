#include <iostream>

using namespace std;

int N, a[100010];
bool visited[100010], result[100010];

bool movable(int i, int j) {
    if (j < 0 || N <= j) return false;
    return a[j] > a[i];
}

bool sim(int i) {
    if (visited[i]) return result[i];
    visited[i] = true;
    result[i] = false;
    for (int j = 1; i + j * a[i] < N; ++j) {
        int to = i + j * a[i];
        if (movable(i, to) && !sim(to)) result[i] = true;
    }

    for (int j = 1; i - j * a[i] >= 0; ++j) {
        int to = i - j * a[i];
        if (movable(i, to) && !sim(to)) result[i] = true;
    }
    return result[i];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) {
        cout << (sim(i) ? 'A' : 'B');
    }
    cout << endl;
    return 0;
}