#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int n, m;
map<int, int> s;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        s[x]++;
        if (s.size() == n)
        {
            printf("1");
            for (map<int, int>::iterator it = s.begin(); it != s.end();)
            {
                if (it->second == 1)
                {
                    s.erase(it++);
                }
                else
                {
                    it->second--;
                    it++;
                }
            }
        }
        else
        {
            printf("0");
        }
    }
    return 0;
}