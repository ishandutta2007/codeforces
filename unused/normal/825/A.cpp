#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    string s;
    cin >> n >> s;
    if (s.back() == '0') s.push_back('0');

    for (int i = 0; i < s.size();)
    {
        int j = i;
        while (j < s.size() && s[j] == '1') ++j;
        printf("%d", j - i);
        i = j + 1;
    }
    printf("\n");
}