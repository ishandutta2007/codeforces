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

set<string> used;
const int N = 1010;
int n;
string a[N][2];
string ans[N];
map<string, vector<int>> b;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, p;
        cin >> s >> p;
        a[i][0] = s.substr(0, 3);
        a[i][1] = p.substr(0, 1);
        b[a[i][0]].push_back(i);
        ans[i] = a[i][0];
    }

    while(true)
    {
        vector<string> solved;
        for (auto it : b)
        {
            if (it.second.size() > 1 || used.count(it.first) > 0)
            {
                solved.push_back(it.first);
                for (int v : it.second)
                {
                    string s = a[v][0].substr(0, 2) + a[v][1];
                    ans[v] = s;
                    if (used.count(s) > 0)
                    {
                        cout << "NO\n";
                        return 0;
                    }
                    used.insert(s);
                }
            }
        }
        if (solved.empty()) break;
        for (string s : solved)
            b.erase(s);
    }

    used.clear();
    for (int i = 0; i < n; i++)
    {
        if (used.count(ans[i]) > 0)
        {
            cout << "NO\n";
            return 0;
        }
        used.insert(ans[i]);
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";

    return 0;
}