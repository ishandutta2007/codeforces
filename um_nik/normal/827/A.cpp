#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = (int)2e6 + 10;
vector<int> a[N];
vector<int> pos[N];
string ans;
int n;
string s[N];
int m;
vector<int> cur;
int cnt[N];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    m = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        int len = s[i].length();
        int k;
        cin >> k;
        while(k--) {
            int p;
            cin >> p;
            p--;
            m = max(m, p + len);
            a[p].push_back(i);
            a[p + len].push_back(-i);
            pos[i].push_back(p);
        }
    }
    ans.resize(m);
    for (int i = 0; i < m; i++) {
        for (int x : a[i]) {
            if (x > 0) {
                cur.push_back(x);
                cnt[x]++;
            } else {
                cnt[-x]--;
            }
        }
        while(!cur.empty() && cnt[cur.back()] == 0) cur.pop_back();
        if (cur.empty())
            ans[i] = 'a';
        else {
            int id = cur.back();
            auto it = upper_bound(pos[id].begin(), pos[id].end(), i);
            it--;
            int p = *it;
            if (i - p >= (int)s[id].length()) throw;
            ans[i] = s[id][i - p];
        }
    }
    cout << ans << endl;

    return 0;
}