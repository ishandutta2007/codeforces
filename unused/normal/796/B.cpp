#include <bits/stdc++.h>
using namespace std;

bool h[1000005];

int main()
{
    cin.sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) { int t; cin >> t; h[t] = true; }
    int bone = 1;
    for (int i = 0; i < k && !h[bone]; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == bone) bone = b;
        else if (b == bone) bone = a;
    }
    cout << bone << '\n';
}