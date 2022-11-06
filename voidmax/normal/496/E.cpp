#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define player pair <int, pair <int, int> >
#define mp(a, b, c) make_pair(a, make_pair(b, c))
#define can fafs
using namespace std;

int n, m;
int win;
int ans[100001];
player p[100001];
multiset <pair <int, int> > used;
vector <pair <player, int> > can;

int Find(int a) {
    multiset<pair <int, int> >::iterator it = used.lower_bound(make_pair(a, -1));
    if (it == used.end()) {
        return -1;
    }
    pair <int, int> c = (*it);
    if (c.first >= a) {
        if (p[c.second].second.second == 1) {
            used.erase(c);
        }
        else {
            --p[c.second].second.second;
        }
        return c.second;
    }
    return -1;
}

main() {
    cin >> n;
    For(i, 0, n) {
        int a, b;
        scanf("%d %d", &a, &b);
        can.push_back(make_pair(mp(a, true, b), i));
    }
    cin >> m;
    For(i, 0, m) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        p[i] = mp(a, b, c);
        can.push_back(make_pair(mp(a, false, b), i));
    }
    sort(can.begin(), can.end());
    For(i, 0, can.size()) {
        if (!can[i].first.second.first) {
            used.insert(make_pair(can[i].first.second.second, can[i].second));
        }
        else {
            int index = Find(can[i].first.second.second);
            if (index == -1) {
                cout << "NO" << endl;
                return 0;
            }
            else {
                ans[can[i].second] = index;
            }
        }
    }
    cout << "YES" << endl;
    For(i, 0, n) {
        printf("%d ", ans[i] + 1);
    }
    cout << endl;
}