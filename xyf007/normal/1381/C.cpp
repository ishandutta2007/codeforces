#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
int t, n, x, y, a[100001], b[100001];
bool f[100001];
vector<int> pos[100002], cnt[100001];
int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--)
    {
        cin >> n >> x >> y;
        memset(f, false, 4 * (n + 2));
        memset(b, 0, 4 * (n + 2));
        for (int i = 0; i <= n + 1; i++)
        {
            pos[i].clear();
            cnt[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pos[a[i]].emplace_back(i);
        }
        for (int i = 1; i <= n + 1; i++)
        {
            cnt[pos[i].size()].emplace_back(i);
        }
        int maxx = n;
        for (int i = 1; i <= x; i++)
        {
            while (cnt[maxx].empty())
            {
                maxx--;
            }
            int c = cnt[maxx].back();
            b[pos[c].back()] = c;
            pos[c].pop_back();
            cnt[maxx].pop_back();
            cnt[maxx - 1].emplace_back(c);
        }
        while (maxx > 0 && cnt[maxx].empty())
        {
            maxx--;
        }
        if (2 * maxx > 2 * n - x - y)
        {
            cout << "NO\n";
            continue;
        }
        vector<int> tmp;
        for (int i = 1; i <= maxx; i++)
        {
            for (auto &&j : cnt[i])
            {
                tmp.insert(tmp.end(), pos[j].begin(), pos[j].end());
            }
        }
        int z = n - y, unused = cnt[0].at(0);
        for (int i = 0; i < n - x; i++)
        {
            b[tmp.at(i)] = a[tmp.at((i + ((n - x) >> 1)) % (n - x))];
            if (a[tmp.at(i)] == b[tmp.at(i)])
            {
                z--;
                b[tmp.at(i)] = unused;
                f[tmp.at(i)] = true;
            }
        }
        for (int i = 0; z > 0; i++)
        {
            if (!f[tmp.at(i)])
            {
                z--;
                b[tmp.at(i)] = unused;
                f[tmp.at(i)] = true;
            }
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}