#include <iostream>
 
 using namespace std;

const int N = 14;
long long a[N], b[N];

long long try_move(int pos) {
    if (a[pos] == 0) return 0;
    for (int i = 0; i < N; i++) {
        b[i] = a[i];
    }
    long long cnt = b[pos] / 28, last = b[pos] % 28;
    b[pos] = 0;
    for (int i = 0; i < N; i++) b[i] += 2 * cnt;
    int now = (pos + 1) % N;
    for (int i = 0; i < last; i++) {
        b[now]++;
        now = (now + 1) % N;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) if (b[i] % 2 == 0) ans += b[i];
    return ans;
}
 
 int main() {
     for (int i = 0; i < N; i++) cin >> a[i];
     long long ans = 0;
     for (int i = 0; i < N; i++) ans = max(ans, try_move(i));
     cout << ans << endl;
     return 0;
 }