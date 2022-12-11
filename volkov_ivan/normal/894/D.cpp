#include <iostream>
#include <vector>

using namespace std;

struct node{
    vector <long long> dist;
    vector <long long> pref;
    node() {};
};

const int MAX_N = 1 << 20;
node t[MAX_N];

void my_merge(int num, vector <long long> a, vector <long long> b) {
    t[num].dist.push_back(0);
    int n = a.size(), m = b.size(), i = 0, j = 0;
    while (i != n && j != m) {
        if (a[i] < b[j])  {
            t[num].dist.push_back(a[i]);
            i++;
        } else {
            t[num].dist.push_back(b[j]);
            j++;
        }
    }
    while (i < n) {
        t[num].dist.push_back(a[i]);
        i++;
    }
    while (j < m) {
        t[num].dist.push_back(b[j]);
        j++;
    }
}

int bs(int num, int x) {
    int l = -1;
    int r = t[num].dist.size(), m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (t[num].dist[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int dists[MAX_N + 1];
int n;

void build(int num) {
    if (2 * num > n) {
        t[num].dist.push_back(0);
        t[num].pref.push_back(0);
        t[num].pref.push_back(0);
        return;
    }
    vector <long long> d1, d2;
    build(2 * num);
    d1 = t[2 * num].dist;
    if (2 * num + 1 <= n) {
        build(2 * num + 1);
        d2 = t[2 * num + 1].dist;
    }
    for (int i = 0; i < d1.size(); i++) {
        d1[i] += dists[2 * num];
    }
    for (int i = 0; i < d2.size(); i++) {
        d2[i] += dists[2 * num + 1];
    }
    my_merge(num, d1, d2);
    t[num].pref.push_back(0);
    for (int i = 0; i < t[num].dist.size(); i++) {
        t[num].pref.push_back(t[num].pref.back() + t[num].dist[i]);
    }
    return;
}

long long find(int num, int h) {
    long long ans = 0;
    long long x = bs(num, h);
    ans += (x + 1) * h - t[num].pref[x + 1];
    int num2, old_num;
    while (num != 1) {
        old_num = num;
        h -= dists[num];
        num /= 2;
        if (h > 0) ans += h;
        if (2 * num == old_num) {
            if (2 * num + 1 <= n) {
                num2 = 2 * num + 1;
                h -= dists[num2];
                x = bs(num2, h);
                ans += (x + 1) * h - t[num2].pref[x + 1];
                h += dists[num2];
            }
        } else {
            num2 = 2 * num;
            h -= dists[num2];
            x = bs(num2, h);
            ans += (x + 1) * h - t[num2].pref[x + 1];
            h += dists[num2];
        }
    }
    return ans;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) {
        scanf("%d\n", &dists[i]);
    }
    build(1);
    int num, h;
    for (int i = 0; i < m; i++) {
        scanf("%d %d\n", &num, &h);
        printf("%I64d\n", find(num, h));
    }
    return 0;
}