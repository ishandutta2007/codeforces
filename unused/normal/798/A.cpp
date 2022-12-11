#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);

    string str;
    cin >> str;

    int diff = 0;

    for (int i = 0; i < str.size(); i++)
    {
        diff += str[i] != str[str.size() - 1 - i];
    }

    if (diff == 2 || (diff == 0 && str.size() % 2 == 1)) printf("YES\n");
    else printf("NO\n");
}