#include <bits/stdc++.h>
using namespace std;

bool lower(int a, int b)
{
    printf("? %d %d\n", a, b);
    fflush(stdout);
    char c;
    scanf(" %c", &c);
    return c == '<';
}

int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        int n;
        scanf("%d", &n);
        if(n == 1)
        {
            printf("! 1 1\n");
            fflush(stdout);
            continue;
        }
        vector<int> low, high;
        for(int i = 2; i <= n; i += 2)
        {
            if(lower(i-1, i))
            {
                low.push_back(i-1);
                high.push_back(i);
            }
            else
            {
                low.push_back(i);
                high.push_back(i-1);
            }
        }
        if(n % 2)
        {
            low.push_back(n);
            high.push_back(n);
        }
        int min = low[0];
        for(int i = 1; i < low.size(); i++)
            if(lower(low[i], min))
                min = low[i];
        int max = high[0];
        for(int i = 1; i < high.size(); i++)
            if(lower(max, high[i]))
                max = high[i];
        printf("! %d %d\n", min, max);
        fflush(stdout);
    }
}