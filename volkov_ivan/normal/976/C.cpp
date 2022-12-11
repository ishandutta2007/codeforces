#include <iostream>
#include <algorithm>

using namespace std;

struct segm{
    int l, r, num;
    segm() {}
    segm(int l, int r, int num) {
        this->l = l;
        this->r = r;
        this->num = num;
    }
};

bool cmp(segm a, segm b) {
    if (a.l == b.l) {
        return (a.r > b.r);
    }
    return (a.l < b.l);
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    segm all[n];
    for (int i = 0; i < n; i++) {
        cin >> all[i].l >> all[i].r;
        all[i].num = i + 1;
    }
    sort(all, all + n, cmp);
    int last = -1, num = -1;
    for (int i = 0; i < n; i++) {
        if (all[i].r <= last) {
            cout << all[i].num << ' ' << num << endl;
            return 0;
        }
        if (all[i].r > last) {
            last = all[i].r;
            num = all[i].num;
        }
    }
    cout << -1 << ' ' << -1 << endl;
    return 0;
}