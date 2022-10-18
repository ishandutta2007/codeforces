#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const long long oo = (long long)1e18 + 7;

typedef long long ll;

ll query1(int i, int j, int k) {
    printf("1 %d %d %d\n", i, j, k);
    fflush(stdout);
    long long res;
    scanf("%lld", &res);
    return res;
}

int query2(int i, int j, int k) {
    printf("2 %d %d %d\n", i, j, k);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

vector<int> askSub(vector<pair<ll, int>> p, int l, int r) {
    vector<int> res;
    if (p.empty())
        return res;

    int mid = 0;
    for(int i = 1; i < p.size(); ++i)
        if (p[mid].first < p[i].first)
            mid = i;

    int midID = p[mid].second;
    
    vector<pair<ll, int>> _left;
    vector<pair<ll, int>> _right;

    for(int i = 0; i < p.size(); ++i) {
        if (i == mid)
            continue;
        int sign = query2(l, midID, p[i].second);
        if (sign == 1)
            _left.push_back(p[i]);
        else
            _right.push_back(p[i]);
    }

    sort(_left.begin(), _left.end());
    sort(_right.begin(), _right.end());
    reverse(_right.begin(), _right.end());
    
    vector<int> ans;
    for(auto e: _left)
        ans.push_back(e.second);
    ans.push_back(midID);
    for(auto e: _right)
        ans.push_back(e.second);

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<ll, int>> upper, lower;
    for(int i = 3; i <= n; ++i) {
        long long area = query1(1, 2, i);
        int sign = query2(1, 2, i);
        if (sign == 1)
            upper.push_back({area, i});
        else
            lower.push_back({area, i});
    }

    vector<int> sortedUpper = askSub(upper, 1, 2);
    vector<int> sortedLower = askSub(lower, 2, 1);

    vector<int> ans;
    ans.push_back(1);    
    for(int id: sortedUpper)
        ans.push_back(id);
    ans.push_back(2);
    for(int id: sortedLower)
        ans.push_back(id);

    if (query2(ans[0], ans[1], ans[2]) == -1)
        reverse(ans.begin(), ans.end());

    while (ans[0] != 1) {
        int x = ans[0];
        ans.erase(ans.begin());
        ans.push_back(x);
    }

    printf("0");
    for(int id: ans)
        printf(" %d", id);
    puts("");
    fflush(stdout);

    return 0;
}