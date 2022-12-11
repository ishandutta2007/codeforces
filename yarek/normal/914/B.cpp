#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a;
        scanf("%d", &a);
        m[a]++;
    }
    for(auto p: m)
        if(p.second % 2)
        {
            puts("Conan");
            return 0;
        }
    puts("Agasa");
}