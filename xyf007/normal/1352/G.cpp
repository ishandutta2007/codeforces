#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
int t, n;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        if (n < 4)
        {
            printf("-1\n");
            continue;
        }
        deque<int> q;
        q.push_back(2);
        q.push_back(4);
        q.push_back(1);
        q.push_back(3);
        for (int i = 5; i <= n; i++)
        {
            if (i & 1)
            {
                q.push_back(i);
            }
            else
            {
                q.push_front(i);
            }
        }
        for (deque<int>::iterator it = q.begin(); it != q.end(); it++)
        {
            printf("%d ", *it);
        }
        printf("\n");
    }
    return 0;
}