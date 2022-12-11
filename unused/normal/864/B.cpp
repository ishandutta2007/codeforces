#include <bits/stdc++.h>
using namespace std;
int z[105];

int main()
{
    string str;
    cin >> str;
    cin >> str;
    int ans = 0;
    for (char *p = strtok(&str[0], "ABCDEFGHIJKLMNOPQRSTUVWXYZ"); p;
               p = strtok(nullptr, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"))
    {
        ans = max(ans, (int)set<char>(p, p + strlen(p)).size());
    }
    printf("%d\n", ans);
}