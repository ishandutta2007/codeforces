#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
int n;
std::string s;
std::vector<int> v;
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1] && s[i] != '?')
        {
            printf("No");
            return 0;
        }
        if (s[i] == '?')
        {
            v.push_back(i);
            sum++;
        }
    }
    if (v.empty())
    {
        printf("No");
        return 0;
    }
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        int pos = *it;
        if (pos == 0 || pos == n - 1 || s[pos - 1] == s[pos + 1] || s[pos - 1] == '?' || s[pos + 1] == '?')
        {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}