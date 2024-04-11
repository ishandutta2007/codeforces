#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// x, x * w, x * w^2... 
vector<ll> fill_min(ll nodes, ll width, ll x) {
    vector<ll> d = {min(nodes, x)};
    nodes -= min(nodes, x);

    while (nodes > 0) {
        d.push_back(min(nodes, d.back() * width));
        nodes -= min(nodes, d.back());
    }

    return d;
}

// nodeswidth-ary tree
ll minscore(ll nodes, ll width) {
    vector<ll> d = fill_min(nodes, width, 1);
    ll score = 0;
    for (int i = 0; i < d.size(); ++i) {
        score += d[i] * (i + 1);
    }

    return score;
}

vector<ll> rec(ll nodes, ll score, ll depth, ll maxx, ll width) {
    if (nodes == 0) {
        if (score != 0) terminate();
        return vector<ll>();
    }

    ll ok = min(nodes, maxx), ng = 0;
    // depthokscore

    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        vector<ll> d = fill_min(nodes, width, mid);

        ll s = 0;
        for (int i = 0; i < d.size(); ++i) {
            s += d[i] * (depth + i);
        }

        if (s <= score) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    vector<ll> ret = rec(nodes - ok, score - depth * ok, depth + 1, ok * width, width);
    ret.push_back(ok);
    return ret;
}


int main() {
    ll N, S;
    cin >> N >> S;

    if (S < N * 2 - 1 || N * (N + 1) / 2 < S) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    ll ok = N, ng = 0;
    // ok-ary treeS
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        if (minscore(N, mid) <= S) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    vector<ll> ans = rec(N, S, 1, 1, ok);
    reverse(ans.begin(), ans.end());

    int par = 1;
    for (int i = 1; i < ans.size(); ++i) {
        int cnum = 0, step = 0;

        for (int j = 0; j < ans[i]; ++j) {
            cout << par + step << " ";
            ++cnum;
            if (cnum == ok) {
                ++step;
                cnum = 0;
            }
        }

        par += ans[i - 1];
    }
    cout << endl;
    return 0;
}