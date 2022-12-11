#include <bits/stdc++.h>
using namespace std;

vector<int> st, elv;

int n, m, cl, ce, v;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>cl>>ce>>v;
    st.resize(cl); elv.resize(ce);
    for (int i = 0; i < cl; i++)
    {
        cin>>st[i];
    }
    for (int i = 0; i < ce; i++)
    {
        cin>>elv[i];
    }

    sort(st.begin(),st.end());
    sort(elv.begin(),elv.end());

    int q;
    cin >> q;
    while (q--)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = 1e9;

        if (x1 == x2) { cout << abs(y1 - y2) << '\n'; continue; }

        int idx = lower_bound(st.begin(), st.end(), y1) - st.begin();

        if (idx < st.size()) ans = min(ans, abs(st[idx] - y1) + abs(st[idx] - y2) + abs(x1 - x2));
        if (idx) --idx, ans = min(ans, abs(st[idx] - y1) + abs(st[idx] - y2) + abs(x1 - x2));

        idx = lower_bound(st.begin(), st.end(), y2) - st.begin();

        if (idx < st.size()) ans = min(ans, abs(st[idx] - y1) + abs(st[idx] - y2) + abs(x1 - x2));
        if (idx) --idx, ans = min(ans, abs(st[idx] - y1) + abs(st[idx] - y2) + abs(x1 - x2));

        idx = lower_bound(elv.begin(), elv.end(), y1) - elv.begin();

        if (idx < elv.size()) ans = min(ans, abs(elv[idx] - y1) + abs(elv[idx] - y2) + (abs(x1 - x2) + v - 1) / v);
        if (idx) --idx, ans = min(ans, abs(elv[idx] - y1) + abs(elv[idx] - y2) + (abs(x1 - x2) + v - 1) / v);

        idx = lower_bound(elv.begin(), elv.end(), y2) - elv.begin();

        if (idx < elv.size()) ans = min(ans, abs(elv[idx] - y1) + abs(elv[idx] - y2) + (abs(x1 - x2) + v - 1) / v);
        if (idx) --idx, ans = min(ans, abs(elv[idx] - y1) + abs(elv[idx] - y2) + (abs(x1 - x2) + v - 1) / v);

        cout << ans << '\n';
    }
}