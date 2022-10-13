#include <bits/stdc++.h>
using namespace std;

#define PI 3.14152965358979323846264338

struct pt {
    int x, y;

};

long long ccw(pt x, pt y) {
    return x.x * 1LL * y.y - y.x * 1LL * x.y;
}

bool cmp(pt &x, pt &y) {
    bool a = x.y >= 0, b = y.y >= 0;
    if(a != b) {
        if(a) return true;
        return false;
    }
    return ccw(x, y) < 0;
}

long long choose3(int x) {
    return x * 1LL * (x - 1) * 1LL * (x - 2) / 6;
}

int main() {
    int n; cin >> n;
    vector<pt> in(n);
    for(int i = 0; i < n; i++) {
        cin >> in[i].x >> in[i].y;
    }

    long long ans = 0LL;
    for(int st = 0; st < n; st++) {
        vector<pt> tmp;
        for(int j = 0; j < n; j++) {
            if(j != st)
                tmp.push_back({in[j].x - in[st].x, in[j].y - in[st].y});
        }
        sort(tmp.begin(), tmp.end(), cmp);
        int k = 0;
        for(int j = 0; j < n - 1; j++) {
            if(j == k) ++k, k %= (n - 1);
            while(ccw(tmp[j], tmp[k]) < 0) {
                ++k;
                if(k == (n - 1)) k = 0;
            } 
            int num;
            if(k > j) num = k - j - 1;
            else num = n - 2 + k - j;
            ans += choose3(num);
        }
        //cout << ans << "\n";
    }
    ans = - ans;
    ans += n * 1LL * (n - 1) * 1LL * (n - 2) / 6 * 1LL * (n - 3) / 4 * 1LL * (n - 4);
    cout << ans;
}