#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

constexpr bool LOCAL = false;
int ary[1024];
int expect;
int qc = 0;
int64_t n;


int query(int l, int r, int k) {
    ++qc;
    if (LOCAL) {
        set<int> s;
        for (int i = l; i <= r; ++i) {
            s.insert(ary[i] / k);
        }
        cerr << "l:" << l << " r:" << r << " k:" << k << " s:" << s.size() << endl;
        return s.size();
    } else {
        cout << "? " << (l + 1) << " " << (r + 1) << " " << k << endl;
        cout.flush();
        int a;
        cin >> a;
        return a;
    }
}

void answer(int i) {
    if (LOCAL) {
        cerr << "qc:" << qc << endl;
        if (i == expect) {
            cerr << "success" << endl;
        } else {
            cerr << "fail " << i << " " << expect << endl;
        }
    } else {
        cout << "! " << (i + 1) << endl;
        cout.flush();
    }
}

int main() {
    cin >> n;
    if (LOCAL) {
        for (int i = 0; i < n; ++i) {
            ary[i] = i + 1;
        }
        random_shuffle(ary, ary + n);
        expect = find(ary, ary + n, 1) - ary;
    }

    int max_i = -1;
    int left = 0;
    int right = n;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        int c0 = query(0, mid - 1, 2);
        int c1 = query(mid, n - 1, 2);
        int d0  = mid - c0;
        int d1  = (n - mid) - c1;
        int s0 = c0 - d0;
        int s1 = c1 - d1;
        if (s0 == s1) {
            if (max_i == -1) {
                if (mid > 1) {
                    int c = query(0, mid - 1, n);
                    max_i = c == 1 ? n : 0;
                } else {
                    int c = query(mid, n, n);
                    max_i = c == 1 ? 0 : n;
                }
            }
            if (max_i < mid) {
                s0--;
            } else {
                s1--;
            }
        }
        if (s0 < s1) {
            left = mid;
        } else {
            right = mid;
        }
    }
    answer(left);
}