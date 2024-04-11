#include <deque>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, q;

bool reversed;
deque<int> thick, psum, ssum;

void debug(deque<int> q) {
    for (int i = 0; i < (int)q.size(); ++i) {
        cout << q[i] << ' ';
    }
    cout << endl;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        thick.push_back(1);
    }
    psum.push_back(0);
    ssum.push_back(0);
    for (int i = 0; i < n; ++i) {
        psum.push_back(i + 1);
        ssum.push_back(i + 1);
    }
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int p;
            scanf("%d", &p);
            if (p * 2 > thick.size()) {
                reversed ^= 1;
                p = thick.size() - p;
            }
            if (reversed) {
                vector<int> stack;
                for (int i = 0; i < p; ++i) {
                    stack.push_back(thick.back());
                    thick.pop_back();
                    psum.pop_back();
                    ssum.pop_front();
                }
                ssum[0] = 0;
                for (int i = 0; i < p; ++i) {
                    thick[thick.size() - 1 - i] += stack.back();
                    stack.pop_back();
                    ssum[i + 1] = ssum[i] + thick[thick.size() - 1 - i];
                }
                for (int i = p - 1; i >= 0; --i) {
                    psum[(int)psum.size() - 1 - i] = psum[(int)psum.size() - 1 - i - 1] + thick[thick.size() - 1 - i];
                }
            } else {
                vector<int> stack;
                for (int i = 0; i < p; ++i) {
                    stack.push_back(thick.front());
                    thick.pop_front();
                    psum.pop_front();
                    ssum.pop_back();
                }
                psum[0] = 0;
                for (int i = 0; i < p; ++i) {
                    thick[i] += stack.back();
                    stack.pop_back();
                    psum[i + 1] = psum[i] + thick[i];
                }
                for (int i = p - 1; i >= 0; --i) {
                    ssum[(int)ssum.size() - 1 - i] = ssum[(int)ssum.size() - 1 - i - 1] + thick[i];
                }
            }
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            if (reversed) {
                printf("%d\n", ssum[r] - ssum[l]);
            } else {
                printf("%d\n", psum[r] - psum[l]);
            }
        }
/*
cout << (reversed ? "REVERSED" : "") << endl;
debug(thick);
debug(psum);
debug(ssum);
*/
    }
    return 0;
}