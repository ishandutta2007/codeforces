#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int a; scanf("%d",&a); mp[-a]++;
    }

    for (auto &e : mp)
    {
        if (e.second & 1)
        {
            printf("Conan\n");
            return 0;
        }
    }

    printf("Agasa\n");
}