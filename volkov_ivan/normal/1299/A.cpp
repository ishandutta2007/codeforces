#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;
int a[N];
int cnt[40];
int pos[40];

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j <= 30; j++) {
            if (a[i] & (1 << j)) {
                cnt[j]++;
                pos[j] = i;
            }
        }
    }
    for (int j = 30; j >= 0; j--) {
        if (cnt[j] == 1) {
            swap(a[0], a[pos[j]]);
            break;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}