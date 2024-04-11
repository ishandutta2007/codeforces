#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    --k;

    for (int i = 2; i <= n && k; i++)
    {
        while (n % i == 0 && k)
        {
            n /= i;
            ans.push_back(i);
            --k;
        }
    }

    if (n == 1 || k)
    {
        cout << -1 << endl;
        return 0;
    }
    ans.push_back(n);

    for (int t : ans) cout << t << ' ';
    cout << '\n';
}