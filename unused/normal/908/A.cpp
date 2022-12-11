#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int ans = 0;
    for (int t : str)
    {
        if (t >= '0' && t <= '9' && t % 2 == 1) ++ans;
        if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u') ++ans;
    }
    cout << ans;
}