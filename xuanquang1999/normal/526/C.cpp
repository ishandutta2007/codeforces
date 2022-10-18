#include <bits/stdc++.h>

using namespace std;

long long C, hr, hb, wr, wb;

long long lcm(long long a, long long b) {
    for(int i = 1; ; ++i) {
        if (i%a == 0 && i%b == 0)
            return i;
    }
}

long long bruteForce(long long C, long long hr, long long hb, long long wr, long long wb) {
    long long ans = 0;
    for(int i = 0; i <= C / wb; ++i) {
        long long j = (C - i * wb) / wr;
        long long sum = hb * i + hr * j;
        ans = max(ans, sum);
    }
    return ans;
}

int main() {
    cin >> C >> hr >> hb >> wr >> wb;

    if (wr > wb) {
        swap(hr, hb);
        swap(wr, wb);
    }

    if (wb >= 10) {
        cout << bruteForce(C, hr, hb, wr, wb) << endl;
    } else {
        long long d = lcm(wr, wb);
        long long ans = 0;
        for(int i = 0; i < wb; ++i) {
            for(int j = 0; j < wr; ++j) {
                long long sumH = hr * i + hb * j;
                long long sumW = wr * i + wb * j;
                if (sumW > C)
                    continue;
                long long sumRemain = (C - sumW) / d * max(d/wr*hr, d/wb*hb);
                ans = max(ans, sumH + sumRemain);
            }
        }
        cout << ans << endl;
    }

    return 0;
}