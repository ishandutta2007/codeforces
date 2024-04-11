#include <bits/stdc++.h>
using namespace std;

int n;

vector<string> transform(vector<string> vec, int qx, int qy, bool flip)
{
    vector<string> ans(n, string(n, ' '));
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
        {
            int dx = x * qx, dy = y * qy;
            if(qx < 0) dx += n - 1;
            if(qy < 0) dy += n - 1;
            if(flip) swap(dx, dy);
            ans[dx][dy] = vec[x][y];
        }
    return ans;
}

vector<string> read()
{
    vector<string> ans(n);
    for(auto &x: ans)
        cin >> x;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    auto m1 = read(), m2 = read();
    for(int qx: { -1, 1 })
        for(int qy: { -1, 1 })
            for(bool flip: { false, true })
            {
                auto t = transform(m2, qx, qy, flip);
                if(m1 == t)
                {
                    cout << "Yes\n";
                    return 0;
                }
            }
    cout << "No\n";
}