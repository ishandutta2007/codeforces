#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int ans[N];
int m[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        ans[i] = 1e9 + 100;
    for(int i = 0; i < 10; i++)
    {
        vector<int> v1, v2;
        for(int j = 1; j <= n; j++)
        {
            if(j & (1 << i)) v1.push_back(j);
            else v2.push_back(j);
        }
        for(int j = 0; j < 2; j++)
        {
            if(!v1.empty() && !v2.empty())
            {
                printf("%d\n", v1.size());
                fflush(stdout);
                for(int x: v1)
                    printf("%d ", x);
                puts("");
                fflush(stdout);
                for(int k = 1; k <= n; k++)
                    scanf("%d", m + k);
                for(int x: v2)
                {
                    //printf("%d %d\n", x, m[x]);
                    ans[x] = min(ans[x], m[x]);
                }
            }
            swap(v1, v2);
        }
    }
    puts("-1");
    fflush(stdout);
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    puts("");
    fflush(stdout);
}