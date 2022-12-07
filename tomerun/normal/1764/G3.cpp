#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <iostream>
using namespace std;

constexpr bool LOCAL = false;
int ary[1024];
int expect;
int qc = 0;
int64_t n;
map<pair<int, int>, int> qm;


int query(int l, int r, int k) {
    ++qc;
    int ret = 0;
    if (LOCAL) {
        set<int> s;
        for (int i = l; i <= r; ++i) {
            s.insert(ary[i] / k);
        }
        cerr << "l:" << l << " r:" << r << " k:" << k << " s:" << s.size() << endl;
        ret = s.size();
    } else {
        cout << "? " << (l + 1) << " " << (r + 1) << " " << k << endl;
        cout.flush();
        cin >> ret;
    }
    if (k == 2) {
        qm[make_pair(l, r)] = ret;
    }
    return ret;
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
        if (right - left == 2) {
            if (n % 2 == 0 && max_i == -1) {
                if (left == 0) {
                    if (query(right - 1, n - 1, n) == 1) {
                        left++;
                    } else {
                    }
                } else {
                    if (query(0, left, n) == 1) {
                    } else {
                        left++;
                    }
                }
            } else {
                int c0 = left == 0 ? 0 : qm[make_pair(0, left - 1)];
                int c1 = qm[make_pair(0, right - 1)];
                if (c0 + 2 == c1) {
                    if (query(right - 1, n - 1, 2) == qm[make_pair(right, n - 1)]) {

                    } else {
                        left++;
                    }
                } else {
                    if (query(0, left, 2) == c0) {
                        left++;
                    } else {
                    }
                }
            }
            break;
        }
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