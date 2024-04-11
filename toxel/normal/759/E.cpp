#include <bits/stdc++.h>

const int moder = (int) 1e9 + 7;
const int N = 300010;
using ll = long long;

int a[N], b[N];
char s[N];

struct BigInt {
    const static int N = 1500;
    const static int DIGIT = 9;
    const static int BASE = (int) 1e9;

    int a[N];
    int len;

    void reformat() {
        for (; len && !a[len - 1]; --len);
    }

    explicit BigInt(char *s) : a(), len(0) {
        int n = strlen(s);
        std::reverse(s, s + n);
        for (int i = 0; i < n; i += DIGIT) {
            for (int j = i + 8; j >= i; --j) {
                a[len] = a[len] * 10 + (isdigit(s[j]) ? s[j] - '0' : 0);
            }
            ++len;
        }
        reformat();
    }

    int mod(const int &t) {
        int remain = 0;
        for (int i = len - 1; i >= 0; --i) {
            ll value = 1ll * remain * BASE + a[i];
            remain = value % t;
            a[i] = value / t;
        }
        reformat();
        return remain;
    }
};

int take(int pos, std::vector <int> &a){
    return pos < 0 ? 0 : pos >= (int) a.size() ? a.back() : a[pos];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    scanf("%s", s);
    BigInt m(s);
    std::vector<int> pre(1, 1);
    for (int i = 0, j = 1; i < n; i = j++) {
        while (j < n && a[j - 1] == 1) {
            ++j;
        }
        std::vector<int> bb;
        std::copy(b + i, b + j, std::back_inserter(bb));
        if (i){
            std::vector<int> npre;
            int remain = m.mod(a[i - 1]);
            for (int k = remain; k < (int) pre.size(); k += a[i - 1]) {
                npre.push_back(pre[k]);
            }
            pre = npre;
            if (pre.empty()){
                puts("0");
                return 0;
            }
        }
        std::vector<int> pref;
        for (auto u : bb) {
            pref.clear();
            for (auto v : pre){
                int value = (pref.empty() ? 0 : pref.back()) + v;
                value -= value >= moder ? moder : 0;
                pref.push_back(value);
            }
            int nsum = pre.size() + u;
            pre.resize(nsum);
            for (int k = 0; k < nsum; ++k) {
                pre[k] = take(k, pref) - take(k - u - 1, pref);
                pre[k] += pre[k] < 0 ? moder : 0;
            }
        }
    }
    if (m.len >= 2 || m.a[0] >= (int) pre.size()){
        puts("0");
    }
    else{
        printf("%d\n", pre[m.a[0]]);
    }
    return 0;
}