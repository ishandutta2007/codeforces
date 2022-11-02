#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }

    int cnt[3];
    fill(cnt, cnt + 3, -N / 3);
    for (int i = 0; i < N; ++i) {
        ++cnt[a[i]];
    }

    for (int i = 0; i < N && cnt[0] < 0; ++i) {
        if (cnt[a[i]] > 0) {
            --cnt[a[i]];
            a[i] = 0;
            ++cnt[0];
        }
    }

    for (int i = N - 1; i >= 0 && cnt[2] < 0; --i) {
        if (cnt[a[i]] > 0) {
            --cnt[a[i]];
            a[i] = 2;
            ++cnt[2];
        }
    }

    for (int i = 0; i < N && cnt[2] > 0; ++i) {
        if (a[i] == 2) {
            --cnt[2];
            a[i] = 1;
            ++cnt[1];
        }
    }

    for (int i = N - 1; i >= 0 && cnt[0] > 0; --i) {
        if (a[i] == 0) {
            --cnt[0];
            a[i] = 1;
            ++cnt[1];
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << a[i];
    }
    cout << endl;
    return 0;
}