#include <bits/stdc++.h>
using namespace std;

const char *z = "heidi";

int main()
{
    string str;
    cin >> str;
    int p = 0;
    for (char ch : str) if (z[p] == ch) ++p;
    cout << (p == 5 ? "YES" : "NO");
}