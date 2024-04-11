#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 300005 * 2;

const int INF = 1000000000 + 1;
long long costs[N], costt[N], choose[N];

int minst[N], maxst[N], minp[N], maxp[N];

int n, w;

int use[N];

int main() {
    scanf("%d%d", &n, &w);
    vector<pair<int, int> > s;
    vector<pair<pair<int, int>, int> > t;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b - a >= a) {
            s.push_back(make_pair(a, i));
            s.push_back(make_pair(b - a, i));
        } else {
            t.push_back(make_pair(make_pair(b, a), i));
        }
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < (int)s.size(); ++i) {
        costs[i + 1] = costs[i] + s[i].first;
    }
    for (int i = 0; i < (int)t.size(); ++i) {
        costt[2 * (i + 1)] = costt[2 * i] + t[i].first.first;
    }
    int l = (int)t.size();
    minst[l] = INF;
    minp[l] = l;
    for (int i = l - 1; i >= 0; --i) {
        minst[i] = minst[i + 1], minp[i] = minp[i + 1];
        if (t[i].first.second < minst[i]) {
            minst[i] = t[i].first.second;
            minp[i] = i;
        }
    }
    maxst[0] = 0;
    maxp[0] = -1;
    for (int i = 0; i < l; ++i) {
        maxst[i + 1] = maxst[i], maxp[i + 1] = maxp[i];
        if (t[i].first.first - t[i].first.second > maxst[i + 1]) {
            maxst[i + 1] = t[i].first.first - t[i].first.second;
            maxp[i + 1] = i;
        }
    }
    for (int i = 0; i < (int)t.size(); ++i) {
        costt[i * 2 + 1] = costt[2 * i] + minst[i];
        choose[i * 2 + 1] = 0;
        if (costt[2 * (i + 1)] - maxst[i + 1] < costt[i * 2 + 1]) {
            costt[i * 2 + 1] = costt[2 * (i + 1)] - maxst[i + 1];
            choose[i * 2 + 1] = 1;
        }
    }
    long long ans = 1ll << 60;
    int anst = -1;
    for (int i = 0; i <= (int)s.size(); ++i) {
        if (i + 2 * l >= w && i <= w) {
            long long cost = costs[i] + costt[w - i];
            if (cost < ans) {
                ans = cost;
                anst = i;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < anst; ++i) {
        ++use[s[i].second];
    }
    int r = w - anst;
    if (r % 2 == 0) {
        for (int i = 0; i < r / 2; ++i) {
            use[t[i].second] = 2;
        }
    } else {
        if (choose[r] == 0) {
            for (int i = 0; i < r / 2; ++i) {
                use[t[i].second] = 2;
            }
            ++use[t[minp[r / 2]].second];
        } else {
            for (int i = 0; i < r / 2 + 1; ++i) {
                use[t[i].second] = 2;
            }
            --use[t[maxp[r / 2 + 1]].second];
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", use[i]);
    }
    printf("\n");
    return 0;
}