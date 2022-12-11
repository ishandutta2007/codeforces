#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> odd;
    int evensum = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] & 1) odd.push_back(a[i]);
        else if (a[i] > 0) evensum += a[i];
    }

    sort(odd.begin(), odd.end());
    int oddsum = odd.back();

    for (int i = (int)odd.size() - 3; i >= 0; i -= 2)
    {
        int res = odd[i] + odd[i + 1];
        if (res < 0) break;
        oddsum += res;
    }

    cout << oddsum + evensum << endl;
}